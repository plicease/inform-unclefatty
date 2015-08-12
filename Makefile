VER=5
STORY=fatty.z$(VER)


MAKE_GAMETXT=-r
#INFORM=./ic
INFORM=inform
INFORMFLAGS=+lib $(MAKE_GAMETXT) -D -v$(VER) 
#PERL=c:/lang/perl/bin/perl
PERL=perl
ZIP=zip

RM=rm -f

all:$(STORY)

fatty:fatty.z($VER)
	cp fatty.z$(VER) fatty

fatty.z8 fatty.z5:fatty.if lib/special.ifl
	$(INFORM) $(INFORMFLAGS) $(LOWERFLAGS) fatty.if

lib/special.ifl:special.txt special.pl
	$(PERL) special.pl

clean:
	$(RM) fatty.z? fatty gametext.txt lib/special.ifl *.sig *.asc *.zip

wc:
	wc -l fatty.if

dist: fatty.z$(VER)
	zip fatty.zip fatty.z$(VER)
