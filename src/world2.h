! ==========================================================================
!   world2.h -- Chapters V-VII:
!   the Caterpillar and the mushroom, the serpent among the tree-tops,
!   Pig and Pepper, the Cheshire Cat, and the Mad Tea-Party.
! ==========================================================================

Global cat_stage = 0;         ! caterpillar conversation
Global cat_temper = 0;        ! how much you have offended him
Global cat_gone = 0;
Global got_bits = 0;
Global pigeon_stage = 0;
Global fish_scene = 0;        ! the footmen
Global kitchen_beats = 0;
Global baby_knotted = 0;
Global baby_wriggles = 0;
Global baby_outside = 0;      ! turns carried in the open air
Global cheshire_stage = 0;
Global tea_seated = 0;
Global tea_beats = 0;
Global riddle_open = 0;
Global riddle_given_up = 0;
Global story_stage = 0;       ! the Dormouse's story: 0 none, 1 begun, 2 done
Global moved_round = 0;
Global had_tea = 0;
Global fed_up = 0;
Global tree_door_visible = 0;

! ==========================================================================
!   CHAPTER V -- Advice from a Caterpillar
! ==========================================================================

Object Clearing "Mushroom Clearing"
  with description [;
           print "A quiet clearing in the wood. Near you grows a large
               mushroom, about the same height as yourself";
           if (alice_size > 0)
               print " when you first came this way, which is to say,
                   three inches or so";
           print ".";
           if (Caterpillar in self)
               print " On the top of it -- you found this out by standing
                   on tiptoe and peeping over the edge -- sits a large
                   blue caterpillar, its arms folded, quietly smoking a
                   long hookah, and taking not the smallest notice of you
                   or of anything else.";
           print " The wood opens southward on a broad open place; the
               way back north is full of puppy.";
           new_line;
       ],
       s_to [;
           if (alice_size >= 2)
               "As you go you come suddenly on an open place with a little
                house in it, about four feet high. ~Whoever lives there,~
                you think, ~it'll never do to come upon them THIS size:
                why, I should frighten them out of their wits!~ You draw
                back into the clearing. (A nibble of the right-hand bit
                would mend matters.)";
           if (alice_size == 0)
               "Grass and fallen twigs bar the way like a forest inside
                the forest: three inches is too few for this journey. (A
                nibble of the left-hand bit would help.)";
           chapter = 6;
           return OpenPlace;
       ],
       n_to "You have no wish to reopen negotiations with the puppy.",
  has  light;

Object -> big_mushroom "large mushroom"
  with name 'large' 'mushroom' 'top' 'edge' 'stalk',
       description [;
           if (Caterpillar in Clearing)
               "As tall as you were when you arrived, and perfectly round;
                and on the top of it sits the Caterpillar, like a
                householder on his own roof.";
           if (got_bits)
               "Perfectly round, and lately nibbled at two opposite edges
                by somebody with a bit in each hand.";
           "A large mushroom, perfectly round. The Caterpillar said that
            one side will make you grow taller, and the other side
            shorter -- but as it is perfectly round, which are the two
            sides of it? You could stretch your arms round it as far as
            they would go, and break off a bit of the edge with each
            hand.";
       ],
       before [;
           Take, Pull, Attack:
               return TakeMushroomBits();
           Climb:
               if (Caterpillar in Clearing)
                   "The top is occupied, and the occupant does not look
                    like a person who shares roofs.";
               "You scramble a little way up the stalk and slide down
                again. The edge is the useful part, anyhow.";
           Eat, Taste:
               return TakeMushroomBits();
           Search, LookUnder:
               "You look under it, and on both sides of it, and behind it;
                and it occurs to you that you might as well look and see
                what is on the top of it.";
       ],
  has  static;

[ TakeMushroomBits;
    if (Caterpillar in Clearing)
        "The Caterpillar is sitting on it. One does not carve a
         gentleman's house while the gentleman is at home -- particularly
         a gentleman so easily offended.";
    if (got_bits)
        "You have a bit from each edge already, one for each hand; and the
         mushroom, for its part, has settled back into being perfectly
         round, as if nothing had ever been broken off it at all.";
    got_bits = 1;
    move right_bit to player;
    move left_bit to player;
    "You look at the mushroom thoughtfully for a minute, trying to make
     out which are the two sides of it; and as it is perfectly round, you
     find this a very difficult question. At last you stretch your arms
     round it as far as they will go, and break off a bit of the edge
     with each hand: a right-hand bit, and a left-hand bit. ~And now
     which is which?~ is a question for careful nibbling.";
];

Object -> Caterpillar "Caterpillar"
  with name 'caterpillar' 'blue' 'hookah',
       description
           "A large blue caterpillar, exactly three inches high, sitting
            on the top of the mushroom with its arms folded, quietly
            smoking a long hookah. Its expression is that of a person who
            has been contradicted once, long ago, and has never got over
            it.",
       life [;
           Ask, Tell, Answer:
               return CaterpillarTalk();
           Attack:
               cat_temper = cat_temper + 2;
               "You cannot bring yourself to actually strike a gentleman
                three inches high; the gesture alone makes him rear up
                like an offended question-mark. This has not improved
                relations.";
           Kiss: "Certainly not. You have only just been introduced, if
               staring counts as introduction.";
           Show, Give:
               "The Caterpillar looks at it, and then at you, and says
                nothing with tremendous fluency.";
       ],
  has  animate;

