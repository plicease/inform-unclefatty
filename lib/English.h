! modified by richard ess for uncle fatty
! ===========================================================================
!   Inform Language Definition File: English 981213
!
!   (c) Graham Nelson 1997, 1998
!
!   Define the constant DIALECT_US before including "Parser" to
!   obtain American English
! ---------------------------------------------------------------------------
System_file;
! ---------------------------------------------------------------------------
!   Part I.   Preliminaries
! ---------------------------------------------------------------------------
Constant EnglishNaturalLanguage;   ! Needed to keep old pronouns mechanism

Class  CompassDirection
  with article "the", number 0
  has  scenery;
Object Compass "compass" has concealed;
IFNDEF WITHOUT_DIRECTIONS;
CompassDirection -> n_obj "north wall"
                    with name 'n//' 'north' 'wall',    door_dir n_to;
CompassDirection -> s_obj "south wall"
                    with name 's//' 'south' 'wall',    door_dir s_to;
CompassDirection -> e_obj "east wall"
                    with name 'e//' 'east' 'wall',     door_dir e_to;
CompassDirection -> w_obj "west wall"
                    with name 'w//' 'west' 'wall',     door_dir w_to;
CompassDirection -> ne_obj "northeast wall"
                    with name 'ne' 'northeast' 'wall', door_dir ne_to;
CompassDirection -> nw_obj "northwest wall"
                    with name 'nw' 'northwest' 'wall', door_dir nw_to;
CompassDirection -> se_obj "southeast wall"
                    with name 'se' 'southeast' 'wall', door_dir se_to;
CompassDirection -> sw_obj "southwest wall"
                    with name 'sw' 'southwest' 'wall', door_dir sw_to;
CompassDirection -> u_obj "ceiling"
                    with name 'u//' 'up' 'ceiling',    door_dir u_to;
CompassDirection -> d_obj "floor"
                    with name 'd//' 'down' 'floor',    door_dir d_to;
ENDIF;
CompassDirection -> out_obj "outside"
                    with                               door_dir out_to;
CompassDirection -> in_obj "inside"
                    with                               door_dir in_to;
! ---------------------------------------------------------------------------
!   Part II.   Vocabulary
! ---------------------------------------------------------------------------
Constant AGAIN1__WD   = 'again';
Constant AGAIN2__WD   = 'g//';
Constant AGAIN3__WD   = 'again';
Constant OOPS1__WD    = 'oops';
Constant OOPS2__WD    = 'o//';
Constant OOPS3__WD    = 'oops';
Constant UNDO1__WD    = 'undo';
Constant UNDO2__WD    = 'undo';
Constant UNDO3__WD    = 'undo';

Constant ALL1__WD     = 'all';
Constant ALL2__WD     = 'each';
Constant ALL3__WD     = 'every';
Constant ALL4__WD     = 'everything';
Constant ALL5__WD     = 'both';
Constant AND1__WD     = 'and';
Constant AND2__WD     = 'and';
Constant AND3__WD     = 'and';
Constant BUT1__WD     = 'but';
Constant BUT2__WD     = 'except';
Constant BUT3__WD     = 'but';
Constant ME1__WD      = 'me';
Constant ME2__WD      = 'myself';
Constant ME3__WD      = 'self';
Constant OF1__WD      = 'of';
Constant OF2__WD      = 'of';
Constant OF3__WD      = 'of';
Constant OF4__WD      = 'of';
Constant OTHER1__WD   = 'another';
Constant OTHER2__WD   = 'other';
Constant OTHER3__WD   = 'other';
Constant THEN1__WD    = 'then';
Constant THEN2__WD    = 'then';
Constant THEN3__WD    = 'then';

Constant NO1__WD      = 'n//';
Constant NO2__WD      = 'no';
Constant NO3__WD      = 'no';
Constant YES1__WD     = 'y//';
Constant YES2__WD     = 'yes';
Constant YES3__WD     = 'yes';

Constant AMUSING__WD  = 'amusing';
Constant FULLSCORE1__WD = 'fullscore';
Constant FULLSCORE2__WD = 'full';
Constant QUIT1__WD    = 'q//';
Constant QUIT2__WD    = 'quit';
Constant RESTART__WD  = 'restart';
Constant RESTORE__WD  = 'restore';

