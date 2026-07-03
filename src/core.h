! ==========================================================================
!   core.h -- globals, the size machinery, tasks, and helpers
! ==========================================================================

! --------------------------------------------------------------------------
! Alice's size: the engine of the whole dream.
!   0 = three inches high      1 = about a foot high
!   2 = your usual height      3 = more than nine feet high
! --------------------------------------------------------------------------

Global alice_size = 2;
Global chapter = 1;           ! which chapter of the book we are in, 1..12
Global prizes_given = 0;      ! the caucus-race prizes have been handed round

! Scene-state globals needed by GamePreRoutine (declared early).
Global shore_stage = 0;
Global mouse_leads = 0;
Global mouse_offense = 0;
Global garden_stage = 0;
Global ledge_stage = 0;
Global court_stage = 0;

[ SizeName n;
    switch (n) {
        0: print "three inches high";
        1: print "about a foot high";
        2: print "your usual height";
        3: print "rather more than nine feet high";
    }
];

! Report a plain size change (special first-time scenes are handled by the
! items themselves; this is the everyday mushroom-nibbling report).
[ AnnounceSize;
    print "^(You are now "; SizeName(alice_size); print ".)^";
];

! --------------------------------------------------------------------------
! Topic helpers: scan the words of a 'topic' token for a given word.
! --------------------------------------------------------------------------

[ TopicHas w   i k;
    if (consult_words == 0) rfalse;
    for (i = 0 : i < consult_words : i++) {
        wn = consult_from + i;
        k = NextWord();
        if (k == w) rtrue;
    }
    rfalse;
];

! --------------------------------------------------------------------------
! The player.
! --------------------------------------------------------------------------

[ AliceDesc;
    print "You are Alice, of course: a curious child, very fond of
        pretending to be two people, and at this moment ";
    SizeName(alice_size);
    print ". ";
    if (right_bit in player || left_bit in player)
        print "Your pockets hold, among other things, the two bits of
            mushroom, one in reach of each hand. ";
    "Your shoes are done with blacking.";
];

! --------------------------------------------------------------------------
! Tasks (the scoring table lives in alice.inf).
! --------------------------------------------------------------------------

Constant T_HOLE      = 0;
Constant T_JAR       = 1;
Constant T_DOOR      = 2;
Constant T_DRINK     = 3;
Constant T_CAKE      = 4;
Constant T_KEY       = 5;
Constant T_FAN       = 6;
Constant T_SHORE     = 7;
Constant T_COMFITS   = 8;
Constant T_THIMBLE   = 9;
Constant T_FETCH     = 10;
Constant T_BILL      = 11;
Constant T_DINAH     = 12;
Constant T_PEBBLE    = 13;
Constant T_PUPPY     = 14;
Constant T_TEMPER    = 15;
Constant T_HEIGHT    = 16;
Constant T_HOUSE     = 17;
Constant T_BABY      = 18;
Constant T_TEA       = 19;
Constant T_TREACLE   = 20;
Constant T_GARDEN    = 21;
Constant T_NONSENSE  = 22;
Constant T_FLOWERPOT = 23;
Constant T_CROQUET   = 24;
Constant T_WHOSECAT  = 25;
Constant T_HOLIDAY   = 26;
Constant T_DANCE     = 27;
Constant T_PENCIL    = 28;
Constant T_LIZARD    = 29;
Constant T_CARDS     = 30;

