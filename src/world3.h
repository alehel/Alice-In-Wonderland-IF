! ==========================================================================
!   world3.h -- Chapters VIII-XII:
!   the Queen's croquet-ground, the Mock Turtle, and the trial.
! ==========================================================================

Global garden_nudge = 0;
Global flam_tucked = 0;
Global head_calm = 0;         ! turns remaining of flamingo-head-down
Global croquet_turns = 0;
Global croquet_done = 0;
Global cathead_stage = 0;
Global duchess_walk = 0;
Global gryphon_here = 0;
Global quiz_open = 0;
Global dance_turns = 0;
Global recite_beats = 0;
Global court_nudge = 0;
Global jury_up = 0;           ! jurors put back after the upset
Global lizard_righted = 0;
Global pencil_taken = 0;

! ==========================================================================
!   CHAPTER VIII -- The Queen's Croquet-Ground
! ==========================================================================

Object RoseGarden "The Beautiful Garden"
  with description [;
           print "Bright flowerbeds and cool fountains at last: the
               loveliest garden you ever saw. A large rose-tree stands
               near the entrance: the roses growing on it are white, but ";
           if (garden_stage == 0)
               print "three gardeners are at it, busily painting them
                   red. ";
           else
               print "they have been painted red, in some haste, by three
                   gardeners whose fortunes have since varied. ";
           print "A large flowerpot stands near.";
           if (garden_stage >= 2)
               print " The croquet-ground lies onward, to the north.";
           new_line;
       ],
       n_to [;
           if (garden_stage < 6)
               "The procession, the Queen, and the present crisis are all
                exactly in the way.";
           return CroquetGround;
       ],
       s_to "The little door has shut behind you, and dwindled, and is
            gone: gardens here keep their exits fluid.",
  has  light;

Object -> rose_tree "rose-tree"
  with name 'rose' 'tree' 'roses' 'rose-tree' 'white' 'red' 'paint',
       description [;
           if (garden_stage == 0)
               "The roses are white, and the gardeners are painting them
                red, splashing rather. A curious thing to do, one would
                say.";
           "Red now -- or red enough, if nobody looks at the drips.";
       ],
  has  scenery;

Object -> flowerpot "large flowerpot"
  with name 'flowerpot' 'flower' 'pot' 'large',
       description
           "A large flowerpot, of the roomy sort that will take a small
            shrub -- or, at a pinch, something in three pieces.",
       before [;
           Receive:
               if (noun == the_gardeners) return PotTheGardeners();
               "It is a flowerpot, not a lumber-room.";
       ],
  has  container open static;

Object -> the_gardeners "three gardeners"
  with name 'gardener' 'gardeners' 'three' 'two' 'five' 'seven' 'cards'
            'card',
       description [;
           if (garden_stage == 0)
               "Three gardeners, oblong and flat, with their hands and
                feet at the corners -- playing-cards, in fact: Two, Five
                and Seven of Spades, all busily painting the white roses
                red, and quarrelling in whispers as they work.";
           if (garden_stage < 4)
               "Two, Five and Seven, flat on their faces. As the pattern
                on their backs is the same as the rest of the pack, there
                is no telling which is which just now.";
           "Two, Five and Seven, huddled close to you and looking with
            great anxiety at everything but the soldiers.";
       ],
       life [;
           Ask, Tell, Answer:
               if (garden_stage == 0) return WhyPaintRoses();
               if (garden_stage >= 4)
                   "~The pot, Miss, the pot!~ whispers Two, from about the
                    level of your knee.";
               "They are lying on their faces, and cards on their faces
                have nothing to say.";
       ],
       before [;
           Take:
               if (garden_stage >= 4) return PotTheGardeners();
               "One does not simply gather up gardeners.";
           Insert:
               if (garden_stage >= 4) return PotTheGardeners();
       ],
  has  animate;

[ WhyPaintRoses;
    if (garden_stage > 0)
        "The gardeners are past conversation just at present.";
    garden_stage = 1;
    "~Would you tell me,~ you say, a little timidly, ~why you are
     painting those roses?~^^Five and Seven say nothing, but look at Two.
     Two begins in a low voice: ~Why the fact is, you see, Miss, this
     here ought to have been a RED rose-tree, and we put a white one in
     by mistake; and if the Queen was to find it out, we should all have
     our heads cut off, you know. So you see, Miss, we're doing our best,
     afore she comes, to--~ At this moment Five, who has been anxiously
     looking across the garden, calls out ~The Queen! The Queen!~ and the
     three gardeners instantly throw themselves flat upon their faces.
     There is a sound of many footsteps, and you look round, eager to
     see the Queen.";
];

Object -> hearts_procession "procession"
  with name 'procession' 'soldiers' 'courtiers' 'children' 'guests'
            'clubs' 'diamonds' 'hearts' 'pack',
       description
           "Soldiers carrying clubs, oblong and flat like the gardeners;
            courtiers ornamented with diamonds; royal children with
            hearts; guests, mostly Kings and Queens; the White Rabbit,
            talking in a hurried nervous manner; the Knave of Hearts,
            carrying the King's crown on a crimson velvet cushion; and
            last of all, the King and Queen of Hearts.",
  has  scenery concealed;

Object -> garden_queen "Queen of Hearts"
  with name 'queen' 'of' 'hearts' 'majesty',
       description
           "The Queen of Hearts, in a fury the colour of her suit. Her
            method with all difficulties, great or small, is the same,
            and it is loud.",
       life [;
           Ask, Tell, Answer: return GardenSay();
           Attack: "There is bold, and there is silly.";
           Kiss: "There is bold, and there is silly.";
       ],
  has  animate female concealed;

Object -> garden_king "King of Hearts"
  with name 'king',
       description
           "The King of Hearts: milder than his Queen, as everything is
            milder than his Queen.",
       life [;
           Ask, Tell, Answer:
               "~Consider, my dear,~ the King is saying, timidly, to
                nobody in particular: he keeps it by him for general
                use.";
       ],
  has  animate concealed;

Object -> garden_soldiers "three soldiers"
  with name 'soldier' 'soldiers' 'executioners',
       description
           "Three soldiers, remaining behind to execute the unfortunate
            gardeners, and searching for them up and down in a puzzled,
            official way.",
       life [;
           Ask, Tell, Answer:
               "~Are their heads off?~ comes the Queen's shout, from up
                the ground. The soldiers look at you meaningly.";
       ],
  has  animate concealed;

[ GardenSay;
    switch (garden_stage) {
        2:  garden_stage = 3;
            "~My name is Alice, so please your Majesty,~ you say very
             politely; but you add, to yourself, ~Why, they're only a
             pack of cards, after all. I needn't be afraid of them!~^^\
             ~And who are THESE?~ says the Queen, pointing to the three
             gardeners lying round the rose-tree; for, you see, as they
             are lying on their faces, and the pattern on their backs is
             the same as the rest of the pack, she cannot tell whether
             they are gardeners, or soldiers, or courtiers, or three of
             her own children. ~How should I know?~ you say, surprised at
             your own courage. ~It's no business of MINE.~^^The Queen
             turns crimson with fury, and, after glaring at you for a
             moment like a wild beast, screams ~Off with her head!
             Off--~ (One loud, decided word would do here. NONSENSE, for
             instance. Say it!)";
        3:  if (TopicHas('nonsense') || TopicHas('stuff')) {
                garden_stage = 4;
                Achieved(T_NONSENSE);
                give garden_soldiers ~concealed;
                "~Nonsense!~ you say, very loudly and decidedly, and the
                 Queen is silent. The King lays his hand upon her arm,
                 and timidly says ~Consider, my dear: she is only a
                 child!~^^The Queen turns angrily away from him, and says
                 to the Knave ~Turn them over!~ The Knave does so, very
                 carefully, with one foot. ~Get up!~ says the Queen, in a
                 shrill, loud voice, and the three gardeners instantly
                 jump up and begin bowing to everybody. ~Leave off
                 that!~ screams the Queen. ~You make me giddy.~ Then,
                 examining the roses: ~What HAVE you been doing here?...
                 I see! Off with their heads!~ -- and the procession
                 moves on, three soldiers remaining behind to execute the
                 unfortunate gardeners, who run to YOU for protection.
                 (The soldiers are casting about -- quick! The gardeners
                 would fit in the large FLOWERPOT!)";
            }
            "You open your mouth, and courage fails, and something polite
             and useless comes out; the Queen's scream is still gathering.
             (Say NONSENSE -- loudly, and as if you meant it. They're
             only a pack of cards!)";
        default:
            "You say it; the garden glitters; nobody minds.";
    }
];