Array LanguagePronouns table

   !  word       possible GNAs                   connected
   !             to follow:                      to:
   !             a     i
   !             s  p  s  p
   !             mfnmfnmfnmfn                 

      'it'     $$001000111000                    NULL
      'him'    $$100000000000                    NULL
      'her'    $$010000000000                    NULL
      'them'   $$000111000111                    NULL;

Array LanguageDescriptors table

   !  word       possible GNAs   descriptor      connected
   !             to follow:      type:           to:
   !             a     i
   !             s  p  s  p
   !             mfnmfnmfnmfn                 

      'my'     $$111111111111    POSSESS_PK      0
      'this'   $$111111111111    POSSESS_PK      0
      'these'  $$000111000111    POSSESS_PK      0
      'that'   $$111111111111    POSSESS_PK      1
      'those'  $$000111000111    POSSESS_PK      1
      'his'    $$111111111111    POSSESS_PK      'him'
      'her'    $$111111111111    POSSESS_PK      'her'
      'their'  $$111111111111    POSSESS_PK      'them'
      'its'    $$111111111111    POSSESS_PK      'it'
      'the'    $$111111111111    DEFART_PK       NULL
      'a//'    $$111000111000    INDEFART_PK     NULL
      'an'     $$111000111000    INDEFART_PK     NULL
      'some'   $$000111000111    INDEFART_PK     NULL
      'lit'    $$111111111111    light           NULL
     'lighted' $$111111111111    light           NULL
      'unlit'  $$111111111111    (-light)        NULL;

Array LanguageNumbers table
    'one' 1 'two' 2 'three' 3 'four' 4 'five' 5
    'six' 6 'seven' 7 'eight' 8 'nine' 9 'ten' 10
    'eleven' 11 'twelve' 12 'thirteen' 13 'fourteen' 14 'fifteen' 15
    'sixteen' 16 'seventeen' 17 'eighteen' 18 'nineteen' 19 'twenty' 20;

! ---------------------------------------------------------------------------
!   Part III.   Translation
! ---------------------------------------------------------------------------

[ LanguageToInformese;
];

! ---------------------------------------------------------------------------
!   Part IV.   Printing
! ---------------------------------------------------------------------------

Constant LanguageAnimateGender   = male;
Constant LanguageInanimateGender = neuter;

Constant LanguageContractionForms = 2;     ! English has two:
                                           ! 0 = starting with a consonant
                                           ! 1 = starting with a vowel

[ LanguageContraction text;
  if (text->0 == 'a' or 'e' or 'i' or 'o' or 'u'
                 or 'A' or 'E' or 'I' or 'O' or 'U') return 1;
  return 0;
];

Array LanguageArticles -->

 !   Contraction form 0:     Contraction form 1:
 !   Cdef   Def    Indef     Cdef   Def    Indef

     "the " "the " "a "      "the " "the " "an "          ! Articles 0
     "the " "the " "some "   "the " "the " "some ";       ! Articles 1

                   !             a           i
                   !             s     p     s     p
                   !             m f n m f n m f n m f n                 

Array LanguageGNAsToArticles --> 0 0 0 1 1 1 0 0 0 1 1 1;

[ LanguageDirection d;
   switch(d)
   {   n_to: print "north";
       s_to: print "south";
       e_to: print "east";
       w_to: print "west";
       ne_to: print "northeast";
       nw_to: print "northwest";
       se_to: print "southeast";
       sw_to: print "southwest";
       u_to: print "up";
       d_to: print "down";
       in_to: print "in";
       out_to: print "out";
       default: return RunTimeError(9,d);
   }
];