[ CaterpillarTalk;
    switch (cat_stage) {
        0:  cat_stage = 1;
            "~Who are YOU?~ says the Caterpillar, in a languid, sleepy
             voice. This is not an encouraging opening for a
             conversation. ~I -- I hardly know, sir, just at present,~
             you reply, rather shyly: ~at least I know who I WAS when I
             got up this morning, but I think I must have been changed
             several times since then.~^^~What do you mean by that?~ says
             the Caterpillar sternly. ~Explain yourself!~";
        1:  cat_stage = 2;
            "~I can't explain MYSELF, I'm afraid, sir,~ you say, ~because
             I'm not myself, you see.~ ~I don't see,~ says the
             Caterpillar. ~I'm afraid I can't put it more clearly,~ you
             reply very politely, ~for I can't understand it myself to
             begin with; and being so many different sizes in a day is
             very confusing.~ ~It isn't,~ says the Caterpillar.^^You have
             never been so much contradicted in your life, and you feel
             that you are losing your temper. (Keep it. He is worth the
             patience, you are nearly sure.)";
        2:  cat_stage = 3;
            "~Who are YOU?~ says the Caterpillar contemptuously, which
             brings you back again to the beginning of the conversation.
             You draw yourself up and say, very gravely, ~I think you
             ought to tell me who YOU are, first.~ ~Why?~ says the
             Caterpillar.^^Here is another puzzling question, and as you
             cannot think of any good reason, you very nearly turn away.
             ~Come back!~ the Caterpillar calls. ~I've something
             important to say!~ This sounds promising, certainly. ~Keep
             your temper,~ says the Caterpillar. ~Is that all?~ you say,
             swallowing down your anger as well as you can. ~No,~ says
             the Caterpillar.";
        3:  cat_stage = 4;
            "For some minutes it puffs away without speaking; at last it
             unfolds its arms, takes the hookah out of its mouth, and
             says, ~So you think you're changed, do you?~ ~I'm afraid I
             am, sir,~ you say; ~I can't remember things as I used -- and
             I don't keep the same size for ten minutes together!~
             ~Can't remember WHAT things?~ says the Caterpillar. ~Well,
             I've tried to say `How doth the little busy bee,' but it all
             came different!~ you reply, in a very melancholy voice.^^\
             ~Repeat `YOU ARE OLD, FATHER WILLIAM,'~ says the
             Caterpillar. (You had better RECITE it.)";
        4:  "The Caterpillar waits, hookah poised. It has asked you to
             repeat ~You are old, Father William~, and it is not a
             creature that asks twice. (RECITE.)";
        5:  cat_stage = 6;
            CaterpillarLeaves();
            rtrue;
        default:
            "The Caterpillar has said all it means to say, which was
             never much at a time.";
    }
];

[ CaterpillarRecite;
    if (cat_stage < 4)
        "You fold your hands and open your mouth, but the Caterpillar has
         not asked for anything yet; and reciting uninvited, to a
         stranger, on a mushroom, is not how you were brought up.";
    if (cat_stage > 4) "Once was quite enough for both of you.";
    cat_stage = 5;
    "You fold your hands and begin:--^^\
     ~You are old, Father William, the young man said,^\
     And your hair has become very white;^\
     And yet you incessantly stand on your head --^\
     Do you think, at your age, it is right?~^^\
     ~In my youth, Father William replied to his son,^\
     I feared it might injure the brain;^\
     But, now that I'm perfectly sure I have none,^\
     Why, I do it again and again.~^^\
     ...and so on, through the back-somersault, the ointment (one
     shilling the box), the goose finished bones and beak, and the eel
     balanced on the end of his nose; and it is all wrong, and you know
     it.^^~That is not said right,~ says the Caterpillar. ~Not QUITE
     right, I'm afraid,~ you say, timidly: ~some of the words have got
     altered.~ ~It is wrong from beginning to end,~ says the Caterpillar
     decidedly, and there is silence for some minutes. Then: ~What SIZE
     do you want to be?~ (A civil answer -- ANY answer -- seems wanted.)";
];

[ CaterpillarLeaves;
    cat_gone = 1;
    remove Caterpillar;
    print "~Oh, I'm not particular as to size,~ you reply hastily; ~only
        one doesn't like changing so often, you know.~ ~I DON'T know,~
        says the Caterpillar. You say nothing: you have never been so
        much contradicted in all your life. ~Are you content NOW?~ says
        the Caterpillar. ~Well, I should like to be a LITTLE larger,
        sir, if you wouldn't mind,~ you say: ~three inches is such a
        wretched height to be.~ ~It is a very good height indeed!~ says
        the Caterpillar angrily, rearing itself upright as it speaks (it
        is exactly three inches high).^^In a minute or two it takes the
        hookah out of its mouth, yawns once or twice, and shakes itself.
        Then it gets down off the mushroom and crawls away into the
        grass";
    if (cat_temper < 2) {
        Achieved(T_TEMPER);
        ", merely remarking as it goes: ~One side will make you grow
         taller, and the other side will make you grow shorter.~^^~One
         side of WHAT? The other side of WHAT?~ you think. ~Of the
         mushroom,~ says the Caterpillar, just as if you had asked it
         aloud; and in another moment it is out of sight. You kept your
         temper, and this is your reward: advice. It is more than most
         people get from a caterpillar.";
    }
    ", without one word more. You have contradicted it, or attacked it,
     or otherwise ruffled it, and whatever important thing it had to say
     about the mushroom has crawled away with it. The mushroom itself
     remains, however; and experiment, after all, is the honest way of
     finding anything out.";
];

[ ClearingSay;
    if (Caterpillar in Clearing) {
        if (TopicHas('stupid') || TopicHas('shut') || TopicHas('rude')
            || TopicHas('horrid')) {
            cat_temper = cat_temper + 2;
            "You say it -- you cannot afterwards believe you said it --
             and the Caterpillar receives it in a silence so complete
             that the hookah bubbles apologetically on its behalf. You
             feel this exchange has cost you something.";
        }
        return CaterpillarTalk();
    }
    "You say it to the clearing; the mushroom continues perfectly round.";
];

! --------------------------------------------------------------------------
! The serpent among the tree-tops: first left-hand nibble.
! --------------------------------------------------------------------------

[ NeckScene;
    neck_scene_done = 1;
    alice_size = 3;
    print "You nibble the left-hand bit. ~Come, my head's free at
        last!~ you say in a tone of delight -- which changes to alarm in
        another moment, when you find that your shoulders are nowhere to
        be found: all you can see, when you look down, is an immense
        length of neck, which seems to rise like a stalk out of a sea of
        green leaves far below.^^~What CAN all that green stuff be?~ you
        say. ~And where HAVE my shoulders got to? And oh, my poor hands,
        how is it I can't see you?~ You find that your neck bends about
        easily in any direction, like a serpent, and you curve it down
        gracefully into the leaves -- which prove to be nothing but the
        tops of the trees you were wandering under --^";
    PlayerTo(TreeTops);
    rtrue;
];

Object TreeTops "Among the Tree-Tops"
  with description
           "Your head is up among the tree-tops, at the end of a neck of
            which the less said the better; the rest of you is somewhere
            on the ground, keeping house. A large pigeon is beating at
            your face with its wings, in a state of high feeling.",
       before [;
           Eat:
               if (noun == right_bit) {
                   alice_size = 3;
                   chin_scene_done = 1;   ! no chin scene from up here
                   print "You crouch down among the trees as well as you
                       can, for your neck keeps getting entangled among
                       the branches, and every now and then you have to
                       stop and untwist it. After a while you remember
                       the pieces of mushroom in your hands, and you
                       nibble the right-hand bit, very carefully -- and
                       the immense neck telescopes graciously down
                       through the leaves, and the world reassembles
                       itself about you in nearly the usual order.^";
                   PlayerTo(Clearing);
                   rtrue;
               }
               if (noun == left_bit)
                   "Any more of the left-hand bit and you will be
                    overtopping the clouds, and the pigeons of the upper
                    air are probably no more reasonable than this one.";
       ],
       cant_go
           "One does not walk anywhere when one is mostly neck. The
            mushroom got you into this, and the mushroom (the right-hand
            bit of it) must get you out.",
  has  light;

Object -> the_pigeon "Pigeon"
  with name 'pigeon' 'large' 'bird',
       description
           "A large pigeon, guarding a nest, and firmly of the opinion
            that you are a serpent. Looking down the length of yourself,
            you cannot altogether blame it.",
       life [;
           Ask, Tell, Answer: return PigeonTalk();
           Attack: "You would not dream of it: the poor thing is only
               defending its eggs.";
       ],
  has  animate;

[ PigeonTalk;
    switch (pigeon_stage) {
        0:  pigeon_stage = 1;
            "~Serpent!~ screams the Pigeon. ~I'm NOT a serpent!~ you say
             indignantly. ~Let me alone!~ ~Serpent, I say again!~ repeats
             the Pigeon, but in a more subdued tone, and adds with a kind
             of sob, ~I've tried every way, and nothing seems to suit
             them! The roots of trees, and banks, and hedges -- but those
             serpents! There's no pleasing them! As if it wasn't trouble
             enough hatching the eggs, I must be on the look-out for
             serpents night and day! And just as I'd taken the highest
             tree in the wood, they must needs come wriggling down from
             the sky! Ugh, Serpent!~";
        1:  pigeon_stage = 2;
            "~But I'm NOT a serpent, I tell you!~ you say. ~I'm a -- I'm
             a --~ ~Well! WHAT are you?~ says the Pigeon. ~I can see
             you're trying to invent something!~ ~I -- I'm a little
             girl,~ you say, rather doubtfully, remembering the number of
             changes you have gone through today.^^~A likely story
             indeed!~ says the Pigeon, in a tone of the deepest contempt.
             ~I've seen a good many little girls in my time, but never ONE
             with such a neck as that! No, no! You're a serpent; and
             there's no use denying it. I suppose you'll be telling me
             next that you never tasted an egg!~";
        2:  pigeon_stage = 3;
            "~I HAVE tasted eggs, certainly,~ you say (you are a very
             truthful child); ~but little girls eat eggs quite as much as
             serpents do, you know.~ ~I don't believe it,~ says the
             Pigeon; ~but if they do, why then they're a kind of serpent,
             that's all I can say.~ This is such a new idea to you that
             you are quite silent for a minute or two. ~You're looking
             for eggs, I know THAT well enough,~ the Pigeon adds; ~and
             what does it matter to me whether you're a little girl or a
             serpent?~^^~It matters a good deal to ME,~ you say hastily;
             ~but I'm not looking for eggs, as it happens; and if I was,
             I shouldn't want YOURS: I don't like them raw.~ ~Well, be
             off, then!~ says the Pigeon in a sulky tone, settling down
             into its nest. (Be off, indeed: the right-hand bit of
             mushroom would take you down out of these branches.)";
        default:
            "~Be off, then!~ repeats the Pigeon, from deep in its nest.
             The conversation, such as it was, is over.";
    }
];

[ TreeTopsSay;
    if (TopicHas('girl') || TopicHas('alice') || TopicHas('serpent'))
        return PigeonTalk();
    "You say it, and the Pigeon takes it as further evidence of
     serpenthood: everything is, this afternoon.";
];

! ==========================================================================
!   CHAPTER VI -- Pig and Pepper
! ==========================================================================

Object OpenPlace "Open Place Before the Little House"
  with description [;
           print "An open place in the wood, with a little house in it
               about four feet high. ";
           if (frog_footman in self)
               print "The Frog-Footman sits on the ground near the door,
                   staring stupidly up into the sky. ";
           if (cheshire_stage >= 1 && cheshire_cat in self)
               print "On the bough of a tree a few yards off sits the
                   Cheshire Cat, grinning from ear to ear. ";
           print "The wood closes round on every side but two: the
               clearing lies back north, and a trodden way goes
               north-east, deeper among the trees.";
           new_line;
       ],
       n_to [;
           if (baby_pig in player || queer_baby in player)
               "Not with a baby (or whatever it is becoming) in your
                arms: the wood is no nursery.";
           return Clearing;
       ],
       ne_to [;
           if (baby_pig in player || queer_baby in player)
               "You can hardly go visiting with somebody else's baby --
                or somebody else's pig -- in your arms. Set it down
                first.";
           chapter = 7;
           return TeaPartyWood;
       ],
       in_to [; return EnterDuchessHouse(); ],
  has  light;

[ EnterDuchessHouse;
    if (alice_size >= 2)
        "The door is a little over three feet high, and you are a great
         deal over it. ~It'll never do to come upon them this size,~ you
         think. (The right-hand bit of mushroom knows its business.)";
    if (alice_size == 0)
        "At three inches, the doorstep alone is an afternoon's
         mountaineering. (A nibble of the left-hand bit first.)";
    if (fish_scene < 2)
        "The Frog-Footman is exactly in front of the door, and shows no
         sign of ever moving; it seems only civil to have it out with him
         first. (KNOCK, perhaps, or ask him how to get in.)";
    Achieved(T_HOUSE);
    print "~Oh, there's no use in talking to him,~ you say desperately:
        ~he's perfectly idiotic!~ And you open the door and go in.^";
    PlayerTo(PepperKitchen);
    rtrue;
];

Object -> duchess_house "little house"
  with name 'little' 'house' 'door' 'roof',
       description
           "A little house, about four feet high, with smoke coming out of
            the chimney and a most extraordinary noise going on within --
            a constant howling and sneezing, and every now and then a
            great crash, as if a dish or kettle had been broken to
            pieces.",
       before [;
           Enter, Open: return EnterDuchessHouse();
           Listen: "Howling, sneezing, and the crash of crockery: a
               domestic interior in full swing.";
       ],
  has  scenery;

Object -> frog_footman "Frog-Footman"
  with name 'frog' 'footman' 'frog-footman' 'livery',
       description
           "A footman in livery, with a round face and large eyes like a
            frog -- indeed, judging by his face only, you would have
            called him a frog at once. He has powdered hair that curls all
            over his head, and he is staring straight up into the sky.",
       life [;
           Ask, Tell, Answer: return FootmanTalk();
           Attack: "One does not strike a footman; one out-waits him, or
               fails to.";
           Kiss: "His face is the wrong shape for it, among other
               objections.";
       ],
  has  animate;

[ FootmanTalk;
    switch (fish_scene) {
        0, 1:
            fish_scene = 2;
            "~Please, then,~ you say, ~how am I to get in?~^^~There might
             be some sense in your knocking,~ the Footman goes on without
             attending to you, ~if we had the door between us. For
             instance, if you were INSIDE, you might knock, and I could
             let you out, you know.~ He looks up into the sky all the
             time he is speaking, which you think decidedly uncivil.
             ~But perhaps he can't help it,~ you say to yourself; ~his
             eyes are so VERY nearly at the top of his head.~ ~How am I
             to get in?~ you repeat, aloud. ~Are you to get in at all?~
             says the Footman. ~That's the first question, you know.~^^\
             At this moment the door of the house opens, and a large
             plate comes skimming out, straight at the Footman's head: it
             just grazes his nose, and breaks to pieces against one of
             the trees behind him. ~I shall sit here,~ the Footman
             remarks, ~-- or next day, maybe --~ exactly as if nothing
             had happened. (There is plainly nothing for it but to OPEN
             THE DOOR and walk in.)";
        default:
            "~I shall sit here,~ says the Footman, ~on and off, for days
             and days.~ ~But what am I to do?~ you say. ~Anything you
             like,~ says the Footman, and begins whistling. He is
             perfectly idiotic; the door, on the other hand, is merely a
             door. (OPEN it.)";
    }
];

[ DuchessKnock;
    if (fish_scene == 0) fish_scene = 1;
    "You go timidly up to the door and knock. ~There's no sort of use in
     knocking,~ says the Footman, ~and that for two reasons. First,
     because I'm on the same side of the door as you are; secondly,
     because they're making such a noise inside, no one could possibly
     hear you.~ And certainly there IS a most extraordinary noise going on
     within. (You might ask him how you ARE to get in, since he is so
     well provided with reasons.)";
];

Object OpenPlaceScene "(open place scene)"
  with daemon [;
           if (location ~= OpenPlace) rfalse;
           if (fish_scene == 0 && self hasnt general) {
               give self general;
               "^Suddenly a footman in livery comes running out of the
                wood (you consider him to be a footman because he is in
                livery: otherwise, judging by his face only, you would
                have called him a fish) and raps loudly at the door with
                his knuckles. It is opened by another footman in livery,
                with a round face and large eyes like a frog. The
                Fish-Footman produces from under his arm a great letter,
                nearly as large as himself, and hands it over, saying in
                a solemn tone, ~For the Duchess. An invitation from the
                Queen to play croquet.~ The Frog-Footman repeats, in the
                same solemn tone, only changing the order of the words a
                little, ~From the Queen. An invitation for the Duchess to
                play croquet.~^^Then they both bow low, and their curls
                get entangled together; and the Fish-Footman goes off the
                way he came, and the other sits down on the ground near
                the door, staring stupidly up into the sky.";
           }
           ! Carrying the baby in the open air:
           if (queer_baby in player) {
               baby_outside++;
               switch (baby_outside) {
                   1: "^The baby grunts. ~Don't grunt,~ you say; ~that's
                       not at all a proper way of expressing yourself.~
                       You look anxiously into its face: it has a VERY
                       turn-up nose, much more like a snout than a real
                       nose; also its eyes are getting extremely small
                       for a baby. Perhaps it was only sobbing? -- but
                       no, there are no tears. ~If you're going to turn
                       into a pig, my dear,~ you say seriously, ~I'll
                       have nothing more to do with you. Mind now!~";
                   2: BabyBecomesPig();
               }
           }
           rfalse;
       ];

[ BabyBecomesPig;
    remove queer_baby;
    move baby_pig to player;
    "^The creature grunts again, so violently that you look down into its
     face in some alarm. This time there can be NO mistake about it: it is
     neither more nor less than a pig, and you feel that it would be quite
     absurd for you to carry it further. (You had better SET IT DOWN.)";
];

Object baby_pig "small pig"
  with name 'pig' 'small' 'baby' 'creature',
       description
           "A small and self-possessed pig, lately a baby. The exchange,
            on the whole, is to its advantage.",
       before [;
           Drop, Transfer:
               remove self;
               cheshire_stage = 1;
               move cheshire_cat to OpenPlace;
               "You set the little creature down, and feel quite relieved
                to see it trot away quietly into the wood. ~If it had
                grown up,~ you say to yourself, ~it would have made a
                dreadfully ugly child: but it makes rather a handsome
                pig, I think.~ And you begin thinking over other children
                you know, who might do very well as pigs, when you notice
                the Cheshire Cat on the bough of a tree a few yards off.";
       ],
       life [;
           Ask, Tell, Answer: "It grunts, with perfect candour.";
       ],
  has  animate;

! --------------------------------------------------------------------------
! The peppery kitchen.
! --------------------------------------------------------------------------

Object PepperKitchen "The Duchess's Kitchen"
  with description [;
           print "A large kitchen, full of smoke from one end to the
               other";
           if (the_duchess in self)
               print ": the Duchess sits on a three-legged stool in the
                   middle, nursing a baby";
           print "; the cook leans over the fire, stirring a large
               cauldron which seems to be full of soup. There is far too
               much pepper in the air -- you can hardly speak for
               sneezing";
           if (kitchen_cat in self)
               print " -- and on the hearth sits a large cat, grinning
                   from ear to ear";
           print ". The door back to the open air is behind you.";
           new_line;
       ],
       out_to [;
           if (queer_baby in player) {
               print "You carry the queer little thing out into the open
                   air. ~If I don't take this child away with me,~ you
                   think, ~they're sure to kill it in a day or two:
                   wouldn't it be murder to leave it behind?~^";
               PlayerTo(OpenPlace);
               rtrue;
           }
           PlayerTo(OpenPlace);
           rtrue;
       ],
       cant_go "The kitchen has one door, and the kitchen's opinion is
           that one is plenty.",
  has  light;

Object -> the_duchess "Duchess"
  with name 'duchess',
       description
           "The Duchess: very ugly, with a chin quite sharp enough to be
            an implement, nursing (or at any rate shaking) a howling
            baby, and sneezing at intervals.",
       life [;
           Ask, Tell, Answer:
               if (second == 'cat' or 'cats' or 'grin' or 'cheshire') {
                   kitchen_beats++;
                   "~Please would you tell me,~ you say, a little timidly,
                    ~why your cat grins like that?~ ~It's a Cheshire
                    cat,~ says the Duchess, ~and that's why. Pig!~ She
                    says the last word with such sudden violence that you
                    quite jump; but you see in another moment that it is
                    addressed to the baby, and not to you, so you take
                    courage and go on: ~I didn't know that Cheshire cats
                    always grinned; in fact, I didn't know that cats
                    COULD grin.~ ~They all can,~ says the Duchess; ~and
                    most of 'em do.~ ~I don't know of any that do,~ you
                    say very politely. ~You don't know much,~ says the
                    Duchess; ~and that's a fact.~";
               }
               kitchen_beats++;
               "~If everybody minded their own business,~ the Duchess
                says in a hoarse growl, ~the world would go round a deal
                faster than it does.~ ~Which would NOT be an advantage,~
                you say, glad of a chance to show off a little knowledge:
                ~just think of what work it would make with the day and
                night! You see the earth takes twenty-four hours to turn
                round on its axis--~ ~Talking of axes,~ says the Duchess,
                ~chop off her head!~ (You glance at the cook in some
                anxiety; but the cook is busy stirring the soup, and
                seems not to be listening.)";
           Attack: "Her chin alone out-reaches you.";
       ],
  has  animate female;

Object -> queer_baby "baby"
  with name 'baby' 'child' 'creature' 'thing' 'ear' 'foot' 'right' 'left'
            'knot',
       description [;
           if (baby_knotted)
               "Twisted up into a sort of knot, held tight by the right
                ear and left foot, and grunting in a thoughtful,
                underhand sort of way.";
           "A queer-shaped little creature that holds out its arms and
            legs in all directions, ~just like a starfish,~ you think.
            It is snorting like a steam-engine, and doubling itself up
            and straightening itself out again, so that holding it at
            all is as much as you can do.";
       ],
       before [;
           Take, Turn, Squeeze:
               if (self in player) return KnotBaby();
           Drop:
               if (location == PepperKitchen)
                   "Leave it here, to be killed in a day or two between
                    the cook and the crockery? It would be murder, and
                    you know it. Out of doors with it first.";
               "It has not finished turning into whatever it means to be:
                another minute in your arms will settle the question.";
       ],
       life [;
           Ask, Tell, Answer: "It grunts. ~Don't grunt,~ you say; ~that's
               not at all a proper way of expressing yourself.~";
       ],
       each_turn [;
           if (self in player && baby_knotted == 0) {
               baby_wriggles++;
               if (baby_wriggles >= 2) {
                   baby_wriggles = 0;
                   "^The baby doubles itself up and straightens itself
                    out again with such energy that you all but lose it
                    over your shoulder. There is only one workable way of
                    nursing a thing of this pattern: twist it into a sort
                    of knot, and keep tight hold of its RIGHT EAR and
                    LEFT FOOT, so as to prevent its undoing itself.";
               }
           }
       ],
  has  animate;

[ KnotBaby;
    if (queer_baby notin player)
        "First catch your baby, as the cookery-books say.";
    if (baby_knotted) "You have it fast already, ear and foot.";
    baby_knotted = 1;
    Achieved(T_BABY);
    "You twist the little thing up into a sort of knot, and take tight
     hold of its right ear and left foot, so as to prevent its undoing
     itself. It grunts once, in the tone of a person conceding a point of
     procedure, and settles. There: that is the only workable way of
     nursing it, and you have found it.";
];

Object -> kitchen_cook "cook"
  with name 'cook',
       description
           "The cook, leaning over the fire and stirring a large cauldron
            of soup; at intervals she leaves off to throw the nearer
            kitchenware at the Duchess and the baby. She is the only
            creature in the kitchen that does not sneeze.",
       life [;
           Ask, Tell, Answer: "The cook's answer is a saucepan, which
               passes over your head with a sincerity there is no
               mistaking.";
           Attack: "She is armed with the entire kitchen.";
       ],
  has  animate female;

Object -> kitchen_cauldron "cauldron of soup"
  with name 'cauldron' 'soup' 'large' 'fire',
       description "A large cauldron which seems to be full of soup;
           certainly it is full of pepper.",
       before [;
           Taste, Eat, Drink: "There is certainly too much pepper in that
               soup -- you can tell without going nearer than this.";
       ],
  has  scenery;

Object -> pepper_air "pepper"
  with name 'pepper' 'smoke' 'air',
       description "The air is mostly pepper, with some smoke to help it
           along.",
       before [; Smell: "AH-choo! Exactly so."; ],
  has  scenery;

Object -> kitchen_cat "large grinning cat"
  with name 'cat' 'large' 'cheshire' 'puss' 'grin',
       description
           "A large cat, sitting on the hearth and grinning from ear to
            ear. It looks good-natured, you think: still it has VERY long
            claws and a great many teeth, so you feel it ought to be
            treated with respect.",
       life [;
           Ask, Tell, Answer: "The Cat only grins wider. Conversation, its
               grin implies, will keep for a better bough.";
       ],
  has  animate;

Object KitchenScene "(kitchen scene)"
  with daemon [;
           if (location ~= PepperKitchen) rfalse;
           if (queer_baby notin the_duchess && queer_baby notin PepperKitchen
               && queer_baby notin player) rfalse;
           kitchen_beats++;
           switch (kitchen_beats) {
               1: "^The pepper catches you and you sneeze; the baby howls
                   and sneezes alternately without a moment's pause; the
                   Duchess sneezes now and then; and a saucepan goes by
                   like a comet. ~Oh, PLEASE mind what you're doing!~ you
                   cry, in an agony of terror.";
               2: "^The cook takes the cauldron off the fire, and at once
                   sets to work throwing everything within her reach at
                   the Duchess and the baby -- the fire-irons come first;
                   then follows a shower of saucepans, plates, and
                   dishes. The Duchess takes no notice of them even when
                   they hit her; and the baby is howling so much already
                   that it is quite impossible to say whether the blows
                   hurt it or not.";
               3: "^The Duchess begins nursing her child again, singing a
                   sort of lullaby to it, and giving it a violent shake
                   at the end of every line: ~Speak roughly to your
                   little boy, and beat him when he sneezes: he only does
                   it to annoy, because he knows it teases.~ (Chorus, in
                   which the cook and the baby join: ~Wow! wow! wow!~)";
               default:
                   if (queer_baby in the_duchess || queer_baby in PepperKitchen) {
                       move queer_baby to player;
                       remove the_duchess;
                       baby_knotted = 0; baby_wriggles = 1;
                       "^~Here! you may nurse it a bit, if you like!~ says
                        the Duchess, flinging the baby at you as she
                        speaks. ~I must go and get ready to play croquet
                        with the Queen,~ and she hurries out of the room.
                        The cook throws a frying-pan after her as she goes
                        out, but it just misses her.^^You catch the baby
                        with some difficulty, for it is a queer-shaped
                        little creature, and holds out its arms and legs
                        in all directions. (It is doing its best to undo
                        itself: there will be a knack to holding it, no
                        doubt.)";
                   }
                   rfalse;
           }
           rfalse;
       ];

! Move the Duchess out when the baby is flung: done by removing her.
! (Handled below via an after-effect: simplest in the daemon above.)

! --------------------------------------------------------------------------
! The Cheshire Cat on the bough.
! --------------------------------------------------------------------------

Object cheshire_cat "Cheshire Cat"
  with name 'cheshire' 'cat' 'puss' 'grin' 'bough',
       description [;
           if (cheshire_stage >= 3)
               "Mostly grin, by now, with some cat arranged loosely
                behind it.";
           "The Cheshire Cat, sitting on a bough a few yards off, grinning
            from ear to ear. It has very long claws and a great many
            teeth, so you feel it ought to be treated with respect.";
       ],
       life [;
           Ask, Tell, Answer: return CheshireTalk();
           Kiss: "The grin widens fractionally: a cat may be kissed by a
               king's subject, it seems, but does not assist.";
           Attack: "Respect, remember: claws and teeth in those
               quantities are entitled to it.";
       ],
  has  animate;

[ CheshireTalk;
    switch (cheshire_stage) {
        1:  cheshire_stage = 2;
            "~Cheshire Puss,~ you begin, rather timidly, as you do not at
             all know whether it will like the name: however, it only
             grins a little wider. ~Come, it's pleased so far,~ you
             think, and go on: ~Would you tell me, please, which way I
             ought to go from here?~^^~That depends a good deal on where
             you want to get to,~ says the Cat. ~I don't much care
             where--~ you say. ~Then it doesn't matter which way you
             go,~ says the Cat. ~--so long as I get SOMEWHERE,~ you add,
             as an explanation. ~Oh, you're sure to do that,~ says the
             Cat, ~if you only walk long enough.~";
        2:  cheshire_stage = 3;
            "~What sort of people live about here?~ you try. ~In THAT
             direction,~ says the Cat, waving its right paw round, ~lives
             a Hatter: and in THAT direction,~ waving the other paw,
             ~lives a March Hare. Visit either you like: they're both
             mad.~ ~But I don't want to go among mad people,~ you remark.
             ~Oh, you can't help that,~ says the Cat: ~we're all mad
             here. I'm mad. You're mad.~ ~How do you know I'm mad?~ you
             say. ~You must be,~ says the Cat, ~or you wouldn't have come
             here.~^^~Do you play croquet with the Queen today?~ it adds.
             ~I should like it very much,~ you say, ~but I haven't been
             invited yet.~ ~You'll see me there,~ says the Cat -- and
             vanishes.";
        3:  cheshire_stage = 4;
            "While you are still looking at the place where it was, it
             suddenly appears again. ~By-the-bye, what became of the
             baby?~ it says. ~I'd nearly forgotten to ask.~ ~It turned
             into a pig,~ you say quietly, just as if it had come back in
             a natural way. ~I thought it would,~ says the Cat, and
             vanishes again.";
        4:  cheshire_stage = 5;
            remove cheshire_cat;
            "It appears once more, on a branch a little further off.
             ~Did you say pig, or fig?~ says the Cat. ~I said pig,~ you
             reply; ~and I wish you wouldn't keep appearing and vanishing
             so suddenly: you make one quite giddy.~ ~All right,~ says
             the Cat; and this time it vanishes quite slowly, beginning
             with the end of the tail, and ending with the grin, which
             remains some time after the rest of it has gone.^^~Well!
             I've often seen a cat without a grin,~ you think; ~but a
             grin without a cat! It's the most curious thing I ever saw
             in all my life!~ The trodden way north-east must lead toward
             the March Hare's house -- or the Hatter's; they were much
             the same direction, allowing for paws.";
        default:
            "The Cat only grins. It is a cat of few remarks and one
             expression.";
    }
];

! ==========================================================================
!   CHAPTER VII -- A Mad Tea-Party
! ==========================================================================

Object TeaPartyWood "Wood by the March Hare's House"
  with description [;
           print "The house of the March Hare stands here: you are sure it
               is the right house, because the chimneys are shaped like
               ears and the roof is thatched with fur. Before the house,
               under a tree, a great table is set out";
           if (fed_up == 0)
               print ", and there is loud unbusinesslike talk going on at
                   one corner of it";
           print ". ";
           if (tree_door_visible)
               print "And -- this is the curious thing -- one of the
                   trees close by has a DOOR leading right into it. ";
           print "The way back south-west leads toward the little house
               of the Duchess.";
           new_line;
       ],
       sw_to OpenPlace,
       e_to [; return ApproachTeaTable(); ],
       in_to [;
           if (tree_door_visible) return EnterDoorTree();
           return ApproachTeaTable();
       ],
  has  light;

[ ApproachTeaTable;
    if (alice_size == 0)
        "At three inches high, the tussocks between here and the table
         are a mountain range. (The left-hand bit of mushroom would mend
         that.)";
    if (alice_size == 3)
        "Nine feet of visitor would put even a mad tea-party off its tea.
         You had better be nearer your usual size. (The right-hand bit.)";
    print "You walk up towards the great table. ~No room! No room!~ they
        cry out when they see you coming. ~There's PLENTY of room!~ you
        say indignantly.^";
    PlayerTo(TeaParty);
    rtrue;
];

[ EnterDoorTree;
    print "You go in at the door in the tree -- and once more you find
        yourself in the long, low hall, close by the little glass table!
        ~Now, I'll manage better this time,~ you say to yourself.^";
    chapter = 8;
    PlayerTo(LongHall);
    rtrue;
];

Object -> hare_house "March Hare's house"
  with name 'house' 'chimneys' 'ears' 'roof' 'fur' 'thatch',
       description
           "The chimneys are shaped like ears and the roof is thatched
            with fur, which settles the question of whose house it is.
            The tea-table stands in front of it: nobody appears to go
            indoors at all.",
  has  scenery;

Object -> door_tree "tree with a door"
  with name 'tree' 'door' 'trees' 'bark',
       description [;
           if (tree_door_visible)
               "One of the trees has a door leading right into it. ~That's
                very curious!~ you think. ~But everything's curious
                today. I think I may as well go in at once.~";
           "Trees, and bark, and branches: a wood attending to its own
            affairs.";
       ],
       before [;
           Open, Enter:
               if (tree_door_visible) return EnterDoorTree();
               "You walk round two or three of the trees, but their doors
                (if they keep any) are not at home to visitors who have
                not yet been sufficiently provoked. Perhaps you have not
                finished with the tea-table.";
       ],
  has  scenery;

Object TeaParty "The Tea-Table"
  with description
           "A great long table under the tree, set for a great many more
            than three, but all crowded at one corner: the March Hare and
            the Hatter having tea, with a Dormouse sitting fast asleep
            between them, used by the other two as a cushion. Teapots,
            milk-jugs, plates of bread-and-butter, and a wilderness of
            cups, most of them used and none of them washed. The rest of
            the wood is back west.",
       w_to [; return LeaveTeaParty(); ],
       out_to [; return LeaveTeaParty(); ],
  has  light;

[ LeaveTeaParty;
    if (story_stage >= 2) {
        fed_up = 1;
        tree_door_visible = 1;
        print "This piece of rudeness is more than you can bear: you get
            up in great disgust, and walk off; the Dormouse falls asleep
            instantly, and neither of the others takes the least notice
            of your going, though you look back once or twice, half
            hoping they will call after you. The last time you see them,
            they are trying to put the Dormouse into the teapot. ~At any
            rate I'll never go THERE again!~ you say, picking your way
            through the wood. ~It's the stupidest tea-party I ever was at
            in all my life!~^^Just as you say this, you notice that one
            of the trees has a door leading right into it.^";
        PlayerTo(TeaPartyWood);
        rtrue;
    }
    print "You push back the armchair and step away from the table; the
        conversation closes over the gap as water closes over a
        stone.^";
    PlayerTo(TeaPartyWood);
    rtrue;
];

Object -> the_hatter "Hatter"
  with name 'hatter' 'mad' 'hat',
       description
           "The Hatter, in a hat with a price still in it (he keeps them
            to sell: he has none of his own), looking at you with great
            curiosity over a cup that has seen service.",
       life [;
           Ask, Tell, Answer:
               if (second == 'riddle' or 'raven' or 'answer' or
                   'writing-desk' or 'desk') return RiddleGiveUp();
               if (second == 'time' or 'watch' or 'clock')
                   return WatchScene();
               "~Suppose we change the subject,~ the March Hare interrupts,
                yawning, before the Hatter can do more than open his
                eyes very wide.";
           Attack: "At a tea-party? Even this one?";
       ],
  has  animate;

Object -> march_hare "March Hare"
  with name 'march' 'hare',
       description
           "The March Hare, with straws in his hair (it is May, so he may
            not be raving mad -- at least not so mad as he was in March),
            presiding over the milk-jug as over a public trust.",
       life [;
           Ask, Tell, Answer:
               if (second == 'wine') "~There isn't any,~ says the March
                   Hare, with the satisfaction of a host whose
                   hospitality is complete.";
               "~Take some more tea,~ the March Hare says to you, very
                earnestly. ~I've had NOTHING yet,~ you reply in an
                offended tone, ~so I can't take more.~ ~You mean you
                can't take LESS,~ says the Hatter: ~it's very easy to
                take MORE than nothing.~";
           Attack: "He would only offer you wine that isn't there.";
       ],
  has  animate;

Object -> the_dormouse "Dormouse"
  with name 'dormouse',
       description
           "A Dormouse, fast asleep between the other two, who rest their
            elbows on it and talk over its head. ~Very uncomfortable for
            the Dormouse,~ you think; ~only, as it's asleep, I suppose it
            doesn't mind.~",
       life [;
           Ask, Tell, Answer, WakeOther:
               return DormouseStory();
           Attack: return DormouseStory();
           Touch: return DormouseStory();
       ],
  has  animate;

[ DormousePinch; return DormouseStory(); ];

[ DormouseStory;
    switch (story_stage) {
        0:  story_stage = 1;
            "You pinch the Dormouse (on both sides at once, which is the
             customary way here). It opens its eyes slowly. ~I wasn't
             asleep,~ it says in a hoarse, feeble voice: ~I heard every
             word you fellows were saying.~ ~Tell us a story!~ says the
             March Hare. ~Yes, please do!~ you plead.^^~Once upon a time
             there were three little sisters,~ the Dormouse begins in a
             great hurry; ~and their names were Elsie, Lacie, and Tillie;
             and they lived at the bottom of a well--~ ~What did they
             live on?~ you ask (you always take a great interest in
             questions of eating and drinking). ~They lived on treacle,~
             says the Dormouse, after thinking a minute or two. ~They
             couldn't have done that, you know,~ you gently remark:
             ~they'd have been ill.~ ~So they were,~ says the Dormouse;
             ~VERY ill.~^^~But why did they live at the bottom of a
             well?~ you ask. The Dormouse takes a minute or two to think
             about it, and then says: ~It was a treacle-well.~ ~There's
             no such thing!~ you are beginning very angrily, but the
             Hatter and the March Hare go ~Sh! sh!~ and the Dormouse
             sulkily remarks, ~If you can't be civil, you'd better finish
             the story for yourself.~ ~No, please go on!~ you say very
             humbly. (Just then the Hatter interrupts -- see what he
             wants; or pinch the Dormouse again to keep the story
             going.)";
        1:  story_stage = 2;
            Achieved(T_TREACLE);
            "The Dormouse has closed its eyes and gone off into a doze;
             but on being pinched it wakes up again with a little shriek,
             and goes on: ~--and so these three little sisters -- they
             were learning to draw, you know--~ ~What did they draw?~ you
             ask. ~Treacle,~ says the Dormouse, without considering at
             all this time. ~But they were IN the well,~ you object.
             ~Of course they were,~ says the Dormouse: ~well in.~^^~They
             were learning to draw,~ it goes on, yawning and rubbing its
             eyes, ~and they drew all manner of things -- everything that
             begins with an M, such as mouse-traps, and the moon, and
             memory, and muchness -- you know you say things are `much of
             a muchness' -- did you ever see such a thing as a drawing of
             a muchness?~ ~Really, now you ask me,~ you say, very much
             confused, ~I don't think--~^^~Then you shouldn't talk,~
             says the Hatter.";
        default:
            "The Dormouse is asleep again, and has plainly delivered
             itself of every M it possesses. (After the Hatter's last
             remark, the civil thing to do -- the only thing to do -- is
             to get up and LEAVE.)";
    }
];