[ PotTheGardeners;
    if (garden_stage ~= 4)
        "The gardeners are not in need of potting just now.";
    garden_stage = 5;
    Achieved(T_FLOWERPOT);
    "~You shan't be beheaded!~ you say, and you put them into the large
     flowerpot that stands near. The three soldiers wander about for a
     minute or two, looking for them, and then quietly march off after
     the others. ~Are their heads off?~ shouts the Queen in the distance.
     ~Their heads are gone, if it please your Majesty!~ the soldiers
     shout in reply. ~That's right!~ shouts the Queen. ~Can you play
     croquet?~^^The soldiers are silent, and look at you, as the question
     is evidently meant for you. (Well? Can you? The answer expected of
     everybody here is YES.)";
];

[ GardenYes;
    if (garden_stage == 5) {
        garden_stage = 6;
        chapter = 8;
        move the_flamingo to player;
        print "~Yes!~ you shout. ~Come on, then!~ roars the Queen, and you
            join the procession, wondering very much what will happen
            next. ~It's -- it's a very fine day!~ says a timid voice at
            your side: you are walking by the White Rabbit, who is
            peeping anxiously into your face. ~Very,~ you say. ~Where's
            the Duchess?~ ~Hush! Hush!~ says the Rabbit in a low, hurried
            tone: ~she's under sentence of execution.~ ~What for?~ ~She
            boxed the Queen's ears--~ (you give a little scream of
            laughter) ~--Oh, hush! the Queen will hear you!~^";
        PlayerTo(CroquetGround);
        rtrue;
    }
    rfalse;
];

Object GardenScene "(garden scene)"
  with daemon [;
           if (location ~= RoseGarden) rfalse;
           if (garden_stage == 0) {
               garden_nudge++;
               if (garden_nudge == 1)
                   "^One of the gardeners says, ~Look out now, Five!
                    Don't go splashing paint over me like that!~ ~I
                    couldn't help it,~ says Five, in a sulky tone:
                    ~Seven jogged my elbow.~ On which Seven looks up and
                    says, ~That's right, Five! Always lay the blame on
                    others!~ (They are cards, painting roses. One does
                    rather want to ask why.)";
               if (garden_nudge >= 3) { garden_nudge = 0; }
               rfalse;
           }
           if (garden_stage == 1) {
               garden_stage = 2;
               give hearts_procession ~concealed;
               give garden_queen ~concealed; give garden_king ~concealed;
               "^First come ten soldiers carrying clubs, all shaped like
                the three gardeners, oblong and flat, with their hands
                and feet at the corners: next the ten courtiers,
                ornamented all over with diamonds; after these the royal
                children, ten of them, jumping merrily along hand in
                hand, ornamented with hearts. Next come the guests,
                mostly Kings and Queens, and among them you recognise
                the White Rabbit; then the Knave of Hearts, carrying the
                King's crown on a crimson velvet cushion; and last of all
                this grand procession, THE KING AND QUEEN OF HEARTS.^^\
                When the procession comes opposite to you, they all stop
                and look at you, and the Queen says severely, ~Who is
                this?~ She says it to the Knave of Hearts, who only bows
                and smiles in reply. ~Idiot!~ says the Queen, tossing her
                head impatiently; and, turning to you, she goes on:
                ~What's your name, child?~ (You had better ANSWER her --
                politely, of course; whatever you privately think of
                playing-cards.)";
           }
           if (garden_stage == 3) {
               garden_nudge++;
               if (garden_nudge >= 2) {
                   garden_nudge = 0;
                   "^~Off with her head! Off with--~ The scream is
                    warming up again. (NONSENSE is the word, said loudly.
                    They're only a pack of cards, after all!)";
               }
           }
           if (garden_stage == 4) {
               garden_nudge++;
               if (garden_nudge >= 2) {
                   garden_nudge = 0;
                   "^The three soldiers peer behind the rose-tree, under
                    the paint-bucket, everywhere but the right place; the
                    gardeners press against your skirts. (The FLOWERPOT,
                    quick: PUT THE GARDENERS IN THE FLOWERPOT.)";
               }
           }
           rfalse;
       ];

! --------------------------------------------------------------------------
! The croquet-ground.
! --------------------------------------------------------------------------

Object CroquetGround "The Queen's Croquet-Ground"
  with description [;
           print "You have never seen such a curious croquet-ground in
               your life: it is all ridges and furrows; the balls are
               live hedgehogs, the mallets live flamingoes, and the
               soldiers have to double themselves up and stand on their
               hands and feet, to make the arches. The players all play
               at once without waiting for turns, quarrelling all the
               while, and fighting for the hedgehogs; and the Queen goes
               stamping about, shouting ~Off with his head!~ or ~Off with
               her head!~ about once in a minute.";
           if (croquet_done == 0) CroquetStatus();
           new_line;
       ],
       s_to "The garden entrance is all procession and paint.",
       n_to [;
           if (gryphon_here) return GryphonWay();
           "Ridges, furrows, and flamingo-tempered chaos in every
            direction: there is nowhere to go until matters here arrange
            themselves.";
       ],
  has  light;

[ CroquetStatus;
    new_line; new_line;
    print "Your flamingo is ";
    if (flam_tucked) print "tucked under your arm, legs hanging down";
    else print "wandering at the end of your grip, mostly neck";
    print "; its head is ";
    if (head_calm > 0) print "nicely straightened out and down";
    else print "twisted round, looking up in your face";
    print ". The hedgehog ";
    switch (croquet_turns % 3) {
        0: print "has unrolled itself and is trundling conveniently
            near";
        1: print "is in the act of crawling away";
        2: print "has met another hedgehog, and rolled up for the
            argument";
    }
    print ". Just ahead, a soldier-arch ";
    if (croquet_turns % 2 == 0) print "is doubled up in place";
    else print "has got up and is walking off to another part of the
        ground";
    print ".";
];

Object -> the_flamingo "flamingo"
  with name 'flamingo' 'mallet' 'bird' 'neck' 'head',
       description
           "A live flamingo, issued to you as a mallet. Its body can be
            tucked away comfortably enough under your arm; the neck and
            the opinions are the difficulty.",
       before [;
           Drop: "You had better keep hold of it: mallets are scarce and
               tempers are short.";
           Turn, Push, Pull, Squeeze, Touch, Rub:
               return CalmFlamingo();
       ],
       life [;
           Ask, Tell, Answer:
               "The flamingo twists its neck round and looks up in your
                face with such a puzzled expression that you cannot help
                bursting out laughing.";
       ],
  has  animate;