[ PrintTaskName n;
    switch (n) {
        T_HOLE:      "going down the rabbit-hole after the White Rabbit";
        T_JAR:       "putting the marmalade jar into a cupboard as you fell";
        T_DOOR:      "discovering the little door behind the curtain";
        T_DRINK:     "drinking what was in the DRINK ME bottle";
        T_CAKE:      "eating the EAT ME cake";
        T_KEY:       "taking the golden key while you could reach it";
        T_FAN:       "dropping the fan before you went out like a candle";
        T_SHORE:     "reaching the shore in the Mouse's company";
        T_COMFITS:   "providing prizes, exactly one comfit apiece all round";
        T_THIMBLE:   "accepting an elegant thimble";
        T_FETCH:     "fetching the Rabbit's fan and gloves";
        T_BILL:      "sending Bill up the chimney like a sky-rocket";
        T_DINAH:     "threatening the mob with Dinah";
        T_PEBBLE:    "shrinking out of the Rabbit's house";
        T_PUPPY:     "tiring out an enormous puppy";
        T_TEMPER:    "keeping your temper with the Caterpillar";
        T_HEIGHT:    "bringing yourself back to your usual height";
        T_HOUSE:     "getting into the Duchess's house without knocking";
        T_BABY:      "nursing the baby in the only workable manner";
        T_TEA:       "taking tea at the maddest of tea-parties";
        T_TREACLE:   "hearing the story of the treacle-well";
        T_GARDEN:    "getting into the beautiful garden at last";
        T_NONSENSE:  "saying NONSENSE to the Queen of Hearts";
        T_FLOWERPOT: "hiding the gardeners in the flowerpot";
        T_CROQUET:   "playing the first fair croquet stroke on that ground";
        T_WHOSECAT:  "recalling whose cat it is";
        T_HOLIDAY:   "knowing what the eleventh day was";
        T_DANCE:     "joining the Lobster Quadrille";
        T_PENCIL:    "relieving Bill of a squeaking pencil";
        T_LIZARD:    "putting the Lizard in right way up";
        T_CARDS:     "telling them what they are, after all";
        default:     rfalse;
    }
];

[ PrintRank;
    print ", earning you the rank of ";
    if (score >= 100) "the Wonder of Wonderland.";
    if (score >= 85)  "an uncommonly clever girl.";
    if (score >= 60)  "a person of some authority.";
    if (score >= 35)  "a great girl (you might well say this).";
    if (score >= 15)  "a curious child.";
    "quite a common little girl.";
];

[ DeathMessage;
    print "The dream has quite run out";
];

[ Amusing;
    print "^Did you try...^^\
        -- reading your sister's book (no pictures or conversations in it)?^\
        -- saying ~Ou est ma chatte?~ to the Mouse?^\
        -- asking the Cheshire Cat whether you said pig, or fig?^\
        -- answering the Hatter's riddle anyway?^\
        -- keeping the marmalade jar all the way to the trial?^\
        -- being rude to the Caterpillar (he can be ruder)?^\
        -- curtseying as you fell (do you think you could manage it?)^";
];

! --------------------------------------------------------------------------
! Things Alice carries from home.
! --------------------------------------------------------------------------

Object comfits "box of comfits"
  with name 'box' 'of' 'comfits' 'comfit' 'sweets' 'sweet',
       article "a",
       description
           "A little cardboard box of comfits -- sugared caraway seeds --
            which has come through everything remarkably well. (Luckily,
            the salt water has not got into it.) You should say there was
            exactly one comfit apiece, if a party of birds and animals were
            ever to want prizes.",
       before [;
           Eat:
               if (prizes_given)
                   "You eat a comfit. It tastes of having won a race.";
               "You are on the point of eating one when it occurs to you
                that comfits are exactly the sort of thing that gets wanted
                for prizes in a place like this; and Alice was far too wise
                a child to eat the prizes first and want them afterwards.";
           Give, Show:
               if (location == SandyShore) rfalse;
               "Nobody here wants comfits just now.";
       ];

Object thimble "thimble"
  with name 'thimble',
       description
           "Your own thimble: a perfectly ordinary one, though it has
            lately been looking as if it should like to be elegant.",
       before [;
           Give, Show:
               if (location == SandyShore) rfalse;
               "Nobody here wants a thimble just now.";
       ];

! --------------------------------------------------------------------------
! The two bits of mushroom (acquired in Chapter V; the size toolkit).
! Right-hand bit shrinks; left-hand bit grows. They are never used up:
! however much you nibble, somehow there is always a bit left in each hand.
! --------------------------------------------------------------------------

Global neck_scene_done = 0;   ! the serpent-and-Pigeon scene, once only
Global chin_scene_done = 0;   ! the chin-strikes-foot scene, once only