[ RiddleGiveUp;
    if (riddle_open == 0)
        "The Hatter opens his eyes very wide, but all he says is, ~Why is
         a raven like a writing-desk?~ Come, you shall have some fun now,
         you think: they've begun asking riddles.";
    if (riddle_given_up)
        "~I haven't the slightest idea,~ the Hatter says again, with the
         air of a man whose answer has improved with keeping.";
    riddle_given_up = 1;
    "~Have you guessed the riddle yet?~ the Hatter says, turning to you.
     ~No, I give it up,~ you reply: ~what's the answer?~ ~I haven't the
     slightest idea,~ says the Hatter. ~Nor I,~ says the March Hare. You
     sigh wearily. ~I think you might do something better with the
     time,~ you say, ~than waste it in asking riddles that have no
     answers.~ ~If you knew Time as well as I do,~ says the Hatter, ~you
     wouldn't talk about wasting IT. It's HIM.~";
];

[ WatchScene;
    "The Hatter takes his watch out of his pocket and looks at it
     uneasily, shaking it every now and then and holding it to his ear.
     ~Two days wrong!~ he sighs. ~I told you butter wouldn't suit the
     works!~ he adds, looking angrily at the March Hare. ~It was the BEST
     butter,~ the March Hare meekly replies. ~Yes, but some crumbs must
     have got in as well,~ the Hatter grumbles: ~you shouldn't have put
     it in with the bread-knife.~ The March Hare takes the watch, looks
     at it gloomily, dips it into his cup of tea, and looks at it again;
     but he can think of nothing better to say than ~It was the BEST
     butter, you know.~^^~What a funny watch!~ you remark. ~It tells the
     day of the month, and doesn't tell what o'clock it is!~ ~Why should
     it?~ mutters the Hatter. ~Does YOUR watch tell you what year it
     is?~ ~Of course not,~ you reply very readily: ~but that's because
     it stays the same year for such a long time together.~ ~Which is
     just the case with MINE,~ says the Hatter. He quarrelled with Time
     last March, it appears (~just before HE went mad, you know~ --
     pointing his teaspoon at the March Hare), at the great concert given
     by the Queen of Hearts, where he had to sing ~Twinkle, twinkle,
     little bat! How I wonder what you're at!~ -- and he'd hardly
     finished the first verse when the Queen jumped up and bawled out,
     ~He's murdering the time! Off with his head!~ ~And ever since
     that,~ he goes on in a mournful tone, ~he won't do a thing I ask!
     It's always six o'clock now.~^^A bright idea comes into your head.
     ~Is that the reason so many tea-things are put out here?~ you ask.
     ~Yes, that's it,~ says the Hatter with a sigh: ~it's always
     tea-time, and we've no time to wash the things between whiles.~
     ~Then you keep moving round, I suppose?~ ~Exactly so: as the things
     get used up.~";
];