Object -> the_hedgehog "hedgehog"
  with name 'hedgehog' 'ball',
       description [;
           switch (croquet_turns % 3) {
               0: "Unrolled, whiskering about, and for the moment
                   conveniently near: as ready as a live croquet-ball
                   ever is.";
               1: "In the act of crawling away, in the unhurried manner
                   of a ball that knows it is also a hedgehog.";
               2: "Rolled up tight: it has met another hedgehog, and the
                   two are having it out, spines first.";
           }
       ],
       before [;
           Take: "The Queen's hedgehogs are not to be pocketed; besides,
               the correct instrument is the flamingo.";
           Attack: return CroquetStroke();
       ],
       life [;
           Ask, Tell, Answer: "It whiskers, non-committally.";
       ],
  has  animate;

Object -> the_arches "soldier-arches"
  with name 'arch' 'arches' 'soldier' 'soldiers' 'soldier-arch',
       description
           "Soldiers doubled up on hands and feet to make the arches --
            when they are not getting up and walking off to other parts
            of the ground, which is most of the time.",
  has  scenery;

Object -> croquet_queen "Queen of Hearts"
  with name 'queen' 'majesty' 'hearts',
       description
           "In a furious passion, stamping about, and shouting ~Off with
            his head!~ or ~Off with her head!~ about once in a minute.",
       life [;
           Ask, Tell, Answer:
               if (cathead_stage == 2) return CroquetSay();
               "~ARE you playing?~ demands the Queen, in passing. ~A
                moment's delay would cost--~ but she is already shouting
                at somebody else.";
       ],
  has  animate female;

Object -> croquet_king "King of Hearts"
  with name 'king',
       description "Following the Queen at a safe distance, which moves.",
       life [;
           Ask, Tell, Answer:
               if (cathead_stage == 2) return CroquetSay();
               "~Consider, my dear,~ murmurs the King, keeping it warm.";
       ],
  has  animate;

Object -> cheshire_head "head of the Cheshire Cat"
  with name 'cheshire' 'cat' 'head' 'grin',
       description
           "A grin, then eyes, then the whole head of the Cheshire Cat,
            hanging in the air with no body attached to it whatever. It
            appears to think there is enough of it in sight.",
       life [;
           Ask, Tell, Answer:
               "~How do you like the Queen?~ says the Cat in a low voice.
                ~Not at all,~ you begin; ~she's so extremely--~ and just
                then you notice the Queen close behind you, listening;
                so you go on, ~--likely to win, that it's hardly worth
                while finishing the game.~ The Queen smiles and passes
                on.";
       ],
  has  animate concealed;

[ TuckFlamingo;
    if (location ~= CroquetGround) "There is nothing here to tuck.";
    if (flam_tucked)
        "The flamingo is tucked already, as far as a flamingo consents
         to be.";
    flam_tucked = 1;
    "You succeed in getting its body tucked away, comfortably enough,
     under your arm, with its legs hanging down. The neck remains a
     free agent.";
];

[ CalmFlamingo;
    if (location ~= CroquetGround)
        "There is no flamingo wanting attention here.";
    head_calm = 2;
    "You get its neck nicely straightened out, and its head down, ready
     to strike. It submits, for the moment, with the expression of a
     bird biding its time. (It will not bide long.)";
];

[ CroquetStroke;
    if (croquet_done)
        "Once was miracle enough: the arches are dispersing, and the
         Queen's temper is the only thing still in play.";
    if (flam_tucked == 0)
        "You swing; the flamingo, untucked, simply walks its legs in the
         air and turns the stroke into a flourish. Its body wants
         tucking under your arm first.";
    if (head_calm == 0)
        "Just as you swing, the flamingo twists itself round and looks up
         in your face with such a puzzled expression that you burst out
         laughing, and the stroke is lost. Its head wants getting down
         first -- and it will not stay down long, either.";
    if (croquet_turns % 3 ~= 0)
        "Your stroke arrives where the hedgehog was: it is either
         crawling off or rolled up in an argument, and in neither state
         is it at home to mallets. (It unrolls and trundles near in its
         own regular turn: watch it.)";
    if (croquet_turns % 2 ~= 0)
        "A clean strike -- and no arch! Yours has got up and walked off
         to another part of the ground, in the manner of arches here.
         (It doubles up in place every other turn: time your stroke for
         when hedgehog AND arch oblige together.)";
    croquet_done = 1;
    Achieved(T_CROQUET);
    "Flamingo tucked, head down, hedgehog unrolled and near, arch in
     place: you swing, there is a soft thump of mallet-head on
     hedgehog, and the hedgehog trundles across the ridge, through the
     doubled-up soldier, and out the other side -- THROUGH THE ARCH.
     It may be the first fair croquet stroke ever played on this
     ground. The soldier-arch looks round at you, upside down, with an
     expression of profound respect; and somewhere behind you the Queen,
     lacking anything to object to, shouts ~Off with his head!~ at a
     passing dragonfly.";
];

