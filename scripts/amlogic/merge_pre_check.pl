#!/usr/bin/perl -W
# SPDX-License-Identifier: (GPL-2.0+ OR MIT)
#
# Copyright (c) 2019 Amlogic, Inc. All rights reserved.
#
my $top = ".";
my $err_cnt = 0;
my $k_v = 4;
my $exit = 0;
my $git_format_link="http://wiki-china.amlogic.com/Platform/Bootloader/Bootloader_commit_message_format";
my $config1 = "arch/arm64/configs/meson64_a64_defconfig";
my $config2 = "arch/arm/configs/meson64_a32_defconfig";
my $config3 = "arch/arm64/configs/meson64_a64_P_defconfig";
my $config4 = "arch/arm64/configs/meson64_a64_R_defconfig";
my $skip = 0;
my $make_clang="make ARCH=arm64 CC=clang HOSTCC=clang LD=ld.lld NM=llvm-nm OBJCOPY=llvm-objcopy CLANG_TRIPLE=aarch64-linux-gnu- CROSS_COMPILE=aarch64-linux-gnu- -j12";
my $make_defconfig_link = "https://wiki-china.amlogic.com/Platform/Kernel/Kernel5.4/Build";
my $env_common = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin";
my $arm64_dts = "arch/arm64/boot/dts/amlogic/";

#Check mesonxx_defconfig
sub check_defconfig
{
	my $err = 0;
	#print "2. Check meson_defconfig: ";
	if( -e $config1)
	{
		`make ARCH=arm64 meson64_a64_defconfig  1> /dev/null 2>&1`;
		`make ARCH=arm64 savedefconfig 1> /dev/null 2>&1`;
		`rm -fr .config`;
		my $diff = `diff defconfig ./arch/arm64/configs/meson64_a64_defconfig`;
		if(length($diff))
		{
			$err_cnt += 1;
			$err = 1;
			$err_msg .= "    $err_cnt: meson64_a64_defconfig not generated by savedefconfig\n";
		}
	}
	if( -e $config2)
	{
		`make ARCH=arm meson64_a32_defconfig  1> /dev/null 2>&1`;
		`make ARCH=arm savedefconfig  1> /dev/null 2>&1`;
		`rm -fr .config`;
		$diff = `diff defconfig ./arch/arm/configs/meson64_a32_defconfig`;
		if(length($diff))
		{
			$err_cnt += 1;
			$err = 1;
			$err_msg .= "    $err_cnt: meson64_a32_defconfig not generated by savedefconfig\n";
		}
	}

	$ENV{PATH}="/opt/clang-r377782b/bin/:/opt/gcc-linaro-6.3.1-2017.02-x86_64_aarch64-linux-gnu/bin/:$env_common";
	if( -e $config3)
	{
		`$make_clang meson64_a64_P_defconfig  1> /dev/null 2>&1`;
		`$make_clang savedefconfig 1> /dev/null 2>&1`;
		`rm -fr .config`;
		my $diff = `diff defconfig ./arch/arm64/configs/meson64_a64_P_defconfig`;
		if(length($diff))
		{
			$err_cnt += 1;
			$err = 1;
			$err_msg .= "    $err_cnt: meson64_a64_P_defconfig not generated by savedefconfig\n";
		}
	}
	if( -e $config4)
	{
		`$make_clang meson64_a64_R_defconfig  1> /dev/null 2>&1`;
		`$make_clang savedefconfig 1> /dev/null 2>&1`;
		`rm -fr .config`;
		my $diff = `diff defconfig ./arch/arm64/configs/meson64_a64_R_defconfig`;
		if(length($diff))
		{
			$err_cnt += 1;
			$err = 1;
			$err_msg .= "    $err_cnt: meson64_a64_R_defconfig not generated by savedefconfig\n";
		}
	}
	$clang_path = `which clang`;
	delete $ENV{PATH};
	if($err)
	{
		$err_msg .= "    Please refer to:\n";
		$err_msg .= "            $make_defconfig_link \n";
	}
	#print $err ? "fail\n" : "success\n";
}