[ NibbleMushroom delta;
    if (delta < 0) {          ! the right-hand bit
        if (chin_scene_done == 0) {
            chin_scene_done = 1;
            alice_size = 0;
            "You nibble a little of the right-hand bit, to try the effect.
             The next moment you feel a violent blow underneath your chin:
             it has struck your foot! You are frightened by the very sudden
             change, but you feel there is no time to be lost, as you are
             shrinking rapidly. (You are now barely three inches high, your
             chin pressed so closely against your foot that there is hardly
             room to open your mouth again -- but you manage it.)";
        }
        if (alice_size == 0)
            "You nibble the right-hand bit, and shrink until your chin
             strikes your foot; whereupon you leave off hastily, for fear
             of going out altogether, like a candle. (You are still three
             inches high, or as near it as makes no matter.)";
        alice_size--;
        AnnounceSize();
        SizeConsequences();
        rtrue;
    }
    else {                    ! the left-hand bit
        if (neck_scene_done == 0 && location == Clearing) {
            NeckScene();      ! defined in world2.h
            rtrue;
        }
        if (alice_size == 3)
            "You nibble the left-hand bit, and grow until your head presses
             against the sky (or whatever serves for a sky in a dream), and
             you leave off in a hurry. Nine feet or so is quite enough for
             anybody.";
        alice_size++;
        AnnounceSize();
        SizeConsequences();
        rtrue;
    }
];

! Called after any ordinary size change: rewards, room-specific remarks.
[ SizeConsequences;
    if (alice_size == 2 && task_done->T_HEIGHT == 0 && chapter >= 5) {
        print "^It is so long since you have been anything near the right
            size, that it feels quite strange at first; but you get used
            to it in a few minutes, and begin talking to yourself, as
            usual. ~Come, there's half my plan done now! The next thing
            is, to get into that beautiful garden -- and how is that to
            be done, I wonder?~^";
        Achieved(T_HEIGHT);
    }
    if (location == LongHall) HallSizeCheck();     ! world1.h
];

Object right_bit "right-hand bit of mushroom"
  with name 'right' 'right-hand' 'bit' 'piece' 'mushroom' 'bits' 'pieces',
       article "the",
       description
           "A bit of the edge of the mushroom, held in (or at any rate kept
            on the side of) your right hand. Nibbling it makes you smaller:
            you found that out by experiment, which is the only way anything
            is ever found out here.",
       before [;
           Eat: return NibbleMushroom(-1);
           Drop: "Better not: you may want it again, you know.";
       ];

Object left_bit "left-hand bit of mushroom"
  with name 'left' 'left-hand' 'bit' 'piece' 'mushroom' 'bits' 'pieces',
       article "the",
       description
           "A bit of the edge of the mushroom, belonging to your left hand.
            Nibbling it makes you larger. It is wonderful how the two bits
            never seem to be used up, however much you nibble; but very few
            things indeed are really impossible down here.",
       before [;
           Eat: return NibbleMushroom(1);
           Drop: "Better not: you may want it again, you know.";
       ];

! Disambiguation help: EAT MUSHROOM alone asks which bit.

! --------------------------------------------------------------------------
! Global scene dispatch for SAY/ANSWER/SHOUT <topic>, YES, and THINK.
! The scene routines live in the world files.
! --------------------------------------------------------------------------

[ SayTopicSub;
    ! Route to whichever scene is listening for words.
    if (location == Courtroom)   { CourtSay();   rtrue; }
    if (location == RoseGarden)  { GardenSay();  rtrue; }
    if (location == CroquetGround) { CroquetSay(); rtrue; }
    if (location == RockyLedge)  { LedgeSay();   rtrue; }
    if (location == TidyRoom)    { RabbitHouseSay(); rtrue; }
    if (location == PoolOfTears || location == LongHall) { PoolSay(); rtrue; }
    if (location == SandyShore)  { ShoreSay();   rtrue; }
    if (location == Clearing)    { ClearingSay(); rtrue; }
    if (location == TreeTops)    { TreeTopsSay(); rtrue; }
    "You say it aloud, and very nicely too; but nobody in Wonderland takes
     the least notice.";
];