Object CroquetScene "(croquet scene)"
  with daemon [;
           if (location ~= CroquetGround) rfalse;
           croquet_turns++;
           if (head_calm > 0) head_calm--;
           if (croquet_done == 0) {
               if (croquet_turns == 1) {
                   print "^The chief difficulty at first is your
                       flamingo. (Its body wants TUCKING under your arm;
                       its head wants CALMING down; and then there is the
                       question of the hedgehog, and of the arch.
                       Everything here moves in its own regular turn, and
                       a person who watched the turns might catch them
                       all agreeing.)";
               }
               CroquetStatus();
               new_line;
               rtrue;
           }
           ! After the great stroke: the Cheshire Cat's head.
           switch (cathead_stage) {
               0:  cathead_stage = 1;
                   give cheshire_head ~concealed;
                   "^A curious appearance in the air puzzles you very
                    much at first: but after watching it a minute or two
                    you make it out to be a grin, and you say to
                    yourself, ~It's the Cheshire Cat: now I shall have
                    somebody to talk to.~ The head appears as far as the
                    ears, and stops there.";
               1:  cathead_stage = 2;
                   "^~Well, it must be removed,~ says the King very
                    decidedly, who does not like the look of it at all;
                    and he calls to the Queen, ~My dear! I wish you would
                    have this cat removed!~ The Queen has only one way of
                    settling all difficulties, great or small: ~Off with
                    his head!~ she says, without even looking round. ~I'll
                    fetch the executioner myself,~ says the King eagerly.^^\
                    In a very few minutes quite a crowd has collected:
                    the executioner's argument is, that you can't cut off
                    a head unless there is a body to cut it off from,
                    and he isn't going to begin at HIS time of life. The
                    King's argument is, that anything that has a head can
                    be beheaded, and you're not to talk nonsense. The
                    Queen's argument is, that if something isn't done
                    about it in less than no time, she'll have everybody
                    executed all round. (They all appeal to YOU to settle
                    the question. Whose cat is it, now? You might SAY
                    so.)";
               2:  court_nudge++;
                   if (court_nudge >= 2) {
                       court_nudge = 0;
                       "^The executioner, the King and the Queen all talk
                        at once, and the rest of the party stands silent
                        and very uncomfortable. (Whose cat is it? You met
                        it on a certain hearth. SAY THE DUCHESS, before
                        the Queen executes everybody all round.)";
                   }
               3:  cathead_stage = 4;
                   remove cheshire_head;
                   "^By the time the executioner comes back with the
                    Duchess, the Cat's head has faded quite away, and the
                    King and the executioner run wildly up and down
                    looking for it, while the rest of the party goes back
                    to the game. The Duchess, meanwhile, tucks her arm
                    affectionately into yours -- ~You can't think how
                    glad I am to see you again, you dear old thing!~ --
                    and you walk off together. She is in a pleasant
                    temper, and you think to yourself that perhaps it was
                    only the pepper that made her so savage in the
                    kitchen.";
               4:  duchess_walk++;
                   switch (duchess_walk) {
                       1: "^~The game's going on rather better now,~ you
                           say. ~'Tis so,~ says the Duchess: ~and the
                           moral of that is -- `Oh, 'tis love, 'tis love,
                           that makes the world go round!'~ ~Somebody
                           said,~ you whisper, ~that it's done by
                           everybody minding their own business!~ ~Ah,
                           well! It means much the same thing,~ says the
                           Duchess, digging her sharp little chin into
                           your shoulder, ~and the moral of THAT is --
                           `Take care of the sense, and the sounds will
                           take care of themselves.'~ (How fond she is of
                           finding morals in things!)";
                       2: "^~I dare say you're wondering why I don't put
                           my arm round your waist,~ says the Duchess
                           after a pause: ~the reason is, that I'm
                           doubtful about the temper of your flamingo.
                           Shall I try the experiment?~ ~He might bite,~
                           you reply cautiously. ~Very true,~ says the
                           Duchess: ~flamingoes and mustard both bite.
                           And the moral of that is -- `Birds of a
                           feather flock together.'~ ~Only mustard isn't
                           a bird,~ you remark. ~Right, as usual,~ says
                           the Duchess: ~what a clear way you have of
                           putting things!~";
                       3: cathead_stage = 5;
                          "^The Duchess's voice dies away, even in the
                           middle of her favourite word ~moral~, and the
                           arm linked into yours begins to tremble. You
                           look up: there stands the Queen in front of
                           you, arms folded, frowning like a
                           thunderstorm. ~A fine day, your Majesty!~ the
                           Duchess begins in a low, weak voice. ~Now, I
                           give you fair warning,~ shouts the Queen,
                           stamping on the ground as she speaks, ~either
                           you or your head must be off, and that in
                           about half no time! Take your choice!~ The
                           Duchess takes her choice, and is gone in a
                           moment.";
                   }
               5:  cathead_stage = 6;
                   "^~Let's go on with the game,~ the Queen says to you;
                    and you are too much frightened to say a word, but
                    follow her slowly back to the croquet-ground. The
                    game wears on; the Queen never leaves off quarrelling
                    with the other players and shouting ~Off with his
                    head!~; and by the end of half an hour or so there
                    are no arches left, and all the players, except the
                    King, the Queen, and yourself, are in custody and
                    under sentence of execution.";
               6:  cathead_stage = 7;
                   gryphon_here = 1;
                   give the_gryphon ~absent;
                   move the_gryphon to CroquetGround;
                   "^Then the Queen leaves off, quite out of breath, and
                    says to you, ~Have you seen the Mock Turtle yet?~
                    ~No,~ you say. ~I don't even know what a Mock Turtle
                    is.~ ~It's the thing Mock Turtle Soup is made from,~
                    says the Queen. ~Come on, then, and he shall tell you
                    his history.~ As you walk off together, you hear the
                    King say in a low voice, to the company generally,
                    ~You are all pardoned.~^^You very soon come upon a
                    Gryphon, lying fast asleep in the sun. ~Up, lazy
                    thing!~ says the Queen, ~and take this young lady to
                    see the Mock Turtle, and to hear his history. I must
                    go back and see after some executions I have
                    ordered~; and she walks off, leaving you alone with
                    the Gryphon. (You had better FOLLOW it when it goes;
                    it is that or the Queen.)";
               default: rfalse;
           }
           rfalse;
       ];

[ CroquetSay;
    if (cathead_stage == 2
        && (TopicHas('duchess') || TopicHas('duchesss'))) {
        cathead_stage = 3;
        Achieved(T_WHOSECAT);
        "You can think of nothing else to say but ~It belongs to the
         Duchess: you'd better ask HER about it.~ ~She's in prison,~ the
         Queen says to the executioner: ~fetch her here.~ And the
         executioner goes off like an arrow.";
    }
    if (cathead_stage == 2)
        "The three arguments go round again, all at once. (The cat sat
         on somebody's hearth, among the pepper. SAY THE DUCHESS.)";
    "You say it; the croquet-ground swallows remarks smaller than a
     scream.";
];

Object the_gryphon "Gryphon"
  with name 'gryphon' 'griffin',
       description
           "A Gryphon: eagle at the front, lion at the back, and fast
            asleep in the sun until lately. (If you don't know what a
            Gryphon is, this is one.)",
       life [;
           Ask, Tell, Answer:
               if (location == CroquetGround)
                   "The Gryphon sits up and rubs its eyes: then it
                    watches the Queen till she is out of sight: then it
                    chuckles. ~What fun!~ it says, half to itself, half
                    to you. ~What IS the fun?~ you ask. ~Why, SHE,~ says
                    the Gryphon. ~It's all her fancy, that: they never
                    executes nobody, you know. Come on!~ (Everybody says
                    `come on!' here, you think: you never were so ordered
                    about in all your life. Still -- FOLLOW it.)";
               "~Come on!~ says the Gryphon, and that is the whole of its
                conversation just now.";
       ],
  has  animate absent;

[ GryphonWay;
    print "~Come on!~ cries the Gryphon, and you go after it, over the
        ridges and furrows and away from the shouting, until the grass
        turns to shingle and you hear, far off, a heavy sighing.^";
    chapter = 9;
    remove the_gryphon;
    give ledge_gryphon ~absent;
    PlayerTo(RockyLedge);
    rtrue;
];

! ==========================================================================
!   CHAPTERS IX-X -- the Mock Turtle and the Lobster Quadrille
! ==========================================================================

Object RockyLedge "A Ledge of Rock by the Sea"
  with description
           "A little ledge of rock above the shingle, with the sea
            beyond. On it, sad and lonely, sits the Mock Turtle, sighing
            as if his heart would break; the Gryphon has settled itself
            comfortably to listen, as to a favourite tune. The shore
            stretches away on either side.",
       cant_go [;
           if (ledge_stage >= 9) return CourtRun();
           "The Gryphon clears its throat meaningly: one does not walk
            out in the middle of a history, particularly a sad one.";
       ],
  has  light;

Object -> ledge_gryphon "Gryphon"
  with name 'gryphon' 'griffin',
       description
           "The Gryphon, lying with its chin on its paws, interrupting
            the Mock Turtle's story with the ease of long practice.",
       life [;
           Ask, Tell, Answer: return LedgeBeat();
       ],
  has  animate;

Object -> mock_turtle "Mock Turtle"
  with name 'mock' 'turtle' 'mock-turtle',
       description
           "The Mock Turtle: the thing Mock Turtle Soup is made from, and
            he knows it. He looks at you with large eyes full of tears,
            and every so often a sob shakes his shell.",
       life [;
           Ask, Tell, Answer: return LedgeBeat();
           Kiss: "He would only cry the more.";
       ],
  has  animate;