Object -> tea_things "tea-things"
  with name 'tea' 'teapot' 'cup' 'cups' 'teacup' 'milk' 'jug' 'milk-jug'
            'bread' 'butter' 'bread-and-butter' 'plate' 'plates'
            'teathings' 'things',
       description [;
           if (moved_round)
               "From your new place: a clean cup (the Hatter took the
                cleanest, but yours will serve), tea within reach, and
                the March Hare's late plate, into which the milk-jug has
                been upset.";
           "A wilderness of tea-things, all used, none washed. The clean
            ones are further round the table, where nobody is sitting --
            for the moment.";
       ],
       before [;
           Take, Drink, Eat:
               return TakeTea();
       ],
  has  scenery;

[ TakeTea;
    if (location ~= TeaParty) "There is no tea here; a grave omission.";
    if (moved_round == 0)
        "Every cup within reach has been drunk from, buttered, or slept
         against. ~Have some wine,~ the March Hare says in an encouraging
         tone. You look all round the table, but there is nothing on it
         but tea. ~I don't see any wine,~ you remark. ~There isn't any,~
         says the March Hare. ~Then it wasn't very civil of you to offer
         it,~ you say angrily. ~It wasn't very civil of you to sit down
         without being invited,~ says the March Hare. (The clean things
         are all further round the table: no tea for you unless the party
         MOVES ROUND, it seems, and it only moves when the Hatter wants a
         clean cup.)";
    if (had_tea)
        "You have had your tea and bread-and-butter, which at this table
         is as far as refreshment can be pushed.";
    had_tea = 1;
    Achieved(T_TEA);
    "You help yourself to tea and bread-and-butter at your new place --
     first tipping the March Hare's milk out of your plate -- and it is
     very good tea, considering that Time himself has been holding it at
     six o'clock for a month or more. ~Nobody asked YOUR opinion,~ you
     remark to the Hatter, over the rim. ~Who's making personal remarks
     now?~ the Hatter asks triumphantly.";
];