[ LanguageNumber n f;
  if (n==0)    { print "zero"; rfalse; }
  if (n<0)     { print "minus "; n=-n; }
  if (n>=1000) { print (LanguageNumber) n/1000, " thousand"; n=n%1000; f=1; }
  if (n>=100)  { if (f==1) print ", ";
                 print (LanguageNumber) n/100, " hundred"; n=n%100; f=1; }
  if (n==0) rfalse;
  #ifndef DIALECT_US;
  if (f==1) print " and ";
  #ifnot;
  if (f==1) print " ";
  #endif;
  switch(n)
  {   1:  print "one";
      2:  print "two";
      3:  print "three";
      4:  print "four";
      5:  print "five";
      6:  print "six";
      7:  print "seven";
      8:  print "eight";
      9:  print "nine";
      10: print "ten";
      11: print "eleven";
      12: print "twelve";
      13: print "thirteen";
      14: print "fourteen";
      15: print "fifteen";
      16: print "sixteen";
      17: print "seventeen";
      18: print "eighteen";
      19: print "nineteen";
      20 to 99:
          switch(n/10)
          {  2: print "twenty";
             3: print "thirty";
             4: print "forty";
             5: print "fifty";
             6: print "sixty";
             7: print "seventy";
             8: print "eighty";
             9: print "ninety";
          }
          if (n%10 ~= 0) print "-", (LanguageNumber) n%10;
  }
];

[ LanguageTimeOfDay hours mins i;
   i=hours%12;
   if (i==0) i=12;
   if (i<10) print " ";
   print i, ":", mins/10, mins%10;
   if ((hours/12) > 0) print " pm"; else print " am";
];