[ AliceThink;
    print "You generally give yourself very good advice (though you very
        seldom follow it). At present you advise yourself as follows:
        ";
    switch (chapter) {
        1: if (location == Riverbank)
               "~A White Rabbit with a waistcoat-pocket is not a thing one
                sees every day. If it goes down a hole, I should follow
                it.~";
           if (location == DownTheWell)
               "~After such a fall as this, I shall think nothing of
                tumbling down stairs! I may as well look about me as I
                go.~";
           "~The garden is through the little door; the little door wants
            the little key; and I want to be little. The things on the
            table keep changing whenever I change -- I must watch the
            order I do things in.~";
        2: "~Crying like that will make a pool of you. If anything should
            offer itself for getting smaller -- a fan, say -- take it; but
            mind you don't go out altogether, like a candle. And in salt
            water, one should be careful what one says about cats.~";
        3: "~Everybody has won, and all must have prizes; and it seems I
            am to provide them. What is in my pockets? And I must have a
            prize myself, you know.~";
        4: if (location == ThickWood)
               "~That puppy is dear, but it is also the size of a
                cart-horse. If I threw it something to worry, and kept the
                thistle between us, it might tire itself out.~";
           "~The Rabbit wants his fan and gloves, and his house is just
            the place to find them. Only I know something interesting is
            sure to happen whenever I eat or drink anything; and if I fill
            the house, why, the window and the chimney will be all the
            arms and legs I have to spare. Bill had better mind the
            chimney. And if they talk of burning the house down, there is
            always Dinah to mention.~";
        5: if (location == Clearing && Caterpillar in Clearing)
               "~Keep your temper. He is very easily offended, and he
                knows something worth hearing about this mushroom, I am
                sure of it: one side of something, and the other side of
                something. Politeness and patience, Alice.~";
           "~One side makes me taller, and the other side shorter; a bit
            in each hand, and nibble till it comes right. My usual height
            first; the rest of the plan afterwards.~";
        6: "~One can't call on anybody at the wrong size: a foot high will
            do for a four-foot house. Knocking is no use at all -- the
            Footman said so himself, and for once a footman was right --
            so I shall simply go in. And if anyone flings a baby at me, I
            shall hold it by the right ear and left foot, which is the
            only workable way, and carry it out of that dreadful
            kitchen.~";
        7: "~They say to take more tea when I have had none, and offer
            wine when there is only tea. When the Hatter wants a clean
            cup, everybody moves one place on; that would be my chance to
            get some tea at last. The Dormouse tells stories if one wakes
            it -- pinching is customary. And when it is all quite
            unbearable, I shall simply walk off into the wood, and keep my
            eyes open: some of these trees have more in them than bark.~";
        8: if (location == LongHall)
               "~Now, I'll manage better this time: the key first, and
                then the door open, and then the mushroom -- quickly,
                before the draught thinks of shutting it.~";
           if (location == CroquetGround)
               "~The flamingo under my arm, and its head down; the
                hedgehog unrolled and near; an arch in place; and all
                three at once, or not at all. The things here go round in
                their own regular order -- I shall count their turns.~";
           "~Whatever the Queen says, they are only a pack of cards, after
            all. I needn't be afraid of them, and NONSENSE is a very good
            word to say loudly. And if she orders anybody's head off, a
            flowerpot holds three gardeners at a pinch.~";
        9: "~Ten hours of lessons the first day, nine the next, and so on:
            that is the reason they're called lessons, because they lessen
            from day to day. Ten, nine, eight... and after the one-hour
            day comes a day of none at all. I know what I should call
            that.~";
        10: "~It must be a very pretty dance, and it would be civil to
            join in it, even with one's toes trodden on. And when they say
            the trial's beginning, I mean to see it: I have never been in
            a court of justice, but I have read about them in books.~";
        11: "~That pencil of Bill's squeaks abominably. If I got round
            behind him, I could take it away quite quickly. And I do
            believe I am beginning to grow again; I shall stay as long as
            there is room for me.~";
        12: "~The jurymen must all go back in their proper places -- ALL
            of them, and right way up, which is more than the Lizard can
            manage for himself. I know NOTHING about this business, and
            shall say so. And if it comes to sentences first and verdicts
            afterwards, why, they're nothing but a pack of cards, and it
            is high time somebody said THAT out loud too.~";
    }
];