[ LedgeBeat;
    switch (ledge_stage) {
        0:  ledge_stage = 1;
            "~This here young lady,~ says the Gryphon, ~she wants for to
             know your history, she do.~ ~I'll tell it her,~ says the
             Mock Turtle in a deep, hollow tone: ~sit down, both of you,
             and don't speak a word till I've finished.~ You sit; there
             is a long silence. ~Once,~ says the Mock Turtle at last,
             with a deep sigh, ~I was a real Turtle.~^^These words are
             followed by a very long silence, broken only by an
             occasional exclamation of ~Hjckrrh!~ from the Gryphon, and
             the constant heavy sobbing of the Mock Turtle. (LISTEN, and
             let him come to it.)";
        1:  ledge_stage = 2;
            "~When we were little,~ the Mock Turtle goes on at last, more
             calmly, ~we went to school in the sea. The master was an old
             Turtle -- we used to call him Tortoise--~ ~Why did you call
             him Tortoise, if he wasn't one?~ you ask. ~We called him
             Tortoise because he TAUGHT US,~ says the Mock Turtle
             angrily: ~really you are very dull!~ ~You ought to be
             ashamed of yourself for asking such a simple question,~ adds
             the Gryphon; and they both sit and look at you till you feel
             ready to sink into the earth.";
        2:  ledge_stage = 3;
            "~We had the best of educations,~ the Mock Turtle continues.
             ~Reeling and Writhing, of course, to begin with; and then
             the different branches of Arithmetic -- Ambition,
             Distraction, Uglification, and Derision.~ ~I never heard of
             `Uglification',~ you venture to say. The Gryphon lifts up
             both its paws in surprise. ~What! Never heard of uglifying!
             You know what to beautify is, I suppose?~ ~Yes,~ you say
             doubtfully: ~it means -- to -- make -- anything --
             prettier.~ ~Well, then,~ the Gryphon goes on, ~if you don't
             know what to uglify is, you ARE a simpleton.~^^~There was
             Mystery besides,~ says the Mock Turtle, counting the
             subjects off on his flappers: ~Mystery, ancient and modern,
             with Seaography: then Drawling -- the Drawling-master was an
             old conger-eel -- Drawling, Stretching, and Fainting in
             Coils.~";
        3:  ledge_stage = 4; quiz_open = 1;
            "~And how many hours a day did you do lessons?~ you ask, in a
             hurry to change the subject. ~Ten hours the first day,~ says
             the Mock Turtle: ~nine the next, and so on.~ ~What a curious
             plan!~ you exclaim. ~That's the reason they're called
             lessons,~ the Gryphon remarks: ~because they LESSEN from day
             to day.~^^This is quite a new idea to you, and you turn it
             over a little. The Gryphon fixes you with one eye. ~Ten the
             first day, nine the next, eight the day after,~ it says.
             ~Now, Miss Clever-shoes: at that rate of lessening, what do
             you say the ELEVENTH day was?~ (It waits. You might ANSWER
             -- and think of the arithmetic before you do.)";
        4:  "The Gryphon is still waiting for your answer: ten hours the
             first day, nine the next, and so lessening -- what was the
             eleventh day, at that rate? (SAY your answer aloud.)";
        5:  ledge_stage = 6;
            "~Would you like to see a little of the Lobster Quadrille?~
             says the Mock Turtle, brightening. ~Very much indeed,~ you
             say. ~Come, let's try the first figure!~ says the Mock
             Turtle to the Gryphon. ~We can do without lobsters, you
             know. Which shall sing?~ ~Oh, YOU sing,~ says the Gryphon.
             ~I've forgotten the words.~ (They are plainly about to
             begin. You might JOIN IN, when they do; it would be civil,
             whatever it costs your toes.)";
        6, 7: return QuadrilleBeat();
        8:  ledge_stage = 9;
            "The Mock Turtle sighs deeply, and begins, in a voice
             sometimes choked with sobs, to sing:--^^\
             ~Beautiful Soup, so rich and green,^\
             Waiting in a hot tureen!^\
             Who for such dainties would not stoop?^\
             Soup of the evening, beautiful Soup!~^^\
             ~Chorus again!~ cries the Gryphon, and the Mock Turtle has
             just begun to repeat it, when a cry of ~THE TRIAL'S
             BEGINNING!~ is heard in the distance.^^~Come on!~ cries the
             Gryphon, and, taking you by the hand, it makes to hurry
             off without waiting for the end of the song. (FOLLOW it --
             or simply run!)";
        default:
            return CourtRun();
    }
];

[ LedgeSay;
    if (quiz_open && (ledge_stage == 4 || ledge_stage == 5)) {
        if (TopicHas('holiday')) {
            quiz_open = 0;
            ledge_stage = 5;
            Achieved(T_HOLIDAY);
            "~A holiday,~ you say: ~for after the one-hour day there
             would be none at all, and no lessons is a holiday wherever
             it happens.~ The Gryphon sits back. ~Of course it was,~ it
             says, in the tone of an examiner robbed of his disappointment.
             ~You may be a little girl after all, whatever the pigeons
             say.~ ~And how did you manage on the twelfth?~ you ask
             eagerly. ~That's enough about lessons,~ the Gryphon
             interrupts in a very decided tone: ~tell her something about
             the games now.~ (The Mock Turtle is already drawing breath.)";
        }
        "~Hjckrrh!~ says the Gryphon, which is Gryphon for `wrong'. ~Ten,
         nine, eight, seven,~ it prompts, with terrible patience. ~By the
         tenth day, one hour; and the day after THAT, Miss?~ (A day of no
         lessons at all has a name. SAY it.)";
    }
    if (ledge_stage == 9) return CourtRun();
    "The Gryphon and the Mock Turtle receive your remark in silence, and
     go on with the programme.";
];

[ QuadrilleBeat;
    if (ledge_stage == 6) {
        ledge_stage = 7;
        "So they begin solemnly dancing round and round you, every now
         and then treading on your toes when they pass too close, and
         waving their forepaws to mark the time, while the Mock Turtle
         sings, very slowly and sadly:--^^\
         ~Will you walk a little faster? said a whiting to a snail,^\
         There's a porpoise close behind us, and he's treading on my
         tail...^\
         Will you, won't you, will you, won't you, will you join the
         dance?^\
         Will you, won't you, will you, won't you, won't you join the
         dance?~^^\
         (Well -- WILL you? You might JOIN IN.)";
    }
    ledge_stage = 8;
    "The dance winds down: the two creatures, who have been jumping about
     like mad things, sit down again very sadly and quietly, and look at
     you. ~It must be a very pretty dance,~ you say timidly; and, because
     it seems expected, you stand up and RECITE when ordered -- ~'Tis the
     voice of the sluggard~ -- except that the words come very queer
     indeed: ~'Tis the voice of the LOBSTER; I heard him declare, You
     have baked me too brown, I must sugar my hair...~ ~That's different
     from what I used to say when I was a child,~ says the Gryphon.
     ~Well, I never heard it before,~ says the Mock Turtle; ~but it
     sounds uncommon nonsense.~ (One more song is plainly coming: the
     Mock Turtle has his tureen face on.)";
];

[ JoinQuadrille;
    if (location ~= RockyLedge || ledge_stage < 6)
        "There is no dance going forward just here.";
    if (ledge_stage > 7)
        "The dance is over, and your toes are glad of it.";
    if (task_done->T_DANCE == 0) {
        Achieved(T_DANCE);
        ledge_stage = 8;
        "You join the first figure of the Lobster Quadrille: you advance
         twice (without a lobster, as they are in short supply), set to
         partners, change imaginary lobsters, and retire in same order;
         and if the Gryphon treads on your toes at the turn, and the
         Mock Turtle weeps down your collar at the swing, it is still
         dancing, and you are still in it. The two creatures finish the
         figure and sit down very sadly and quietly. ~Thank you, it's a
         very interesting dance to watch,~ you pant -- ~to DO, I mean~;
         and, on being ordered, you stand up and recite ~'Tis the voice
         of the sluggard~, which arrives as ~'Tis the voice of the
         Lobster~, every word of it queer. ~It sounds uncommon
         nonsense,~ says the Mock Turtle gravely. (He is drawing the
         long breath that means one more song.)";
    }
    "You have danced your figure.";
];