[ LanguageVerb i;
   if (i==#n$l)        { print "look";              rtrue; }
   if (i==#n$z)        { print "wait";              rtrue; }
   if (i==#n$x)        { print "examine";           rtrue; }
   if (i==#n$i or 'inv' or 'inventory')
                       { print "inventory";         rtrue; }
   rfalse;
];

Constant NKEY__TX     = "n = next subject";
Constant PKEY__TX     = "p = previous";
Constant QKEY1__TX    = "  q = resume game";
Constant QKEY2__TX    = "q = previous menu";
Constant RKEY__TX     = "return = read subject";

Constant NKEY1__KY    = 'N';
Constant NKEY2__KY    = 'n';
Constant PKEY1__KY    = 'P';
Constant PKEY2__KY    = 'p';
Constant QKEY1__KY    = 'Q';
Constant QKEY2__KY    = 'q';

Constant SCORE__TX    = "score: ";
Constant MOVES__TX    = "moves: ";
Constant TIME__TX     = "time: ";
Constant CANTGO__TX   = "you can't go that way.";
Constant FORMER__TX   = "your former self";
Constant YOURSELF__TX = "yourself";
Constant DARKNESS__TX = "darkness";

Constant THOSET__TX   = "those things";
Constant THAT__TX     = "that";
Constant OR__TX       = " or ";
Constant NOTHING__TX  = "nothing";
Constant IS__TX       = " is";
Constant ARE__TX      = " are";
Constant IS2__TX      = "is ";
Constant ARE2__TX     = "are ";
Constant AND__TX      = " and ";
Constant WHOM__TX     = "whom ";
Constant WHICH__TX    = "which ";

[ ThatorThose obj;   ! Used in the accusative
  if (obj == player) { print "you"; return; }
  if (obj has pluralname) { print "those"; return; }
  if (obj has animate)
  {   if (obj has female) { print "her"; return; }
      else if (obj hasnt neuter) { print "him"; return; }
  }
  print "that";
];
[ ItorThem obj;
  if (obj == player) { print "yourself"; return; }
  if (obj has pluralname) { print "them"; return; }
  if (obj has animate)
  {   if (obj has female) { print "her"; return; }
      else if (obj hasnt neuter) { print "him"; return; }
  }
  print "it";
];
[ IsorAre obj;
  if (obj has pluralname || obj == player) print "are"; else print "is";
];
[ CThatorThose obj;   ! Used in the nominative
  if (obj == player) { print "You"; return; }
  if (obj has pluralname) { print "Those"; return; }
  if (obj has animate)
  {   if (obj has female) { print "she"; return; }
      else if (obj hasnt neuter) { print "He"; return; }
  }
  print "That";
];
[ CTheyreorThats obj;
  if (obj == player) { print "you're"; return; }
  if (obj has pluralname) { print "they're"; return; }
  if (obj has animate)
  {   if (obj has female) { print "she's"; return; }
      else if (obj hasnt neuter) { print "he's"; return; }
  }
  print "That's";
];

[ LanguageLM n x1;
  Prompt:  print "^>";
  Miscellany:
           switch(n)
           {   1: "(considering the first sixteen objects only)^";
               2: "Nothing to do!";
               3: print " you have died ";
               4: print " you have won ";
               5: print "^would you like to restart, restore a saved game";
                  #IFDEF DEATH_MENTION_UNDO;
                  print ", undo your last move";
                  #ENDIF;
                  if (TASKS_PROVIDED==0)
                      print ", give the full score for that game";
                  if (deadflag==2 && AMUSING_PROVIDED==0)
                      print ", see some suggestions for amusing things to do";
                  " or quit?";
               6: "[your interpreter does not provide ~undo~.  sorry!]";
               7: "~undo~ failed.  [not all interpreters provide it.]";
               8: "please give one of the answers above.";
               9: "^it is now pitch dark in here!";
              10: "i beg your pardon?";
              11: "[you can't ~undo~ what hasn't been done!]";
              12: "[can't ~undo~ twice in succession. sorry!]";
              13: "[previous turn undone.]";
              14: "sorry, that can't be corrected.";
              15: "think nothing of it.";
              16: "~oops~ can only correct a single word.";
              17: "it is pitch dark, and you can't see a thing.";
              18: print "yourself";
              19: "as good-looking as ever.";           
              20: "to repeat a command like ~frog, jump~, just say
                   ~again~, not ~frog, again~.";
              21: "you can hardly repeat that.";
              22: "you can't begin with a comma.";
              23: "you seem to want to talk to someone, but i can't see whom.";
              24: "you can't talk to ", (the) x1, ".";
              25: "to talk to someone, try ~someone, hello~ or some such.";
              26: "(first taking ", (the) not_holding, ")";
              27: "i didn't understand that sentence.";
              28: print "i only understood you as far as wanting to ";
              29: "i didn't understand that number.";
              30: "you can't see any such thing.";
              31: "you seem to have said too little!";
              32: "you aren't holding that!";
              33: "you can't use multiple objects with that verb.";
              34: "you can only use multiple objects once on a line.";
              35: "i'm not sure what ~", (address) pronoun_word,
                  "~ refers to.";
              36: "you excepted something not included anyway!";
              37: "you can only do that to something animate.";
              38: #ifdef DIALECT_US;
                  "that's not a verb i recognize.";
                  #ifnot;
                  "that's not a verb i recognise.";
                  #endif;
              39: "that's not something you need to refer to
                   in the course of this game.";
              40: "you can't see ~", (address) pronoun_word,
                  "~ (", (the) pronoun_obj, ") at the moment.";
              41: "i didn't understand the way that finished.";
              42: if (x1==0) print "none";
                  else print "only ", (number) x1;
                  print " of those ";
                  if (x1==1) print "is"; else print "are";
                  " available.";
              43: "nothing to do!";
              44: "there are none at all available!";
              45: print "who do you mean, ";
              46: print "which do you mean, ";
              47: "sorry, you can only have one item here. which exactly?";
              48: print "whom do you want";
                  if (actor~=player) print " ", (the) actor; print " to ";
                  PrintCommand(); print "?^";
              49: print "what do you want";
                  if (actor~=player) print " ", (the) actor; print " to ";
                  PrintCommand(); print "?^";
              50: print "your score has just gone ";
                  if (x1 > 0) print "up"; else { x1 = -x1; print "down"; }
                  print " by ", (number) x1, " point";
                  if (x1 > 1) print "s";
              51: "(since something dramatic has happened,
                   your list of commands has been cut short.)";
              52: "^type a number from 1 to ", x1,
                  ", 0 to redisplay or press enter.";
              53: "^[please press space.]";
           }

  ListMiscellany:
           switch(n)
           {   1: print " (providing light)";
               2: print " (which ", (isorare) x1, " closed)";
               3: print " (closed and providing light)";
               4: print " (which ", (isorare) x1, " empty)";
               5: print " (empty and providing light)";
               6: print " (which ", (isorare) x1, " closed and empty)";
               7: print " (closed, empty and providing light)";
               8: print " (providing light and being worn";
               9: print " (providing light";
              10: print " (being worn";
              11: print " (which ", (isorare) x1, " ";
              12: print "open";
              13: print "open but empty";
              14: print "closed";
              15: print "closed and locked";
              16: print " and empty";
              17: print " (which ", (isorare) x1, " empty)";
              18: print " containing ";
              19: print " (on ";
              20: print ", on top of ";
              21: print " (in ";
              22: print ", inside ";
           }

  Pronouns: switch(n)
           {   1: print "at the moment, ";
               2: print "means ";
               3: print "is unset";
               4: "no pronouns are known to the game.";
           }
  Order:          print (the) x1;
                  if (x1 has pluralname) print " have"; else print " has";
                  " better things to do.";
  Quit:    switch(n)
           {   1: print "please answer yes or no.";
               2: print "are you sure you want to quit? ";
           }
  Restart: switch(n)
           {   1: print "are you sure you want to restart? ";
               2: "failed.";
           }
  Restore: switch(n)
           {   1: "restore failed.";
               2: "ok.";
           }
  Save:    switch(n)
           {   1: "save failed.";
               2: "ok.";
           }
  Verify:  switch(n)
           {   1: "the game file has verified as intact.";
               2: "the game file did not verify as intact,
                   and may be corrupt.";
           }
  ScriptOn: switch(n)
           {   1: "transcripting is already on.";
               2: "start of a transcript of";
               3: "attempt to begin transcript failed.";
           }
  ScriptOff: switch(n)
           {   1: "transcripting is already off.";
               2: "^end of transcript.";
               3: "attempt to end transcript failed.";
           }
  NotifyOn:       "score notification on.";
  NotifyOff:      "score notification off.";
  Places:         print "you have visited: ";
  Objects: switch(n)
           {   1: "objects you have handled:^";
               2: "none.";
               3: print "   (worn)";
               4: print "   (held)";
               5: print "   (given away)";
               6: print "   (in ", (name) x1, ")";
               7: print "   (in ", (the) x1, ")";
               8: print "   (inside ", (the) x1, ")";
               9: print "   (on ", (the) x1, ")";
              10: print "   (lost)";
           }
  Score:          if (deadflag) print "in that game you scored ";
                  else print "you have so far scored ";
                  print score, " out of a possible ", MAX_SCORE,
                  ", in ", turns, " turn";
                  if (turns~=1) print "s"; return;
  FullScore: switch(n)
           {   1: if (deadflag) print "the score was ";
                  else          print "the score is ";
                  #ifndef CONSISTANT_SCORE;
                  "made up as follows:^";
                  #endif;
                  #ifdef CONSISTANT_SCORE;
                  "earned from the following actions:^";
                  #endif;
               2: "finding sundry items";
               3: "visiting various places";
               4: print "total (out of ", MAX_SCORE; ")";
           }
  Inv:     switch(n)
           {   1: "you are carrying nothing.";
               2: print "you are carrying";
           }
  Take:    switch(n)
           {   1: "taken.";
               2: "you are always self-possessed.";
               3: "i don't suppose ", (the) x1, " would care for that.";
               4: print "you'd have to get ";
                  if (x1 has supporter) print "off "; else print "out of ";
                  print_ret (the) x1, " first.";
               5: "you already have ", (thatorthose) x1, ".";
               6: if (noun has pluralname) print "those seem ";
                  else print "that seems ";
                  "to belong to ", (the) x1, ".";
               7: if (noun has pluralname) print "those seem ";
                  else print "that seems ";
                  "to be a part of ", (the) x1, ".";
               8: print_ret (Cthatorthose) x1, " ", (isorare) x1,
                  "n't available.";
               9: print_ret (The) x1, " ", (isorare) x1, "n't open.";
              10: if (x1 has pluralname) print "They're ";
                  else print "that's ";
                  "hardly portable.";
              11: if (x1 has pluralname) print "They're ";
                  else print "that's ";
                  "fixed in place.";
              12: "you're carrying too many things already.";
              13: "(putting ", (the) x1, " into ", (the) SACK_OBJECT,
                  " to make room)";
           }
  Drop:    switch(n)
           {   1: if (x1 has pluralname) print (The) x1, " are ";
                  else print (The) x1, " is ";
                  "already here.";
               2: "you haven't got ", (thatorthose) x1, ".";
               3: "(first taking ", (the) x1, " off)";
               4: "dropped.";
           }
  Remove:  switch(n)
           {   1: if (x1 has pluralname) print "they are"; else print "It is";
                  " unfortunately closed.";
               2: if (x1 has pluralname)
                      print "but they aren't";
                  else print "but it isn't";
                  " there now.";
               3: "removed.";
           }
  PutOn:   switch(n)
           {   1: "you need to be holding ", (the) x1,
                  " before you can put ", (itorthem) x1,
                  " on top of something else.";
               2: "you can't put something on top of itself.";
               3: "putting things on ", (the) x1, " would achieve nothing.";
               4: "you lack the dexterity.";
               5: "(first taking ", (itorthem) x1, " off)^";
               6: "there is no more room on ", (the) x1, ".";
               7: "done.";
               8: "you put ", (the) x1, " on ", (the) second, ".";
           }
  Insert:  switch(n)
           {   1: "you need to be holding ", (the) x1,
                  " before you can put ", (itorthem) x1,
                  " into something else.";
               2: print_ret (Cthatorthose) x1, " can't contain things.";
               3: print_ret (The) x1, " ", (isorare) x1, " closed.";
               4: "you'll need to take ", (itorthem) x1, " off first.";
               5: "you can't put something inside itself.";
               6: "(first taking ", (itorthem) x1, " off)^";
               7: "there is no more room in ", (the) x1, ".";
               8: "done.";
               9: "you put ", (the) x1, " into ", (the) second, ".";
           }
  EmptyT:  switch(n)
           {   1: print_ret (The) x1, " can't contain things.";
               2: print_ret (The) x1, " ", (isorare) x1, " closed.";
               3: print_ret (The) x1, " ", (isorare) x1, " empty already.";
               4: "that would scarcely empty anything.";
           }
  Give:    switch(n)
           {   1: "you aren't holding ", (the) x1, ".";
               2: "you juggle ", (the) x1,
                  " for a while, but don't achieve much.";
               3: print (the) x1;
                  if (x1 has pluralname) print " don't";
                  else print " doesn't";
                  " seem interested.";
           }
  Show:    switch(n)
           {   1: "you aren't holding ", (the) x1, ".";
               2: print_ret (The) x1, " ", (isorare) x1, " unimpressed.";
           }
  Enter:   switch(n)
           {   1: print "but you're already ";
                  if (x1 has supporter) print "on "; else print "in ";
                  print_ret (the) x1, ".";
               2: if (x1 has pluralname) print "they're"; else print "that's";
                  " not something you can enter.";
               3: "you can't get into the closed ", (name) x1, ".";
               4: "you can only get into something free standing.";
               5: print "you get ";
                  if (x1 has supporter) print "onto "; else print "into ";
                  print_ret (the) x1, ".";
               6: print "(getting ";
                  if (x1 has supporter) print "off "; else print "out of ";
                  print (the) x1; ")";
               7: if (x1 has supporter) "(getting onto ", (the) x1, ")^";
                  if (x1 has container) "(getting into ", (the) x1, ")^";
                  "(entering ", (the) x1, ")^";
           }
  GetOff:         "but you aren't on ", (the) x1, " at the moment.";
  Exit:    switch(n)
           {   1: "but you aren't in anything at the moment.";
               2: "you can't get out of the closed ", (name) x1, ".";
               3: print "you get ";
                  if (x1 has supporter) print "off "; else print "out of ";
                  print_ret (the) x1, ".";
           }
  VagueGo:       "you'll have to say which compass direction to go in.";

  Go:      switch(n)
           {   1: print "you'll have to get ";
                  if (x1 has supporter) print "off "; else print "out of ";
                  print_ret (the) x1, " first.";
               2: "you can't go that way.";
               3: "you are unable to climb ", (the) x1, ".";
               4: "you are unable to descend by ", (the) x1, ".";
               5: "you can't, since ", (the) x1, " ", (isorare) x1,
                  " in the way.";
               6: print "you can't, since ", (the) x1;
                  if (x1 has pluralname) " lead nowhere.";
                  " leads nowhere.";
           }

  LMode1:         " is now in its normal ~brief~ printing mode, which gives
                   long descriptions of places never before visited and short
                   descriptions otherwise.";
  LMode2:         " is now in its ~verbose~ mode, which always gives long
                   descriptions of locations
                   (even if you've been there before).";
  LMode3:         " is now in its ~superbrief~ mode, which always gives short
                   descriptions of locations
                   (even if you haven't been there before).";

  Look:    switch(n)
           {   1: print " (on ", (the) x1, ")";
               2: print " (in ", (the) x1, ")";
               3: print " (as "; @print_obj x1; print ")";
               4: print "^on ", (the) x1;
                  WriteListFrom(child(x1),
                      ENGLISH_BIT + RECURSE_BIT + PARTINV_BIT
                      + TERSE_BIT + ISARE_BIT + CONCEAL_BIT);
                  ".";
         default: if (x1~=location)
                  {   if (x1 has supporter) print "^on "; else print "^in ";
                      print (the) x1, " you";
                  }
                  else print "^you";
                  print " can ";
                  if (n==5) print "also "; print "see ";
                  WriteListFrom(child(x1),
                      ENGLISH_BIT + WORKFLAG_BIT + RECURSE_BIT
                      + PARTINV_BIT + TERSE_BIT + CONCEAL_BIT);
                  if (x1~=location) ".";
                  " here.";
           }

  Examine: switch(n)
           {   1: "darkness, noun.  an absence of light to see by.";
               2: "you see nothing special about ", (the) x1, ".";
               3: print (The) x1, " ", (isorare) x1, " currently switched ";
                  if (x1 has on) "on."; else "off.";
           }
  LookUnder: switch(n)
           {   1: "but it's dark.";
               2: "you find nothing of interest.";
           }

  Search:  switch(n)
           {   1: "but it's dark.";
               2: "there is nothing on ", (the) x1, ".";
               3: print "on ", (the) x1;
                  WriteListFrom(child(x1),
                      TERSE_BIT + ENGLISH_BIT + ISARE_BIT + CONCEAL_BIT);
                  ".";
               4: "you find nothing of interest.";
               5: "you can't see inside, since ", (the) x1, " ",
                  (isorare) x1, " closed.";
               6: print_ret (the) x1, " ", (isorare) x1, " empty.";
               7: print "in ", (the) x1;
                  WriteListFrom(child(x1),
                      TERSE_BIT + ENGLISH_BIT + ISARE_BIT + CONCEAL_BIT);
                  ".";
           }

  Unlock:  switch(n)
           {   1: if (x1 has pluralname) print "they don't ";
                  else print "that doesn't ";
                  "seem to be something you can unlock.";
               2: print_ret (ctheyreorthats) x1,
                  " unlocked at the moment.";
               3: if (x1 has pluralname) print "those don't ";
                  else print "that doesn't ";
                  "seem to fit the lock.";
               4: "you unlock ", (the) x1, ".";
           }
  Lock:    switch(n)
           {   1: if (x1 has pluralname) print "they don't ";
                  else print "that doesn't ";
                  "seem to be something you can lock.";
               2: print_ret (ctheyreorthats) x1, " locked at the moment.";
               3: "first you'll have to close ", (the) x1, ".";
               4: if (x1 has pluralname) print "those don't ";
                  else print "that doesn't ";
                  "seem to fit the lock.";
               5: "you lock ", (the) x1, ".";
           }

  SwitchOn: switch(n)
           {   1: print_ret (ctheyreorthats) x1,
                  " not something you can switch.";
               2: print_ret (ctheyreorthats) x1,
                  " already on.";
               3: "you switch ", (the) x1, " on.";
           }
  SwitchOff: switch(n)
           {   1: print_ret (ctheyreorthats) x1,
                  " not something you can switch.";
               2: print_ret (ctheyreorthats) x1,
                  " already off.";
               3: "you switch ", (the) x1, " off.";
           }

  Open:    switch(n)
           {   1: print_ret (ctheyreorthats) x1,
                  " not something you can open.";
               2: if (x1 has pluralname) print "They seem ";
                  else print "It seems ";
                  "to be locked.";
               3: print_ret (ctheyreorthats) x1,
                  " already open.";
               4: print "you open ", (the) x1, ", revealing ";
                  if (WriteListFrom(child(x1),
                      ENGLISH_BIT + TERSE_BIT + CONCEAL_BIT)==0) "nothing.";
                  ".";
               5: "you open ", (the) x1, ".";
           }

  Close:   switch(n)
           {   1: print_ret (ctheyreorthats) x1,
                  " not something you can close.";
               2: print_ret (ctheyreorthats) x1,
                  " already closed.";
               3: "you close ", (the) x1, ".";
           }
  Disrobe: switch(n)
           {   1: "you're not wearing ", (thatorthose) x1, ".";
               2: "you take off ", (the) x1, ".";
           }
  Wear:    switch(n)
           {   1: "you can't wear ", (thatorthose) x1, "!";
               2: "you're not holding ", (thatorthose) x1, "!";
               3: "you're already wearing ", (thatorthose) x1, "!";
               4: "you put on ", (the) x1, ".";
           }
  Eat:     switch(n)
           {   1: print_ret (ctheyreorthats) x1,
                  " plainly not edible.";
               2: "you eat ", (the) x1, ". Not bad.";
           }
  Yes, No:        "that was a rhetorical question.";
  Burn:           "this dangerous act would achieve little.";
  Pray:           "nothing practical results from your prayer.";
  Wake:           "the dreadful truth is, this is not a dream.";
  WakeOther:      "that seems unnecessary.";
  Kiss:           "keep your mind on the game.";
  Think:          "what a good idea.";
  Smell:          "you smell nothing unexpected.";
  Listen:         "you hear nothing unexpected.";
  Taste:          "you taste nothing unexpected.";
  Touch:   switch(n)
           {   1: "keep your hands to yourself!";
               2: "you feel nothing unexpected.";
               3: "if you think that'll help.";
           }
  Dig:            "digging would achieve nothing here.";
  Cut:            "cutting ", (thatorthose) x1, " up would achieve little.";
  Jump:           "you jump on the spot, fruitlessly.";
  JumpOver, Tie:  "you would achieve nothing by this.";
  Drink:          "there's nothing suitable to drink here.";
  Fill:           "but there's no water here to carry.";
  Sorry:          #ifdef DIALECT_US;
                  "oh, don't apologize.";
                  #ifnot;
                  "oh, don't apologise.";
                  #endif;
  Strong:         "real adventurers do not use such language.";
  Mild:           "quite.";
  Attack:         "violence isn't the answer to this one.";
  Swim:           "there's not enough water to swim in.";
  Swing:          "there's nothing sensible to swing here.";
  Blow:           "you can't usefully blow ", (thatorthose) x1, ".";
  Rub:            "you achieve nothing by this.";
  Set:            "no, you can't set ", (thatorthose) x1, ".";
  SetTo:          "no, you can't set ", (thatorthose) x1, " to anything.";
  WaveHands:      "you wave, feeling foolish.";
  Wave:    switch(n)
           {   1: "but you aren't holding ", (thatorthose) x1, ".";
               2: "you look ridiculous waving ", (the) x1, ".";
           }
  Pull, Push, Turn:
           switch(n)
           {   1: if (x1 has pluralname) print "those are ";
                  else print "It is ";
                  "fixed in place.";
               2: "you are unable to.";
               3: "nothing obvious happens.";
               4: "that would be less than courteous.";
           }
  PushDir: switch(n)
           {   1: "is that the best you can think of?";
               2: "that's not a direction.";
               3: "not that way you can't.";
           }
  Squeeze: switch(n)
           {   1: "keep your hands to yourself.";
               2: "you achieve nothing by this.";
           }
  ThrowAt: switch(n)
           {   1: "futile.";
               2: "you lack the nerve when it comes to the crucial moment.";
           }
  Tell:    switch(n)
           {   1: "you talk to yourself a while.";
               2: "this provokes no reaction.";
           }
  Answer, Ask:    "there is no reply.";
  Buy:            "nothing is on sale.";
  Sing:           "your singing is abominable.";
  Climb:          "i don't think much is to be achieved by that.";
  Wait:           "time passes.";
  Sleep:          "you aren't feeling especially drowsy.";
  Consult:        "you discover nothing of interest in ", (the) x1, ".";
];

! ---------------------------------------------------------------------------