[ HelpSub;
    print "This is an interactive fiction: you play Alice, and you tell
        her what to do with short commands -- LOOK, EXAMINE things, TAKE
        and DROP them, GO NORTH (or just N), and so on.^^\
        Some commands that get plenty of use in Wonderland: TALK TO
        someone, ASK someone ABOUT something, SAY something (out loud, to
        the room at large), FOLLOW someone, EAT and DRINK what you find
        (reading the label first, like a wise child), RECITE when you are
        told to, and WAIT (the letter Z) when it seems polite to.^^\
        THINK gives you Alice's own advice for the present chapter.
        SCORE shows your progress, and FULL shows how you earned it.
        SAVE and RESTORE do what they say; UNDO takes back one turn.^^\
        Nothing in this dream can kill you or trap you for good: it is,
        after all, your dream.^";
];

! --------------------------------------------------------------------------
! Initialise.
! --------------------------------------------------------------------------

[ Initialise;
    location = Riverbank;
    lookmode = 2;                     ! VERBOSE by default
    player.description = AliceDesc;
    move comfits to player;
    move thimble to player;
    StartDaemon(RiverbankScene);
    StartDaemon(WellScene);
    StartDaemon(HallScene);
    StartDaemon(PoolScene);
    StartDaemon(ShoreScene);
    StartDaemon(OpenPlaceScene);
    StartDaemon(KitchenScene);
    StartDaemon(TeaScene);
    StartDaemon(GardenScene);
    StartDaemon(CroquetScene);
    StartDaemon(CourtScene);
    print "^^All in the golden afternoon, full leisurely we glide... and
        the tale that follows is very much what happened next.^^\
        You are beginning to get very tired of sitting by your sister on
        the bank, and of having nothing to do: once or twice you have
        peeped into the book your sister is reading, but it has no
        pictures or conversations in it, ~and what is the use of a book,~
        you think, ~without pictures or conversations?~^^\
        So you are considering in your own mind (as well as you can, for
        the hot day makes you feel very sleepy and stupid) whether the
        pleasure of making a daisy-chain would be worth the trouble of
        getting up and picking the daisies...^";
];

! --------------------------------------------------------------------------
! GamePreRoutine: contextual handling of standard actions.
! (Defined here, before the library's Grammar stub.)
! --------------------------------------------------------------------------

[ GamePreRoutine;
    switch (action) {
        ##Think:
            AliceThink(); rtrue;
        ##Sorry:
            return DoApology();
        ##Listen:
            if (location == SandyShore) { ShoreListen(); rtrue; }
            if (location == RockyLedge) { LedgeBeat(); rtrue; }
        ##Yes:
            if (location == RoseGarden && garden_stage == 5) {
                GardenYes(); rtrue;
            }
            if (location == RockyLedge && ledge_stage >= 5
                && ledge_stage < 9) { LedgeBeat(); rtrue; }
        ##Swim:
            if (location == PoolOfTears) {
                if (mouse_leads) { MouseToShore(); rtrue; }
                SwimAbout(); rtrue;
            }
        ##VagueGo:
            if (location == SandyShore && shore_stage == 2) {
                CaucusRun(); rtrue;
            }
        ##Exit, ##Jump:
            if (location == Courtroom && court_stage == 7) {
                CourtStand(); rtrue;
            }
        ##Pray:
            "A dream is not a place where praying changes the furniture;
             still, it can do no harm.";
    }
    rfalse;
];

[ DoApology;
    if (location == PoolOfTears && pool_mouse in PoolOfTears) {
        mouse_offense = 0;
        mouse_leads = 1;
        "~Oh, I beg your pardon!~ you cry, in real distress. ~Mouse dear!
         Do come back again, and we won't talk about cats or dogs either,
         if you don't like them!~ When the Mouse hears this, it turns
         round and swims slowly back to you: its face is quite pale (with
         passion, you think), and it says in a low trembling voice, ~Let
         us get to the shore, and then I'll tell you my history, and
         you'll understand why it is I hate cats and dogs.~ (You had
         better FOLLOW it.)";
    }
    "You apologise, prettily, to nobody in particular; and it is received
     in the spirit in which it was sent.";
];