sub dts_check
{
	my $dts_diff = "";
	my $diff = `git diff HEAD^ --name-only | grep -E '*dts'`;
	my $all_dts = `find $arm64_dts -name "*dts"`;
	my @diff_str = split /[\n]/, $diff;
	my @all_dts_str = split /[\n]/, $all_dts;
	my $diff_count = 0;
	my $all_dts_count = 0;
	my $count = 0;
	for (@diff_str)
	{
		$re = $_;
		if ($re=~m/^(.*?)\_/)
		{
		$dts_diff = $1;
		$dts_diff = $dts_diff."_";
		}
		if (!($_ =~ "pxp.dts"))
		{
			for (@diff_str)
			{
				if ($_ =~ $dts_diff)
				{
					$diff_count=$diff_count+1;
				}
			}
			for (@all_dts_str)
			{
				if ($_ =~ $dts_diff)
				{
					$all_dts_count=$all_dts_count+1;
				}
			}
		}
		if ($diff_count != $all_dts_count)
		{
			$count=$count+1;
		}
		$diff_count=0;
		$all_dts_count=0;
	}
	if ($count != 0)
	{
		$err_cnt += 1;
		$err_msg .= "	$err_cnt: Solution:\n	please check dts the board is all changed? \n";
	}
}


# check module_param number
sub check_module_param
{
	my $num = `git format-patch -1 --stdout | grep -c "module_param("`;
	my $MAX_NUM = 5;

	if( $num > $MAX_NUM )
	{
		$err_cnt += 1;
		$err_msg .= "	$err_cnt: the number of module_param too much\n";
	}
}

my $MAX_LEN	=	80;

sub check_msg_common
{
	my $line = pop(@_);
	my $lnum = pop(@_);

	if( (length($line) > ($MAX_LEN + 4) ) && ($lnum > 4) )
	{	#Line over 80 characters is not allowed.
		$line =~ s/^(\s){4}//;
		$err_cnt += 1;
		$err_msg .= "    $err_cnt: Line over $MAX_LEN characters: <$line>\n";
	}

	if ( ($line =~ /\s+$/) && $line !~/^(\s){4}$/ )
	{ #No space at the end of line
		$err_cnt += 1;
		$line =~ s/^(\s){4}//;
		$err_msg .= "    $err_cnt: No space at the end of line: <$line>\n";
	}
}