[ LedgeRecite;
    if (ledge_stage == 7) return QuadrilleBeat();
    if (ledge_stage == 8)
        "You have recited, and it came out all Lobster; there is no
         mending it by repetition.";
    "There is nothing you have been asked to recite just now, and
     volunteers are not called for.";
];

[ CourtRun;
    chapter = 11;
    print "~Come on!~ cries the Gryphon, and it runs the faster, while
        more and more faintly comes, carried on the breeze that follows
        you, the melancholy words: ~Soo--oop of the e--e--evening,
        beautiful, beautiful Soup!~^^You arrive quite out of breath --^";
    remove ledge_gryphon;
    PlayerTo(Courtroom);
    rtrue;
];

! ==========================================================================
!   CHAPTERS XI-XII -- the trial
! ==========================================================================

Object Courtroom "The Court of Justice"
  with description [;
           print "The King and Queen of Hearts are seated on their
               throne, with a great crowd assembled about them -- all
               sorts of little birds and beasts, as well as the whole
               pack of cards: the Knave is standing before them, in
               chains, with a soldier on each side to guard him; and near
               the King is the White Rabbit, with a trumpet in one hand
               and a scroll of parchment in the other. In the very middle
               of the court is a table, with a large dish of tarts upon
               it: they look so good that it makes you quite hungry just
               to see them. ";
           print "The jury-box holds twelve creatures";
           if (jury_up == 0 && court_stage >= 8)
               print " -- or held them, before you upset it";
           print ", all writing very busily on slates.";
           new_line;
       ],
       cant_go
           "You have never been in a court of justice before, and you
            mean to see it through: there is no leaving in the middle of
            a trial, particularly one you are shortly to be part of.",
  has  light;

Object -> court_king "King of Hearts"
  with name 'king' 'judge' 'wig',
       description
           "The King is the judge -- you can tell by his great wig; he
            wears his crown over it, and does not look at all comfortable,
            and it is certainly not becoming.",
       life [;
           Ask, Tell, Answer: return CourtSay();
       ],
  has  animate;

Object -> court_queen "Queen of Hearts"
  with name 'queen' 'majesty',
       description
           "The Queen of Hearts, glaring about the court with spectacles
            on, in the manner of a person choosing.",
       life [;
           Ask, Tell, Answer: return CourtSay();
           Attack: "Not even now.";
       ],
  has  animate female;

Object -> court_rabbit "White Rabbit"
  with name 'white' 'rabbit' 'herald' 'trumpet' 'scroll' 'parchment',
       description
           "The White Rabbit, in his glory at last: a trumpet in one
            hand, a scroll of parchment in the other, and a voice of
            office.",
       life [;
           Ask, Tell, Answer:
               "~Silence in the court!~ cries the White Rabbit, in a
                general way, and hurries on with the programme.";
       ],
  has  animate;

Object -> court_knave "Knave of Hearts"
  with name 'knave' 'prisoner',
       description
           "The Knave of Hearts, standing before the throne in chains,
            with a soldier on each side to guard him, and looking (it
            must be said) like a person who could not lift a dish of
            tarts, being made entirely of cardboard.",
       life [;
           Ask, Tell, Answer:
               "~Please your Majesty,~ says the Knave, to the room in
                general, ~I didn't write it, and they can't prove I did.~
                He is saving it up, evidently.";
       ],
  has  animate;

Object -> court_tarts "dish of tarts"
  with name 'tarts' 'tart' 'dish' 'table',
       description
           "A large dish of tarts, in the very middle of the court. They
            look so good that it makes you quite hungry to look at them
            -- ~I wish they'd get the trial done,~ you think, ~and hand
            round the refreshments!~",
       before [;
           Take, Eat: "They are the evidence. Eating the evidence, in
               full view of the court, is more boldness than even you
               have arrived at.";
       ],
  has  static;

Object -> court_jurybox "jury-box"
  with name 'jury-box' 'box' 'jurybox',
       description [;
           if (court_stage >= 8 && jury_up == 0)
               "The jury-box lies tipped over on its side, quite empty,
                its late occupants sprawling on the crowd below.";
           "A high box with twelve places in it, for twelve creatures
            and their slates.";
       ],
       before [;
           Receive:
               if (court_stage >= 8 && jury_up == 0) return JuryBack();
               "The box is fully occupied by the jury, such as it is.";
       ],
  has  container open static;

Object -> court_jurors "twelve jurors"
  with name 'jurors' 'jury' 'jurymen' 'juror' 'creatures' 'twelve'
            'slates' 'slate',
       description [;
           if (court_stage >= 8 && jury_up == 0)
               "The twelve jurors are sprawling about on the heads of
                the crowd below, reminding you very much of a globe of
                goldfish you accidentally upset the week before. They
                must be collected at once and put back, or they will
                die.";
           "Twelve creatures -- you are obliged to say `creatures',
            because some of them are animals and some are birds -- all
            writing very busily on slates. (They are putting down their
            names, the Gryphon whispered once, for fear they should
            forget them before the end of the trial.)";
       ],
       before [;
           Take:
               if (court_stage >= 8 && jury_up == 0) return JuryBack();
               "The jury is in session, more or less.";
           Insert:
               if (court_stage >= 8 && jury_up == 0) return JuryBack();
       ],
  has  animate;

Object -> court_bill "Bill the Lizard"
  with name 'bill' 'lizard',
       description [;
           if (court_stage >= 8 && jury_up == 1 && lizard_righted == 0)
               "Bill the Lizard, replaced in the jury-box in your haste
                HEAD DOWNWARDS: the poor little thing is waving its tail
                about in a melancholy way, being quite unable to move.";
           if (pencil_taken)
               "Bill the Lizard, juror, writing with one finger, which
                leaves no mark on the slate and is exactly as useful as
                his testimony.";
           "Bill the Lizard, in the jury-box, writing very busily with a
            pencil that SQUEAKS.";
       ],
       before [;
           Turn, Push, Pull:
               return RightTheLizard();
       ],
       life [;
           Ask, Tell, Answer:
               "Bill looks at you with the expression of a lizard who has
                been down a chimney and expects little from acquaintance
                renewed.";
       ],
  has  animate;

Object -> squeaky_pencil "squeaking pencil"
  with name 'squeaking' 'squeaky' 'pencil',
       description
           "A slate-pencil in Bill's grip, producing a squeak with every
            letter of his name (he is not sure of the spelling, and is
            asking his neighbour).",
       before [;
           Take:
               if (pencil_taken) "You have it already, and blessed
                   silence with it.";
               if (court_stage >= 7)
                   "The court is looking at you now: the moment for
                    quiet pencil-collecting has gone by.";
               pencil_taken = 1;
               Achieved(T_PENCIL);
               move squeaky_pencil to player;
               "This of course you cannot stand: you go round the court
                and get behind him, and very soon find an opportunity of
                taking it away. You do it so quickly that the poor little
                juror cannot make out at all what has become of it; so,
                after hunting all about, he is obliged to write with one
                finger for the rest of the day -- of very little use, as
                it leaves no mark on the slate.";
       ];

