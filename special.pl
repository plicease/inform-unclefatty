#!/usr/bin/perl -w

use POSIX;

open(S1, 'special.txt') || die "unable to open special.txt $!";
open(OUT, '>lib/special.ifl') || die "unable to write to lib/special.if $!";

@list = <S1>;
chomp(@list); @list = sort(@list);
$max = @list;
$max = POSIX::ceil($max/3);


@s1 = splice(@list, 0, $max);
@s2 = splice(@list, 0, $max);
@s3 = splice(@list, 0, $max);

print OUT "Global specialist = \"i would like to thank the following\n";
print OUT "people for lending me their perspectives over the years:^";
for($i=0; $i<$max; $i++) {
	printf(OUT "\n^%-25s %-25s %s", f($s1[$i]), f($s2[$i]), f($s3[$i]));
}
print OUT "\";";

sub f {
	my $x = shift || '';
	if($x =~ /^(.*?)\s*,\s*(.*?)$/) {
		return "$2 $1";
	} else {
		return $x;
	}
}