Object -> tea_armchair "large armchair"
  with name 'armchair' 'arm-chair' 'chair' 'large',
       description "A large armchair at one end of the table: yours, by
           right of sitting in it.",
       before [;
           Enter: if (tea_seated) "You are in it already.";
               tea_seated = 1;
               "You sit down in the large armchair at one end of the
                table, in the teeth of the cry of ~No room!~";
       ],
  has  enterable static;

Object TeaScene "(tea-party scene)"
  with daemon [;
           if (location ~= TeaParty) rfalse;
           tea_beats++;
           switch (tea_beats) {
               1: riddle_open = 1;
                  "^~Your hair wants cutting,~ says the Hatter. He has
                   been looking at you for some time with great
                   curiosity, and this is his first speech. ~You should
                   learn not to make personal remarks,~ you say with some
                   severity: ~it's very rude.~ The Hatter opens his eyes
                   very wide on hearing this; but all he SAYS is: ~Why is
                   a raven like a writing-desk?~ (There is a riddle for
                   you! You might try to ANSWER it -- or ask him for the
                   answer, when you have given it up.)";
               2: "^~Do you mean that you think you can find out the
                   answer to it?~ says the March Hare, of the riddle.
                   ~Exactly so,~ you say. ~Then you should say what you
                   mean,~ the March Hare goes on. ~I do,~ you hastily
                   reply; ~at least -- at least I mean what I say --
                   that's the same thing, you know.~ ~Not the same thing
                   a bit!~ says the Hatter. ~You might just as well say
                   that `I see what I eat' is the same thing as `I eat
                   what I see'!~ ~You might just as well say,~ adds the
                   Dormouse, which seems to be talking in its sleep,
                   ~that `I breathe when I sleep' is the same thing as `I
                   sleep when I breathe'!~ ~It IS the same thing with
                   you,~ says the Hatter, and here the conversation
                   drops.";
               3: "^The Hatter takes his watch out of his pocket, shakes
                   it, and holds it to his ear. ~What day of the month is
                   it?~ he says, turning to you. You consider a little,
                   and say ~The fourth.~ ~Two days wrong!~ sighs the
                   Hatter. (There is evidently a history to that watch:
                   you might ask him about it. The Dormouse, meanwhile,
                   sleeps on between them, and might be worth waking --
                   pinching is customary. And you have still had no
                   tea.)";
               5: if (story_stage >= 1 && moved_round == 0) {
                      moved_round = 1;
                      "^~I want a clean cup,~ interrupts the Hatter:
                       ~let's all move one place on.~ He moves on as he
                       speaks, and the Dormouse follows him: the March
                       Hare moves into the Dormouse's place, and you
                       rather unwillingly take the place of the March
                       Hare. The Hatter is the only one who gets any
                       advantage from the change; and you are a good deal
                       worse off than before, as the March Hare has just
                       upset the milk-jug into his plate. Still -- your
                       new place has a cup that will pass for clean, and
                       tea in reach of it. (You might actually get some
                       TEA at last.)";
                  }
                  tea_beats = 4; ! hold here until the story advances
               default: rfalse;
           }
           rfalse;
       ];