[ RightTheLizard;
    if (court_stage < 8 || jury_up == 0)
        "Bill is no more upside down than the rest of the court, for the
         moment.";
    if (lizard_righted) "Bill is right way up, for whatever difference it
        makes to his usefulness.";
    lizard_righted = 1;
    Achieved(T_LIZARD);
    court_stage = 9;
    "You pull the Lizard out again and put it in right way up; ~not that
     it signifies much,~ you say to yourself; ~I should think it would be
     QUITE as much use in the trial one way up as the other.~^^As soon as
     the jury have a little recovered from the shock of being upset, and
     their slates and pencils have been found and handed back to them,
     they set to work very diligently to write out a history of the
     accident -- all except the Lizard, who seems too much overcome to do
     anything but sit with its mouth open, gazing up into the roof of the
     court.^^~What do you know about this business?~ the King says to
     you. (Well -- what DO you know? SAY it.)";
];

[ JuryBack;
    if (jury_up) "The jurors are back in their box.";
    jury_up = 1;
    "~Oh, I BEG your pardon!~ you exclaim in a tone of great dismay, and
     you begin picking them up again as quickly as you can, for the
     accident of the goldfish keeps running in your head, and you have a
     vague sort of idea that they must be collected at once and put back
     into the jury-box, or they will die. ~The trial cannot proceed,~
     says the King in a very grave voice, ~until all the jurymen are back
     in their proper places -- ALL,~ he repeats with great emphasis,
     looking hard at you as he says so.^^You look at the jury-box, and
     see that in your haste you have put the Lizard in HEAD DOWNWARDS:
     the poor little thing is waving its tail about in a melancholy way,
     being quite unable to move. (You had better TURN THE LIZARD right
     way up.)";
];

[ CourtSay;
    switch (court_stage) {
        7:  if (TopicHas('here') || TopicHas('present') || TopicHas('me')) {
                court_stage = 8;
                "~HERE!~ you cry, quite forgetting in the flurry of the
                 moment how large you have grown in the last few minutes;
                 and you jump up in such a hurry that you tip over the
                 jury-box with the edge of your skirt, upsetting all the
                 jurymen on to the heads of the crowd below, and there
                 they lie sprawling about, reminding you very much of a
                 globe of goldfish you accidentally upset the week
                 before. (Pick them up! PUT THE JURORS BACK IN THE BOX!)";
            }
            "The White Rabbit reads out again, at the top of his shrill
             little voice, the name ~ALICE!~ (That is you. SAY HERE --
             and stand up.)";
        9:  if (TopicHas('nothing')) {
                court_stage = 10;
                "~Nothing,~ you say. ~Nothing WHATEVER?~ persists the
                 King. ~Nothing whatever,~ you say. ~That's very
                 important,~ the King says, turning to the jury. They are
                 just beginning to write this down on their slates, when
                 the White Rabbit interrupts: ~UNimportant, your Majesty
                 means, of course,~ he says in a very respectful tone,
                 but frowning and making faces at him as he speaks.
                 ~UNimportant, of course, I meant,~ the King hastily
                 says, and goes on to himself in an undertone,
                 ~important -- unimportant -- unimportant -- important
                 --~ as if he were trying which word sounded best.";
            }
            "~What do you know about this business?~ the King repeats.
             (The truthful answer, and the safest, is NOTHING. Say it.)";
        11: if (TopicHas('nonsense') || TopicHas('stuff')) {
                court_stage = 12;
                Achieved(T_NONSENSE);   ! harmless if already done
                "~Stuff and nonsense!~ you say loudly. ~The idea of
                 having the sentence first!~ ~Hold your tongue!~ says the
                 Queen, turning purple. ~I won't!~ you say. ~OFF WITH HER
                 HEAD!~ the Queen shouts at the top of her voice. Nobody
                 moves.^^(You have grown to your full size again, you
                 notice. Who cares for them, after all? What are they,
                 the whole pack of them? You know the words. SAY them.)";
            }
            "~Sentence first -- verdict afterwards,~ the Queen repeats,
             with relish. (That is nonsense, and worse than nonsense --
             STUFF AND NONSENSE, in fact, and you might say so out
             loud.)";
        12: if (TopicHas('pack') || TopicHas('cards')) {
                return TheFinale();
            }
            "The pack of cards is all round you, and the Queen is
             drawing breath for another sentence. (Say it: they're
             nothing but A PACK OF CARDS!)";
        default:
            "~Silence in the court!~ cries the White Rabbit. The
             proceedings, such as they are, proceed.";
    }
];

[ TheFinale;
    Achieved(T_CARDS);
    print "~Who cares for YOU?~ you say (you have grown to your full size
        by now). ~You're nothing but a pack of cards!~^^At this the whole
        pack rises up into the air, and comes flying down upon you: you
        give a little scream, half of fright and half of anger, and try
        to beat them off -- and find yourself lying on the bank, with
        your head in the lap of your sister, who is gently brushing away
        some dead leaves that have fluttered down from the trees upon
        your face.^^~Wake up, Alice dear!~ says your sister. ~Why, what a
        long sleep you've had!~^^~Oh, I've had SUCH a curious dream!~ you
        say; and you tell your sister, as well as you can remember them,
        all these strange Adventures of yours that you have just been
        reading about; and when you have finished, your sister kisses
        you, and says, ~It WAS a curious dream, dear, certainly: but now
        run in to your tea; it's getting late.~ So you get up and run
        off, thinking while you run, as well you may, what a wonderful
        dream it has been.^^But your sister sits still just as you leave
        her, watching the setting sun and thinking of little Alice and
        all her wonderful Adventures; and how this same little Alice
        would, in the after-time, keep, through all her riper years, the
        simple and loving heart of her childhood; and gather about her
        other little children, and make THEIR eyes bright and eager with
        many a strange tale, perhaps even with the dream of Wonderland
        of long ago.^";
    deadflag = 2;
    rtrue;
];