sub check_msg_49_2
{
	my $msg = `git cat-file commit HEAD~0 | sed '1,/\^\$/d'`;
	my @str = split /[\n][\n]/, $msg;
	my $i = 0;
	my $len = @str;

	if( $msg =~ /^Revert\s/ )
	{
		return 0;
	}

	if( $len < 4 )
	{
		$err_cnt += 5;
		$err_msg .= "	module: message [n/m]\n\n";
		$err_msg .= "	PD#SWPL-XXXX\n\n";
		$err_msg .= "	Problem:\n	detailed description\n\n";
		$err_msg .= "	Solution:\n	detailed description\n\n";
		$err_msg .= "	Verify:\n	detailed description\n\n";
		return -1;
	}

	if( $msg !~ /Merge\s/ && $msg =~ /5\.4/ )
	{
		$err_cnt += 1;
		$err_msg .= "	$err_cnt: this branch is 5.4, all changes here are for 5.4. No「5.4」in commit message please\n";
	}

	if( $str[$i] !~ /^([\w-]+:\s){1,2}.+(\s)\[[\d]+\/[\d]+\]$/ )
	{
		$err_cnt += 1;
		$err_msg .= "	$err_cnt: module: message\n";
	}
	elsif( $str[$i] =~ /(kernel)/i )
	{
		$err_cnt += 1;
		$err_msg .= "	$err_cnt: Should be no 'kernel' in kernel commit message\n";
	}

	if( $str[++ $i] !~ /^PD\#SWPL-.+(\d)$/ )
	{
		$err_cnt += 1;
		$err_msg .= "	$err_cnt: PD#SWPL-XXXX\n";

	}

	if( $str[++ $i] !~ /^Problem:[\n].+/ )
	{
		$err_cnt += 1;
		$err_msg .= "	$err_cnt: Problem:\n	detailed description\n";
	}

	$i += 1;
	while( $str[$i] !~ /^Solution:[\n].+/ && $str[$i] !~ /^Change-Id:/ && $str[$i] !~ /^Verify:[\n].+/ && ($i + 1) < $len )
	{
		$i = $i + 1;
	}

	if( $str[$i] !~ /^Solution:[\n].+/ )
	{
		$err_cnt += 1;
		$err_msg .= "	$err_cnt: Solution:\n	detailed description\n";
	}

	if( $str[$i] =~ /^Change-Id:/ )
	{
		$err_cnt += 1;
		$err_msg .= "	$err_cnt: Verify:\n	detailed description\n";
		return -1;
	}

	while( $str[$i] !~ /^Verify:[\n].+/ && $str[$i] !~ /^Change-Id:/ && ($i + 1) < $len )
	{
		$i += 1;
	}

	if( $str[$i] !~ /^Verify:[\n].+/ )
	{
		$err_cnt += 1;
		$err_msg .= "	$err_cnt: Verify:\n	detailed description\n";
	}
}

sub sync_arm64_arm_diff
{
	my $file = `git diff --name-only HEAD HEAD^`;
	my $arm_dts_num = () = ($file =~ /arch\/arm\/boot\/dts\/amlogic/g);
	my $arm64_dts_num = () = ($file =~ /arch\/arm64\/boot\/dts\/amlogic/g);
	my $arm_config_num = () = ($file =~ /arch\/arm\/config/g);
	my $arm64_config_num = () = ($file =~ /arch\/arm64\/config/g);

	if( $arm_config_num != $arm64_config_num )
	{
		$err_cnt += 1;
		$err_msg .= "	$err_cnt: maybe should modify the config in both arm and arm64\n";
	}
	if( $arm_dts_num != $arm64_dts_num )
	{
		$err_cnt += 1;
		$err_msg .= "	$err_cnt: maybe should modify the dts in both arm and arm64\n";
	}
}

sub check_nonascii_character
{
	my $add_msg = `git format-patch -1 --stdout`;
	my @add_str = split /[\n]/, $add_msg;
	my $i = 0;
	my $len = @add_str;

	for ($i = 0; $i < $len; $i = $i + 1)
	{
		if ($add_str[$i] =~ m/[^\x00-\x7f]/)
		{
			$err_cnt += 1;
			$err_msg  .= "	$add_str[$i]\n";
		}
	}
}


sub check_commit_msg
{

	my $lnum = 0;
	my $err = 0;
	my $result = 0;
	my $commit;
	my $FILE;

	open($FILE, '<&STDIN');

	while (<$FILE>) {
		chomp;
		my $line = $_;


		if( $line =~ /^commit\s([0-9a-z])+$/)
		{
			$lnum = 0;
			$commit = $line;
			$skip = 0;
		}
		$lnum ++;


		if( ($lnum ==2) && ($line =~ /^Merge: /))
		{
			#$skip =1;			#Don't Check branch merge
		}
		if( ($lnum==2) && ($line !~ /^Author: .*\@amlogic\.com\>$/))
		{
			#$skip =1;			#Don't Check commit which is not from amlogic
		}

		if( $err == 1)
		{
			$skip = 1;
			$err = 0;
			$result = 1;
		}
		if( $skip ==1)
		{
			next;
		}

		check_msg_common($lnum, $line);
	}
	close $FILE;
	if ($k_v >= 4)
	{
		check_msg_49_2;
	}
}

sub out_review
{
	my $out_msg = "";
	my $out_file = "../output/review.txt";

	if ($err_cnt)
	{
		$out_msg = <<END;
\$ git log -1 | ./scripts/amlogic/merge_pre_check.pl -; total $err_cnt errors.
${err_msg}

END

		#open O, "> $out_file" or die "Can't Open $out_file For Write \n";
		#print O $out_msg;
		#close O;
		$exit = 1;
		print $out_msg;
		print "Please refer to:\n	$git_format_link\n";
	}
	else
	{
		print "";
	}
}

#start

my $err_msg_p = "\nCommit Pre check failed. Total $err_cnt errors.\n";


#Check meson_defconfig
check_defconfig();
dts_check();

#check_module_param
check_module_param();

#Check commit message
check_commit_msg();

#check config and dts in arm and arm64
#sync_arm64_arm_diff();
check_nonascii_character();

out_review();
#out
exit $exit;