Object CourtScene "(court scene)"
  with daemon [;
           if (location ~= Courtroom) rfalse;
           switch (court_stage) {
               0:  court_stage = 1;
                   "^~Silence in the court!~ cries the White Rabbit. You
                    have never been in a court of justice before, but you
                    have read about them in books, and you are quite
                    pleased to find that you know the name of nearly
                    everything here. ~That's the judge,~ you say to
                    yourself, ~because of his great wig.~ The twelve
                    jurors are all writing very busily on slates --
                    putting down their names, for fear they should forget
                    them before the end of the trial. One of the pencils
                    SQUEAKS: it is Bill the Lizard's, and this, of
                    course, you cannot stand. (Not while it can be quietly
                    TAKEN, anyhow.)";
               1:  court_stage = 2;
                   "^The White Rabbit blows three blasts on the trumpet,
                    unrolls the parchment scroll, and reads:--^^\
                    ~The Queen of Hearts, she made some tarts,^\
                    All on a summer day:^\
                    The Knave of Hearts, he stole those tarts,^\
                    And took them quite away!~^^\
                    ~Consider your verdict,~ the King says to the jury.
                    ~Not yet, not yet!~ the Rabbit hastily interrupts.
                    ~There's a great deal to come before that!~";
               2:  court_stage = 3;
                   "^~Call the first witness,~ says the King; and the
                    White Rabbit blows three blasts on the trumpet, and
                    calls out, ~First witness!~^^The first witness is the
                    Hatter. He comes in with a teacup in one hand and a
                    piece of bread-and-butter in the other. ~I beg
                    pardon, your Majesty,~ he begins, ~for bringing these
                    in: but I hadn't quite finished my tea when I was
                    sent for.~ ~You ought to have finished,~ says the
                    King. ~When did you begin?~ The Hatter looks at the
                    March Hare, who has followed him into the court,
                    arm-in-arm with the Dormouse. ~Fourteenth of March, I
                    THINK it was,~ he says. ~Fifteenth,~ says the March
                    Hare. ~Sixteenth,~ adds the Dormouse. ~Write that
                    down,~ the King says to the jury; and the jury
                    eagerly write down all three dates on their slates,
                    and then add them up, and reduce the answer to
                    shillings and pence.";
               3:  court_stage = 4;
                   "^~Give your evidence,~ says the King; ~and don't be
                    nervous, or I'll have you executed on the spot.~ This
                    does not seem to encourage the witness at all: he
                    keeps shifting from one foot to the other, looking
                    uneasily at the Queen, and in his confusion he bites
                    a large piece out of his teacup instead of the
                    bread-and-butter.^^Just at this moment you feel a
                    very curious sensation, which puzzles you a good deal
                    until you make out what it is: you are beginning to
                    grow larger again. You think at first you will get up
                    and leave the court; but on second thoughts you
                    decide to remain where you are as long as there is
                    room for you.";
               4:  court_stage = 5;
                   alice_size = 3;
                   "^~I wish you wouldn't squeeze so,~ says the Dormouse,
                    who is sitting next to you. ~I can hardly breathe.~
                    ~I can't help it,~ you say very meekly: ~I'm
                    growing.~ ~You've no right to grow HERE,~ says the
                    Dormouse. ~Don't talk nonsense,~ you say more boldly:
                    ~you know you're growing too.~ ~Yes, but I grow at a
                    reasonable pace,~ says the Dormouse, ~not in that
                    ridiculous fashion.~ And he gets up very sulkily and
                    crosses over to the other side of the court.";
               5:  court_stage = 6;
                   "^The Hatter's evidence establishes that the twinkling
                    began with the tea (~Of course twinkling begins with
                    a T!~ says the King sharply: ~do you take me for a
                    dunce? Go on!~), that the March Hare denies
                    everything, and that the Dormouse said something the
                    Hatter cannot remember and must remember or be
                    executed. At last the King says, ~If that's all you
                    know about it, you may stand down.~ ~I can't go no
                    lower,~ says the Hatter: ~I'm on the floor, as it
                    is.~ ~Then you may SIT down,~ the King replies. ~I'd
                    rather finish my tea,~ says the Hatter, with an
                    anxious look at the Queen; and he hurries out of the
                    court without even waiting to put his shoes on --
                    ~and just take his head off outside,~ the Queen adds
                    to one of the officers: but the Hatter is out of
                    sight before the officer can get to the door.";
               6:  court_stage = 7;
                   "^~Call the next witness!~ says the King. The next
                    witness is the Duchess's cook, pepper-box in hand;
                    you guess who it is even before she gets into the
                    court, by the way the people near the door begin
                    sneezing all at once. ~Give your evidence,~ says the
                    King. ~Shan't,~ says the cook. The King looks
                    anxiously at the White Rabbit, who says in a low
                    voice, ~Your Majesty must cross-examine THIS
                    witness.~ ~Well, if I must, I must,~ the King says,
                    and after folding his arms and frowning at the cook
                    till his eyes are nearly out of sight, he says in a
                    deep voice, ~What are tarts made of?~ ~Pepper,
                    mostly,~ says the cook. ~Treacle,~ says a sleepy
                    voice behind her. ~Collar that Dormouse!~ the Queen
                    shrieks out. ~Behead that Dormouse! Turn that
                    Dormouse out of court! Suppress him! Pinch him! Off
                    with his whiskers!~ For some minutes the whole court
                    is in confusion, and by the time they have settled
                    down again, the cook has disappeared.^^~Never mind!~
                    says the King, with an air of great relief. ~Call the
                    next witness.~ You watch the White Rabbit as he
                    fumbles over the list, feeling very curious to see
                    what the next witness will be like -- and imagine
                    your surprise when he reads out, at the top of his
                    shrill little voice, the name: ~ALICE!~";
               7, 9, 11, 12:
                   court_nudge++;
                   if (court_nudge >= 2) {
                       court_nudge = 0;
                       switch (court_stage) {
                           7: "^~ALICE!~ the White Rabbit repeats,
                               shriller still. Every eye in the court has
                               found you. (SAY HERE!)";
                           9: "^~What do you know about this business?~
                               the King asks again, with the patience of
                               a judge who has nowhere else to be. (Say
                               NOTHING -- it is the exact truth.)";
                           11: "^~Sentence first -- verdict afterwards,~
                               says the Queen again, savouring it. (STUFF
                               AND NONSENSE! -- say it out loud.)";
                           12: "^The cards are rising about you like a
                               red-and-white weather. (Say it! ~You're
                               nothing but A PACK OF CARDS!~)";
                       }
                   }
               8:  if (jury_up == 0) {
                       court_nudge++;
                       if (court_nudge >= 2) {
                           court_nudge = 0;
                           "^The jurymen lie sprawling about on the heads
                            of the crowd, wriggling. ~The trial cannot
                            proceed,~ the King repeats gravely, ~until
                            ALL the jurymen are back in their proper
                            places.~ (PUT THE JURORS IN THE BOX.)";
                       }
                   }
               10: court_stage = 11;
                   "^~There's more evidence to come yet, please your
                    Majesty,~ says the White Rabbit, jumping up in a
                    great hurry: ~this paper has just been picked up. It
                    seems to be a letter, written by the prisoner to --
                    to somebody.~ He unfolds it as he speaks, and adds,
                    ~It isn't a letter, after all: it's a set of verses
                    -- and they're not in the prisoner's handwriting,
                    which is the queerest thing about it.~ ~He must have
                    imitated somebody else's hand,~ says the King. (The
                    jury all brighten up again.) ~Please your Majesty,~
                    says the Knave, ~I didn't write it, and they can't
                    prove I did: there's no name signed at the end.~ ~If
                    you didn't sign it,~ says the King, ~that only makes
                    the matter worse. You MUST have meant some mischief,
                    or else you'd have signed your name like an honest
                    man.~ There is a general clapping of hands at this:
                    it is the first really clever thing the King has said
                    that day.^^The White Rabbit puts on his spectacles
                    and reads the verses -- ~They told me you had been to
                    her, and mentioned me to him: she gave me a good
                    character, but said I could not swim...~ -- and the
                    King rubs his hands and finds meaning after meaning
                    in them (~`--said I could not swim--' you can't swim,
                    can YOU?~ he asks the Knave, who is made entirely of
                    cardboard and does not look like it); until at last
                    he says, for about the twentieth time that day, ~Let
                    the jury consider their verdict.~^^~No, no!~ says the
                    Queen. ~Sentence first -- verdict afterwards.~ (Well!
                    Of all the-- You know what that is. Say NONSENSE --
                    stuff and nonsense!)";
               default: rfalse;
           }
           rfalse;
       ];

! Answering / standing when called: STAND also works at stage 7.
[ CourtStand;
    if (court_stage == 7) {
        court_stage = 8;
        "~HERE!~ you cry, jumping up in such a hurry that you tip over
         the jury-box with the edge of your skirt, upsetting all the
         jurymen on to the heads of the crowd below, and there they lie
         sprawling about, reminding you very much of a globe of goldfish
         you accidentally upset the week before. (Pick them up! PUT THE
         JURORS BACK IN THE BOX!)";
    }
    rfalse;
];
