! ==========================================================================
!   world1.h -- Chapters I-IV:
!   the Riverbank, the fall, the Long Hall, the Pool of Tears,
!   the Caucus-Race, the Rabbit's house, and the enormous puppy.
! ==========================================================================

! --------------------------------------------------------------------------
! Scene-state globals for this file.
! --------------------------------------------------------------------------

Global rb_stage = 0;          ! riverbank: rabbit's entrance
Global well_stage = 0;        ! the fall
Global hall_door_found = 0;
Global hall_seen_garden = 0;  ! the little door has been opened once
Global hall_door_open = 0;
Global hall_door_timer = 0;
Global hall_bottle_out = 0;
Global drink_timer = 0;       ! the DRINK ME shrink takes a little while
Global cake_eaten = 0;
Global pool_formed = 0;
Global cried_beats = 0;
Global hallrabbit_stage = 0;  ! the Rabbit's dash through the hall
Global pool_stage = 0;
Global race_on = 0;
Global dry_run = 0;
Global thimble_given = 0;
Global tale_stage = 0;
Global rh_stage = 0;          ! the siege of the Rabbit's house
Global rh_nudge = 0;
Global snatches = 0;
Global bill_tries = 0;
Global puppy_stage = 0;
Global puppy_charges = 0;
Global dinah_said = 0;

! ==========================================================================
!   CHAPTER I -- the Riverbank and the fall
! ==========================================================================

Object Riverbank "The Bank, in the Golden Afternoon"
  with description [;
           print "You are sitting with your sister on the bank of the
               river, in the sleepiest afternoon that ever was. The daisies
               are thick in the grass, and a hedge runs along the top of
               the field";
           if (rb_stage >= 3)
               print ", and under the hedge is a large rabbit-hole, down
                   which the White Rabbit has just popped";
           ".";
       ],
       d_to [; return HoleGate(); ],
       in_to [; return HoleGate(); ],
       n_to [; return HoleGate(); ],
       s_to "You feel much too sleepy to go visiting anywhere; and
             besides, something is about to happen. You can feel it in the
             afternoon.",
       e_to "You feel much too sleepy for a walk; the afternoon has other
             plans for you.",
       w_to "You feel much too sleepy for a walk; the afternoon has other
             plans for you.",
       cant_go "The afternoon is too hot and too golden for wandering.
             Something remarkable is sure to come along if you sit still a
             moment more.",
  has  light;

[ HoleGate;
    if (rb_stage < 3)
        "There is no hole to go down just yet; only grass, daisies, and
         drowsiness. Something remarkable is bound to happen first.";
    Achieved(T_HOLE);
    print "In another moment down you go after it, never once considering
        how in the world you are to get out again.^";
    PlayerTo(DownTheWell);
    rtrue;
];

Object -> bank_sister "your sister"
  with name 'sister' 'my',
       description
           "Your sister is deep in her book, which is a very dull one: you
            have peeped, and there are no pictures or conversations in it
            whatever.",
       life [;
           Ask, Tell, Answer:
               "Your sister murmurs something soothing and does not look
                up. She is at a very absorbing chapter, no doubt, though
                how a chapter with no conversations in it can absorb
                anybody is more than you can say.";
           Kiss: "She pats your hair without looking up.";
           Attack: "Certainly not. She is your sister, and besides, she is
                bigger than you.";
       ],
  has  animate scenery female proper;

Object -> sister_book "sister's book"
  with name 'book' 'sisters',
       description
           "You peep into it once more, on the chance. No pictures. No
            conversations. ~And what is the use of a book,~ you think,
            ~without pictures or conversations?~",
       before [;
           Take: "It is your sister's, and she is using it. Both of these
               objections would want answering.";
       ],
  has  scenery;

Object -> daisies "daisies"
  with name 'daisy' 'daisies' 'flowers' 'grass' 'daisy-chain' 'chain',
       description
           "White and gold in the deep grass: the raw material of
            daisy-chains, if the pleasure of making one should prove worth
            the trouble of getting up and picking them.",
       before [;
           Take, Pull:
               if (rb_stage >= 3)
                   "There is no time for daisies now! A rabbit with a
                    waistcoat-pocket has just gone down that hole.";
               "You pick a daisy or two, in a considering sort of way, but
                the hot day makes your fingers slow, and you let them fall
                into your lap.";
       ],
  has  scenery;

Object -> bank_hedge "hedge"
  with name 'hedge' 'field',
       description [;
           if (rb_stage >= 3)
               "A good English hedge, with a large rabbit-hole under it.";
           "A good English hedge, of the sort that generally has rabbits
            under it somewhere.";
       ],
  has  scenery;

Object -> rabbit_hole "large rabbit-hole"
  with name 'hole' 'rabbit-hole' 'rabbithole' 'burrow' 'rabbit' 'white',
       description
           "A large rabbit-hole under the hedge: it goes straight on like
            a tunnel for some way, and how far after that there is only
            one way of finding out.",
       before [;
           Enter: return HoleGate();
       ],
  has  scenery concealed;

Object -> bank_rabbit "White Rabbit"
  with name 'white' 'rabbit' 'pink' 'eyes' 'waistcoat' 'watch',
       description
           "A White Rabbit with pink eyes, in a waistcoat -- and there was
            nothing so very remarkable in that, until it took a watch out
            of its waistcoat-pocket. You have never before seen a rabbit
            with either a waistcoat-pocket, or a watch to take out of it.",
       life [;
           Ask, Tell, Answer, Kiss, Attack:
               "The Rabbit is in far too great a hurry to attend to
                anybody.";
       ],
       before [;
           Take: "One does not simply pick up a rabbit in a waistcoat.";
       ],
  has  animate scenery concealed;

Object RiverbankScene "(riverbank scene)"
  with daemon [;
           if (location ~= Riverbank) rfalse;
           rb_stage++;
           switch (rb_stage) {
               1:  move bank_rabbit to Riverbank;
                   give bank_rabbit ~concealed;
                   "^Suddenly a White Rabbit with pink eyes runs close by
                    you. There is nothing so very remarkable in that; nor
                    do you think it so very much out of the way to hear
                    the Rabbit say to itself, ~Oh dear! Oh dear! I shall
                    be late!~";
               2:  "^But now the Rabbit actually takes a watch out of its
                    waistcoat-pocket, looks at it, and hurries on -- and
                    you start to your feet, for it flashes across your
                    mind that you have never before seen a rabbit with
                    either a waistcoat-pocket, or a watch to take out of
                    it.";
               3:  remove bank_rabbit;
                   give rabbit_hole ~concealed;
                   "^Burning with curiosity, you run across the field
                    after it, and are just in time to see it pop down a
                    large rabbit-hole under the hedge. (You might FOLLOW
                    it; or you might go back to the daisies, and never
                    know.)";
               default:
                   StopDaemon(RiverbankScene);
                   rfalse;
           }
       ];

! --------------------------------------------------------------------------
! The fall down the well.
! --------------------------------------------------------------------------

Object DownTheWell "Falling Down the Well"
  with description
           "Either the well is very deep, or you are falling very slowly,
            for you have plenty of time as you go down to look about you,
            and to wonder what is going to happen next. The sides of the
            well are filled with cupboards and bookshelves: here and there
            you see maps and pictures hung upon pegs, all drifting gently
            upwards past you.",
       cant_go
           "You are falling, and the only direction on offer is Down,
            which is being seen to already.",
       d_to "You are going down quite as fast as the well allows, which is
            not very.",
  has  light;

Object -> well_shelves "cupboards and bookshelves"
  with name 'cupboard' 'cupboards' 'shelf' 'shelves' 'bookshelf'
            'bookshelves' 'maps' 'map' 'pictures' 'picture' 'pegs' 'sides',
       description
           "Cupboards, bookshelves, maps and pictures, sliding smoothly
            upwards past you -- or rather, you are sliding smoothly down
            past them.",
       before [;
           Open, Search:
               "They pass just too quickly for rummaging -- all except the
                one with the jar, which providence has put within reach.";
           Receive:
               if (noun == marmalade_jar) {
                   remove marmalade_jar;
                   Achieved(T_JAR);
                   "You manage to put the jar into one of the cupboards as
                    you fall past it -- for you do not like to drop it,
                    for fear of killing somebody underneath. It was very
                    well done, for a person falling down a well.";
               }
               "You had better keep hold of that.";
       ],
  has  scenery;

Object marmalade_jar "jar labelled ORANGE MARMALADE"
  with name 'jar' 'orange' 'marmalade' 'label',
       article "a",
       description
           "The label says ORANGE MARMALADE, beautifully; but the jar, to
            your great disappointment, is empty. Labels are like that,
            sometimes.",
       before [;
           Eat, Taste: "It is empty: the label is all the marmalade there
               is.";
           Drop: if (location == DownTheWell)
                   "You do not like to drop the jar, for fear of killing
                    somebody underneath. Perhaps a cupboard will present
                    itself.";
       ];

Object WellScene "(well scene)"
  with daemon [;
           if (location ~= DownTheWell) rfalse;
           well_stage++;
           switch (well_stage) {
               1:  move marmalade_jar to well_shelves;
                   give marmalade_jar ~concealed;
                   move marmalade_jar to DownTheWell; ! within reach on a shelf
                   "^Down, down, down. A jar drifts past on one of the
                    shelves, exactly within reach: it is labelled ORANGE
                    MARMALADE.";
               2:  "^Down, down, down. Would the fall never come to an
                    end? ~I wonder how many miles I've fallen by this
                    time?~ you say aloud. ~I must be getting somewhere
                    near the centre of the earth... but then I wonder what
                    Latitude or Longitude I've got to?~ (You have no idea
                    what Latitude is, or Longitude either, but they are
                    nice grand words to say.)";
               3:  "^Down, down, down. ~Dinah'll miss me very much
                    tonight, I should think! I wish you were down here
                    with me, Dinah! There are no mice in the air, I'm
                    afraid, but you might catch a bat, and that's very
                    like a mouse, you know. But do cats eat bats, I
                    wonder?~ And here you begin to get rather sleepy: do
                    cats eat bats? Do bats eat cats?";
               4:  StopDaemon(WellScene);
                   if (marmalade_jar in DownTheWell) remove marmalade_jar;
                   print "^...when suddenly, thump! thump! down you come
                       upon a heap of sticks and dry leaves, and the fall
                       is over. You are not a bit hurt, and you jump to
                       your feet in a moment.^";
                   PlayerTo(LongPassage);
                   rtrue;
           }
       ];

Object LongPassage "Long Passage"
  with description
           "It is all dark overhead; before you is another long passage,
            and the White Rabbit is still in sight, hurrying down it.
            There is not a moment to be lost.",
       n_to [; return ChasePassage(); ],
       s_to "There is nothing behind you but the heap of sticks and dry
             leaves you arrived on, and no way up the well at all.",
       u_to "It is all dark overhead, and quite unclimbable.",
       cant_go "The passage runs onward, after the Rabbit. (You might
             simply FOLLOW it.)",
  has  light;

[ ChasePassage;
    print "Away you go like the wind, and are just in time to hear it say,
        as it turns a corner, ~Oh my ears and whiskers, how late it's
        getting!~ You are close behind it when you turn the corner -- but
        the Rabbit is no longer to be seen.^";
    PlayerTo(LongHall);
    rtrue;
];

Object -> passage_rabbit "White Rabbit"
  with name 'white' 'rabbit',
       description
           "Hurrying along ahead of you, coat-tails flying.",
       life [;
           Ask, Tell, Answer:
               "It is too far ahead to hear you, and going further.";
       ],
       before [; Take: "It is a great deal faster than you are."; ],
  has  animate scenery;

! ==========================================================================
!   The Long, Low Hall: the hub of the dream.
! ==========================================================================

Object LongHall "Long, Low Hall"
  with description [;
           print "This is a long, low hall, lit up by a row of lamps
               hanging from the roof. There are doors all round it, but
               they are all locked; you have been down one side and up
               the other, trying every one. In the middle stands a little
               three-legged table, all made of solid glass";
           if (alice_size < 2)
               print ", its top hopelessly far above your head";
           print ".";
           if (hall_door_found == 0)
               print " A low curtain hangs along one wall.";
           else {
               print " Behind the low curtain is the little door, about
                   fifteen inches high";
               if (hall_door_open) print ", standing open";
               else print ", shut";
               print ".";
           }
           if (pool_formed && chapter < 3)
               print " A large pool of tears, about four inches deep,
                   reaches half down the hall.";
           new_line;
       ],
       before [;
           Go: if (pool_formed && alice_size <= 1 && chapter < 3) {
                   SlipIntoPool();
                   rtrue;
               }
       ],
       n_to [; return TryHallDoors(); ],
       s_to [; return TryHallDoors(); ],
       e_to [; return TryHallDoors(); ],
       w_to [; return TryHallDoors(); ],
       u_to "The roof is far too low for climbing anywhere, and the
             passage behind is lost in the dark.",
       in_to [; return EnterLittleDoor(); ],
       cant_go [; return TryHallDoors(); ],
  has  light;

[ TryHallDoors;
    if (pool_formed && alice_size <= 1 && chapter < 3) {
        SlipIntoPool(); rtrue;
    }
    "You walk all the way down one side and up the other, trying every
     door; but they are all locked, and you come sadly back to the middle,
     wondering how you are ever to get out again.";
];

[ SlipIntoPool;
    print "As you hurry across the hall your foot slips, and in another
        moment, splash! you are up to your chin in salt water. Your first
        idea is that you have somehow fallen into the sea; however, you
        soon make out that you are in the pool of tears which you wept
        when you were nine feet high. ~I wish I hadn't cried so much!~
        you say, as you swim about, trying to find your way out. ~I shall
        be punished for it now, I suppose, by being drowned in my own
        tears!~^";
    ! The hall's furniture stays behind, whatever you were holding.
    if (golden_key in player) move golden_key to glass_table;
    if (bottle_dm in player) move bottle_dm to glass_table;
    if (glass_box in player) move glass_box to LongHall;
    if (hall_fan in player) remove hall_fan;
    if (kid_gloves in player) remove kid_gloves;
    chapter = 2;
    PlayerTo(PoolOfTears);
    rtrue;
];

[ EnterLittleDoor;
    if (hall_door_found == 0)
        "There are doors all round the hall, but they are all locked.";
    if (hall_door_open == 0) {
        if (little_door has locked)
            "The little door is locked. The lock is a conscientious one,
             and does its work thoroughly.";
        "The little door is shut.";
    }
    if (alice_size >= 2)
        "You kneel down and put your head into the passage -- and even if
         your head would go through, it would be of very little use
         without your shoulders. Oh, how you wish you could shut up like a
         telescope!";
    ! Small enough, and the door is open:
    Achieved(T_GARDEN);
    chapter = 8;
    alice_size = 2;
    print "You walk down the little passage -- not much larger than a
        rat-hole, but exactly large enough for you -- and then... you find
        yourself at last in the beautiful garden, among the bright
        flowerbeds and the cool fountains. (The garden air agrees with
        you: by insensible degrees, and without a crumb of mushroom, you
        find yourself your usual height again. Gardens of this quality
        arrange such things themselves.)^";
    PlayerTo(RoseGarden);
    rtrue;
];

! Called when Alice's size changes while in the hall.
[ HallSizeCheck;
    if (alice_size < 2 && golden_key in glass_table)
        print "^(The little golden key twinkles on the glass table, high
            above your head.)^";
];

Object -> hall_lamps "row of lamps"
  with name 'lamp' 'lamps' 'row' 'roof' 'lights',
       description "A row of lamps hanging from the roof, burning steadily
           and asking no questions.",
  has  scenery;

Object -> hall_doors "doors"
  with name 'door' 'doors' 'locked' 'large',
       description
           "Doors all round the hall, every one of them locked. Either the
            locks are too large, or the key is too small, but at any rate
            the little golden key will not open any of them.",
       before [;
           Open, Unlock, Enter: return TryHallDoors();
       ],
  has  scenery;

Object -> hall_curtain "low curtain"
  with name 'curtain' 'low',
       description [;
           if (hall_door_found)
               "A low curtain; behind it is the little door.";
           "A low curtain you had not noticed before, hanging along the
            wall about knee-height.";
       ],
       before [;
           Search, LookUnder, Pull, Push, Open:
               if (hall_door_found)
                   "Behind the curtain is the little door, as before.";
               hall_door_found = 1;
               Achieved(T_DOOR);
               give little_door ~concealed;
               "You lift the curtain aside, and behind it is a little door
                about fifteen inches high! You feel sure the little golden
                key must belong to it: it would be just the size.";
       ],
  has  scenery;

Object -> little_door "little door"
  with name 'little' 'door' 'small' 'tiny' 'garden' 'passage' 'keyhole',
       description [;
           if (hall_door_open)
               "The little door stands open on a small passage, not much
                larger than a rat-hole. Kneeling and looking along it, you
                can see the loveliest garden you ever saw: beds of bright
                flowers and cool fountains. How you long to get out of
                this dark hall and wander among them!";
           print "A door about fifteen inches high, set low in the wall
               behind the curtain";
           if (little_door has locked) ". It is locked";
           ". It is shut";
       ],
       with_key golden_key,
       before [;
           Unlock:
               if (second ~= golden_key)
                   "The lock wants a key, and a little one.";
               if (alice_size < 2)
                   "You try, reaching up on tiptoe -- but the golden key,
                    which was a charming little key when you were larger,
                    is now a great heavy golden beam, and the lock is
                    above you besides. It will not turn for anybody under
                    a certain height.";
               give little_door ~locked;
               "You try the little golden key in the lock, and to your
                great delight it fits! The lock turns with a willing
                click.";
           Lock: "There is no occasion for locking things; the lock
               attends to that side of the business itself.";
           Open:
               if (little_door has locked)
                   "The little door is locked. (The keyhole is a golden
                    one, if that is a hint.)";
               if (hall_door_open) "It is open already.";
               if (alice_size < 2)
                   "It is all you can do, at your height, to reach the
                    handle; and the door is beyond your strength unless it
                    chooses to help.";
               hall_door_open = 1;
               hall_door_timer = 3;
               if (hall_seen_garden == 0) {
                   hall_seen_garden = 1;
                   "You open the little door and kneel down: it leads into
                    a small passage, not much larger than a rat-hole, and
                    beyond it lies the loveliest garden you ever saw --
                    bright flowerbeds, cool fountains. But you cannot even
                    get your head through the doorway; ~and even if my
                    head would go through,~ you think, ~it would be of
                    very little use without my shoulders. Oh, how I wish I
                    could shut up like a telescope! I think I could, if I
                    only knew how to begin.~";
               }
               "You open the little door, and the green and silver of the
                garden shines through. It is a door with opinions about
                staying open, so you had better be quick about whatever
                you mean to do.";
           Close: hall_door_open = 0; hall_door_timer = 0;
               give little_door locked;
               "You shut the little door, and the conscientious lock
                fastens itself with a click of satisfaction.";
           Enter: return EnterLittleDoor();
       ],
  has  static openable locked concealed;

Object -> glass_table "glass table"
  with name 'glass' 'table' 'three-legged' 'legs' 'leg',
       description [;
           print "A little three-legged table, all made of solid glass";
           if (alice_size < 2)
               print ", and quite hopelessly above you: you can see the
                   top of it glittering through the glass, like the
                   underside of a pond";
           ".";
       ],
       before [;
           Climb:
               if (alice_size >= 2) "There is no need: you can reach the
                   top perfectly well.";
               "You try your best to climb up one of the legs of the
                table, but it is too slippery; and when you have tired
                yourself out with trying, you sit down and very nearly
                cry.";
           LookUnder, Search:
               if (glass_box has concealed) {
                   give glass_box ~concealed;
                   move glass_box to LongHall;
                   "Lying under the table is a little glass box. (You
                    wonder that you never noticed it before; but then, it
                    is the sort of table things appear under.)";
               }
               "Nothing else under there but floor.";
           Receive:
               if (alice_size < 2)
                   "The tabletop is far out of your reach.";
       ],
  has  supporter static;

Object -> -> golden_key "little golden key"
  with name 'little' 'golden' 'key' 'gold',
       description
           "A tiny key of bright gold. Your first thought was that it
            might belong to one of the doors of the hall; but either the
            locks are too large, or the key is too small. It fits the
            little door behind the curtain exactly.",
       before [;
           Take:
               if (alice_size < 2)
                   "You can see it quite plainly through the glass, and
                    you try your best to climb up one of the table-legs,
                    but it is too slippery. The poor little key might as
                    well be at the top of a mountain.";
               if (self in glass_table && task_done->T_KEY == 0)
                   Achieved(T_KEY);
       ],
  has  ;

Object glass_box "little glass box"
  with name 'glass' 'box' 'little',
       description [;
           if (small_cake in self)
               "A little glass box; in it is a very small cake, on which
                the words EAT ME are beautifully marked in currants.";
           "A little glass box, empty now, and smelling faintly of
            currants.";
       ],
  has  container open concealed;

Object -> small_cake "small cake"
  with name 'small' 'cake' 'currants' 'eat' 'me',
       description
           "A very small cake, on which the words EAT ME are beautifully
            marked in currants. ~Well, I'll eat it,~ is the obvious
            resolution, ~and if it makes me grow larger, I can reach the
            key; and if it makes me grow smaller, I can creep under the
            door; so either way I'll get into the garden, and I don't care
            which happens!~",
       before [;
           Eat:
               cake_eaten = 1;
               Achieved(T_CAKE);
               remove self;
               alice_size = 3;
               print "You eat a little bit, and say anxiously to yourself,
                   ~Which way? Which way?~, holding your hand on the top
                   of your head to feel which way it is growing -- and
                   for a moment nothing happens at all, which seems quite
                   dull and stupid, life going on in the common way. So
                   you set to work, and very soon finish off the cake.^^\
                   ~Curiouser and curiouser!~ you cry (you are so much
                   surprised that for the moment you quite forget how to
                   speak good English); ~now I'm opening out like the
                   largest telescope that ever was! Goodbye, feet!~ Your
                   head strikes against the roof of the hall: in fact you
                   are now rather more than nine feet high.^";
               HallSizeCheck();
               rtrue;
       ],
  has  edible;

Object bottle_dm "little bottle"
  with name 'little' 'bottle' 'label' 'drink' 'me' 'paper',
       description
           "A little bottle (~which certainly was not here before,~ you
            say), and round its neck a paper label with the words DRINK ME
            beautifully printed on it in large letters. It is all very
            well to say ~Drink me~, but you look first to see whether it
            is marked ~poison~ or not -- and it is not.",
       before [;
           Drink, Eat:
               if (drink_timer > 0 || alice_size == 1)
                   "There is only a swallow left, and you had rather see
                    how the first one turns out.";
               Achieved(T_DRINK);
               drink_timer = 2;
               "This bottle is not marked ~poison~, so you venture to
                taste it, and find it very nice (it has, in fact, a sort
                of mixed flavour of cherry-tart, custard, pineapple, roast
                turkey, toffee, and hot buttered toast), and you very soon
                finish it off.^^~What a curious feeling!~ you say. ~I must
                be shutting up like a telescope.~ (Something is certainly
                happening, at its own unhurried pace.)";
       ];

! The Rabbit's dropped fan and gloves, in the hall.

Object hall_fan "little fan"
  with name 'fan' 'little',
       description
           "The White Rabbit's fan, of white paper and quite small -- or
            it was small; it fits your hand better every minute, come to
            think of it, and the hall is very hot.",
       daemon [;
           if (self notin player) { StopDaemon(self); rfalse; }
           if (alice_size > 0) {
               alice_size--;
               switch (alice_size) {
                   2: "^It is very hot in here, and you keep fanning
                       yourself as you talk. ~Dear, dear! How queer
                       everything is today!~ -- and then you look down at
                       your own hand, and find you have put on one of the
                       Rabbit's little white kid gloves while you were
                       talking. ~How can I have done that?~ you think. ~I
                       must be growing small again.~ (You are: you are
                       your usual height, and going down.)";
                   1: "^You are shrinking rapidly -- you are barely a foot
                       high now -- and you soon make out the cause of it:
                       it is the fan you are holding! You had better drop
                       it quickly, before there is nothing left of you at
                       all.";
                   0: StopDaemon(self);
                       move self to LongHall;
                       "^You drop the fan hastily, just in time to avoid
                       shrinking away altogether -- indeed it slips from
                       your fingers of its own accord, which is fortunate,
                       for you had quite forgotten to let go. ~That was a
                       narrow escape!~ you say, a good deal frightened at
                       the sudden change, but very glad to find yourself
                       still in existence: you are barely three inches
                       high.";
               }
           }
           rfalse;
       ],
       before [;
           Take: StartDaemon(self);
           Drop:
               if (alice_size >= 1 && alice_size < 2) {
                   StopDaemon(self);
                   move self to LongHall;
                   Achieved(T_FAN);
                   "You drop the fan hastily, just in time to avoid
                    shrinking away altogether. ~That was a narrow
                    escape!~ you say, very glad to find yourself still in
                    existence; ~and now for the garden!~ -- though the
                    garden, it must be said, is as locked as ever, and
                    the golden key is lying on the glass table as before,
                    and the pool of tears is all round your ankles.";
               }
               StopDaemon(self);
       ];

Object kid_gloves "pair of white kid gloves"
  with name 'white' 'kid' 'gloves' 'glove' 'pair',
       article "a",
       description
           "A dainty pair of white kid gloves, dropped by the White Rabbit
            in his fright. They are much too small for you at most of your
            sizes, and much too large at the rest.",
       before [;
           Wear: if (alice_size <= 1)
                   "You put one on, in an absent sort of way. It fits,
                    which is a bad sign: you must be a good deal smaller
                    than you were.";
                 "They are far too small for you at present.";
       ];

! The Hall scene daemon: the conscientious door, the appearing bottle,
! the crying, and the Rabbit's second dash.

Object HallScene "(hall scene)"
  with daemon [;
           ! The DRINK ME potion works, slowly.
           if (drink_timer > 0) {
               drink_timer--;
               if (drink_timer == 0) {
                   alice_size = 1;
                   if (location == LongHall)
                       print "^And so it is indeed: you are now only ten
                           inches high, and your face brightens up at the
                           thought that you are now the right size for
                           going through the little door into that lovely
                           garden. (First, however, you wait a few
                           minutes to see if you are going to shrink any
                           further: you feel a little nervous about
                           this; ~for it might end, you know,~ you say to
                           yourself, ~in my going out altogether, like a
                           candle.~ But nothing more happens.)^";
                   HallSizeCheck();
               }
           }
           ! The conscientious little door.
           if (hall_door_open && hall_door_timer > 0) {
               hall_door_timer--;
               if (hall_door_timer == 0) {
                   hall_door_open = 0;
                   give little_door locked;
                   if (golden_key in player or LongHall)
                       move golden_key to glass_table;
                   if (location == LongHall) {
                       print "^A little draught comes wandering down the
                           hall, and the little door blows shut; the lock
                           (a conscientious little lock) fastens itself;
                           and -- you may believe it or not, just as you
                           please -- the little golden key is lying on
                           the glass table as before. Things are
                           tidy-minded here, in their inconvenient way.^";
                       if (hall_bottle_out == 0) {
                           hall_bottle_out = 1;
                           move bottle_dm to glass_table;
                           print "^There seems to be no use in waiting by
                               the little door, so you go back to the
                               table, half hoping you might find another
                               key on it, or at any rate a book of rules
                               for shutting people up like telescopes:
                               this time you find a little bottle on it
                               (~which certainly was not here before~),
                               with a label round the neck saying DRINK
                               ME.^";
                       }
                   }
                   else {
                       if (hall_bottle_out == 0) {
                           hall_bottle_out = 1;
                           move bottle_dm to glass_table;
                       }
                   }
               }
           }
           ! Giant Alice, stymied at the door, cannot help crying.
           if (location == LongHall && alice_size == 3 && pool_formed == 0
               && hall_seen_garden == 1) {
               cried_beats++;
               switch (cried_beats) {
                   1: "^It is as much as you can do, lying down on one
                       side, to look through into the garden with one eye;
                       but to get through is more hopeless than ever. You
                       feel a great sob coming.";
                   2: "^~You ought to be ashamed of yourself,~ you say, ~a
                       great girl like you, to go on crying in this way!
                       Stop this moment, I tell you!~ But you go on all
                       the same.";
                   3: pool_formed = 1;
                      "^You shed gallons of tears, until there is a large
                       pool all round you, about four inches deep, and
                       reaching half down the hall. (There: it is done
                       now, and can always be swum in later.)";
               }
           }
           ! The glass box comes to notice once one is small and needy.
           if (location == LongHall && alice_size < 2
               && glass_box has concealed) {
               give glass_box ~concealed;
               move glass_box to LongHall;
               print "^Soon your eye falls on a little glass box lying
                   under the table: you never noticed it before, but
                   then, it is the sort of table things appear under.^";
           }
           ! Small Alice, wet floor: the pool claims her (Chapter II).
           if (location == LongHall && chapter < 3 && pool_formed
               && alice_size <= 1 && hall_fan notin player) {
               SlipIntoPool();
               rtrue;
           }
           ! The White Rabbit trots back through, splendidly dressed.
           if (location == LongHall && pool_formed == 1
               && hallrabbit_stage < 3) {
               hallrabbit_stage++;
               switch (hallrabbit_stage) {
                   1: move hall_rabbit to LongHall;
                      "^After a time you hear a little pattering of feet
                       in the distance, and you hastily dry your eyes to
                       see what is coming. It is the White Rabbit
                       returning, splendidly dressed, with a pair of white
                       kid gloves in one hand and a large fan in the
                       other, trotting along in a great hurry and
                       muttering to himself, ~Oh! the Duchess, the
                       Duchess! Oh! won't she be savage if I've kept her
                       waiting!~";
                   2: "^The Rabbit is coming nearer. You feel so desperate
                       that you are ready to ask help of anyone. (You
                       might simply SPEAK TO him -- politely, of course:
                       ~If you please, sir--~)";
                   3: RabbitDropsFan();
               }
           }
           rfalse;
       ];

Object hall_rabbit "White Rabbit"
  with name 'white' 'rabbit' 'sir',
       description
           "The White Rabbit, splendidly dressed, with a pair of white kid
            gloves in one hand and a large fan in the other, and lateness
            written all over him.",
       life [;
           Ask, Tell, Answer: RabbitDropsFan(); rtrue;
       ],
       before [;
           Take, Touch: RabbitDropsFan(); rtrue;
       ],
  has  animate;

[ RabbitDropsFan;
    if (hall_rabbit notin LongHall) rfalse;
    hallrabbit_stage = 3;
    remove hall_rabbit;
    move hall_fan to LongHall;
    move kid_gloves to LongHall;
    "You begin, in a low, timid voice, ~If you please, sir--~ The Rabbit
     starts violently, drops the white kid gloves and the fan, and skurries
     away into the darkness as hard as he can go. The fan and gloves lie
     where they fell. It is very hot in this hall; a fan would be a
     comfort, if fans down here did nothing but fanning.";
];

! ==========================================================================
!   CHAPTER II-III -- the Pool of Tears and the Caucus-Race
! ==========================================================================

Object PoolOfTears "The Pool of Tears"
  with description
           "Salt water in every direction: a pool that would do credit to
            a small sea, though you know perfectly well how it came here,
            and who wept it, and at what size. Swimming keeps your chin
            above water, and that is about all it does.",
       cant_go [; return SwimAbout(); ],
       n_to [; return SwimAbout(); ],
       s_to [; return SwimAbout(); ],
       e_to [; return SwimAbout(); ],
       w_to [; return SwimAbout(); ],
       out_to [; return SwimAbout(); ],
  has  light;

[ SwimAbout;
    if (mouse_leads)
        "The Mouse is swimming for the shore: better FOLLOW it than
         flounder at random.";
    if (pool_mouse in PoolOfTears)
        "You swim about, but every direction is equally wet. The Mouse, on
         the other hand, looks like a person of local knowledge.";
    "You swim about, trying to find your way out; but every direction is
     equally wet, and none of them is a shore yet.";
];

Object -> pool_water "salt water"
  with name 'water' 'salt' 'pool' 'tears' 'sea',
       description
           "Your own tears, four inches deep when you were the other size,
            and practically an ocean now.",
       before [;
           Drink, Taste: "Salt, as you have every reason to know.";
           Swim, Enter: return SwimAbout();
       ],
  has  scenery;

Object -> pool_mouse "Mouse"
  with name 'mouse',
       description
           "At first you thought it must be a walrus or hippopotamus; but
            then you remembered how small you are now, and it is only a
            mouse, that has slipped in like yourself: whiskers, anxious
            eyes, and a long and interesting tail.",
       life [;
           Ask, Tell, Answer:
               if (second == 'dinah' or 'cat' or 'cats' or 'dog' or 'dogs'
                   or 'terrier') {
                   MouseOffended(); rtrue;
               }
               return MouseChat();
           Kiss: "It would take that as a very great liberty, or possibly
               as an attempted mouthful.";
           Attack: MouseOffended(); rtrue;
       ],
  has  animate concealed;

[ MouseChat;
    if (mouse_leads)
        "~The shore, the shore,~ says the Mouse, rather bubbily. ~Histories
         are for dry land.~ (You had better FOLLOW it.)";
    if (mouse_offense > 0)
        "The Mouse eyes you with deep suspicion, and swims a little
         further off. An apology might answer. (You could simply say you
         are SORRY.)";
    mouse_leads = 1;
    "~O Mouse,~ you begin (it seems the right way of speaking to a mouse:
     you remember your brother's Latin Grammar: a mouse -- of a mouse --
     to a mouse -- a mouse -- O mouse!), ~do you know the way out of this
     pool? I am very tired of swimming about here, O Mouse!~^^The Mouse
     looks at you rather inquisitively, seems to wink with one of its
     little eyes, and says in a low trembling voice: ~Let us get to the
     shore, and then I'll tell you my history, and you'll understand why
     it is I hate cats and dogs.~ It strikes out for a shore you cannot
     yet see. (You had better FOLLOW it.)";
];

[ MouseOffended;
    mouse_offense++;
    mouse_leads = 0;
    if (mouse_offense == 1)
        "~Not like cats!~ cries the Mouse, in a shrill, passionate voice.
         ~Would YOU like cats if you were me?~ It is bristling all over,
         and you feel certain it must be really offended. (You might say
         you are SORRY.)";
    "The Mouse is swimming away from you as hard as it can go, and making
     quite a commotion in the pool as it goes. (SORRY, said softly, has
     been known to bring it back.)";
];

[ PoolSay;
    if (location == LongHall)
        "You say it to the empty hall, which takes no notice: the lamps
         burn on, and the doors stay locked.";
    if (TopicHas('sorry') || TopicHas('pardon') || TopicHas('apologise')
        || TopicHas('apologize')) return DoApology();
    if (TopicHas('chatte') || TopicHas('ou') || TopicHas('est')) {
        mouse_offense++;
        mouse_leads = 0;
        "~Ou est ma chatte?~ you say, which is the first sentence in your
         French lesson-book. The Mouse gives a sudden leap out of the
         water, and seems to quiver all over with fright. ~Oh, I beg your
         pardon!~ you cry hastily. ~I quite forgot you didn't like cats.~
         (It appears French cats are quite as alarming as English ones.
         You had better say you are SORRY, in whatever language.)";
    }
    "You say it aloud, treading water; the pool swallows most of it.";
];

Object PoolScene "(pool scene)"
  with daemon [;
           if (location ~= PoolOfTears) rfalse;
           pool_stage++;
           switch (pool_stage) {
               1: "^~It was much pleasanter at home,~ you think, ~when one
                   wasn't always growing larger and smaller. I almost wish
                   I hadn't gone down that rabbit-hole -- and yet -- and
                   yet -- it's rather curious, you know, this sort of
                   life!~";
               2: give pool_mouse ~concealed;
                  move pool_mouse to PoolOfTears;
                  "^Just then you hear something splashing about in the
                   pool a little way off: it is a Mouse, that has slipped
                   in like yourself. ~Would it be of any use, now,~ you
                   think, ~to speak to this mouse? Everything is so
                   out-of-the-way down here, that I should think very
                   likely it can talk: at any rate, there's no harm in
                   trying.~";
               3: if (pool_mouse in PoolOfTears && mouse_leads == 0
                      && mouse_offense == 0)
                      "^The Mouse paddles in a circle, keeping one anxious
                       eye upon you. It is clearly waiting to be spoken
                       to properly. (ASK MOUSE ABOUT THE WAY OUT, perhaps;
                       and perhaps do not mention You-Know-Who at home.)";
               default: rfalse;
           }
       ];

! Following the mouse to shore is handled by the Follow verb (verbs.h),
! which calls this:

[ MouseToShore;
    if (mouse_leads == 0)
        "You paddle after the Mouse, but it keeps its distance: it does
         not yet regard you as a person to be led anywhere.";
    Achieved(T_SHORE);
    chapter = 3;
    print "You swim after the Mouse, and it is high time to go, for the
        pool is getting quite crowded with the birds and animals that have
        fallen into it: there is a Duck and a Dodo, a Lory and an Eaglet,
        and several other curious creatures. The whole party swims to the
        shore.^";
    remove pool_mouse;
    PlayerTo(SandyShore);
    rtrue;
];

! --------------------------------------------------------------------------
! The shore, and the Caucus-Race.
! --------------------------------------------------------------------------

Object SandyShore "Sandy Shore"
  with description [;
           print "A strip of sand and shingle under a low bank, with the
               pool of tears shrinking modestly away behind it. ";
           if (shore_stage < 6)
               print "Assembled on the bank is as queer-looking a party as
                   you ever saw: birds with draggled feathers, animals
                   with their fur clinging close to them, all dripping
                   wet, cross, and uncomfortable.";
           else
               print "The bank is empty now: the whole party has melted
                   away on one excuse or another, and the sand keeps its
                   own counsel.";
           if (shore_stage >= 7)
               print " A little path runs east, in the direction the White
                   Rabbit pointed.";
           new_line;
       ],
       e_to [;
           if (shore_stage < 7)
               "The path east has not been pointed out to you yet; and on
                this shore, things happen in their order.";
           chapter = 4;
           return OutsideRabbitHouse;
       ],
       w_to "The country that way is all wet sand and disinclination.",
       n_to "The bank is too crumbly to climb, and the party (or the
            memory of it) is in the way.",
       s_to [;
           "The pool lies that way, and you have had quite enough of
            swimming in salt water for one dream.";
       ],
  has  light;

Object -> shore_pool "pool of tears"
  with name 'pool' 'tears' 'water' 'sea',
       description "It has shrunk back to a respectful distance, glinting.",
       before [; Enter, Swim: "Once was quite enough."; ],
  has  scenery;

Object -> shore_mouse "Mouse"
  with name 'mouse',
       description
           "The Mouse, a person of some authority among the party, still
            very wet and very dignified about it.",
       life [;
           Ask, Tell, Answer:
               if (second == 'dinah' or 'cat' or 'cats' or 'dog' or 'dogs') {
                   ShoreDinah(); rtrue;
               }
               if (second == 'history' or 'tale' or 'tail' or 'story')
                   return MouseTale();
               if (shore_stage == 0)
                   "~Sit down, all of you, and listen to me,~ says the
                    Mouse, with an important air. ~I'll soon make you dry
                    enough!~ (You had better LISTEN.)";
               "The Mouse is too dignified, and too wet, for small talk.";
       ],
  has  animate;

Object -> shore_dodo "Dodo"
  with name 'dodo',
       description
           "A Dodo: solemn, extinct, and quite unembarrassed about either.
            When it thinks, it presses one finger to its forehead (the
            position you usually see Shakespeare in, in the pictures of
            him).",
       life [;
           Ask, Tell, Answer:
               if (shore_stage == 1) {
                   shore_stage = 2;
                   "~What I was going to say,~ says the Dodo in an
                    offended tone, ~was, that the best thing to get us dry
                    would be a Caucus-race.~ ~What IS a Caucus-race?~ you
                    ask. ~Why,~ says the Dodo, ~the best way to explain it
                    is to do it.~ (It marks out a race-course, in a sort
                    of circle -- ~the exact shape doesn't matter,~ it says
                    -- and places the whole party along it, here and
                    there. Evidently one begins running when one likes,
                    and leaves off when one likes. You might simply
                    RUN.)";
               }
               "The Dodo bows, solemnly.";
           Give, Receive:
               if (noun == thimble) return ThimbleCeremony();
               "The Dodo examines it solemnly and hands it back.";
       ],
  has  animate;

Object -> shore_crowd "queer-looking party"
  with name 'party' 'crowd' 'creatures' 'birds' 'animals' 'everybody'
            'duck' 'lory' 'eaglet' 'crab' 'magpie' 'canary' 'all',
       description
           "A Duck and a Dodo, a Lory and an Eaglet, an old Crab with her
            daughter, a Magpie, a Canary with its children, and several
            other curious creatures, all dripping and cross. They have the
            air of persons expecting things to be done for them.",
       life [;
           Ask, Tell, Answer:
               if (second == 'dinah' or 'cat' or 'cats')
                   return ShoreDinah();
               "They all talk at once, which comes to the same thing as
                nobody talking at all.";
           Give, Receive:
               if (noun == comfits) return ComfitPrizes();
               if (noun == thimble)
                   "~Hand it over HERE,~ says the Dodo, solemnly: the
                    presenting of prizes is evidently the Dodo's
                    department.";
               "They crowd round, look at it, and lose interest in a body.";
       ],
  has  animate;

[ ComfitPrizes;
    if (shore_stage < 3)
        "Nobody has won anything yet, so nobody can want a prize yet: even
         here, that is the order things go in.";
    if (prizes_given)
        "The comfits went round already, exactly one apiece.";
    prizes_given = 1;
    Achieved(T_COMFITS);
    "In some despair you put your hand in your pocket and pull out the box
     of comfits (luckily the salt water has not got into it), and hand
     them round as prizes. There is exactly one apiece, all round. The
     eating causes some noise and confusion, as the large birds complain
     that they cannot taste theirs, and the small ones choke and have to
     be patted on the back; but it is over at last.^^~But she must have a
     prize herself, you know,~ says the Mouse. ~Of course,~ the Dodo
     replies very gravely. ~What else have you got in your pocket?~ it
     goes on, turning to you.";
];

[ ThimbleCeremony;
    if (prizes_given == 0)
        "The Dodo looks at the thimble with grave interest, but the
         proper moment for prizes has not yet arrived.";
    if (thimble_given)
        "The ceremony has been performed once, and even a Dodo cannot make
         it solemn twice.";
    thimble_given = 1;
    shore_stage = 4;
    Achieved(T_THIMBLE);
    move thimble to player;
    "~Only a thimble,~ you say sadly, and hand it over. Then they all
     crowd round you once more, while the Dodo solemnly presents it back,
     saying ~We beg your acceptance of this elegant thimble~; and, when it
     has finished this short speech, they all cheer.^^It is all very
     absurd, but they all look so grave that you dare not laugh; and as
     you cannot think of anything to say, you simply bow, and take the
     thimble, looking as solemn as you can.";
];

[ ShoreSay;
    if (TopicHas('dinah') || TopicHas('cat') || TopicHas('cats'))
        return ShoreDinah();
    if (shore_stage >= 6)
        "You say it to the empty shore; the sand is a good listener and
         a poor conversationalist.";
    "The party receives your remark, considers it in committee, and
     returns it unopened.";
];

[ MouseTale;
    if (shore_stage < 4)
        "~You promised to tell me your history, you know,~ you remind it.
         ~All in its place,~ says the Mouse: ~drying first, history
         afterwards.~";
    if (tale_stage > 0) "The Mouse has said all the tale it means to say.";
    tale_stage = 1;
    shore_stage = 5;
    remove shore_mouse;
    "~Mine is a long and a sad tale!~ says the Mouse, turning to you and
     sighing. ~It IS a long tail, certainly,~ you say, looking down with
     wonder at the Mouse's tail; ~but why do you call it sad?~ And you
     keep on puzzling about it while the Mouse is speaking, so that your
     idea of the tale is something twisty, with a cur called Fury in it,
     and a trial with no jury or judge, and death at the very tip of
     it...^^~You are not attending!~ says the Mouse to you severely.
     ~What are you thinking of?~ ~I beg your pardon,~ you say very humbly:
     ~you had got to the fifth bend, I think?~ ~I had NOT!~ cries the
     Mouse, sharply and very angrily. ~A knot!~ you say, always ready to
     make yourself useful, and looking anxiously about. ~Oh, do let me
     help to undo it!~^^~I shall do nothing of the sort,~ says the Mouse,
     getting up and walking away. ~You insult me by talking such
     nonsense!~ And it stalks off along the shore, deaf to all calling
     after.^^You feel very lonely and low-spirited all at once; and at
     such times one does so miss one's cat. (You might SAY so -- though
     whether the company would thank you for the subject is another
     question.)";
];

[ ShoreDinah;
    if (shore_stage < 5)
        "Something warns you to keep quiet about cats until the party is
         drier and better disposed.";
    shore_stage = 6;
    remove shore_mouse; remove shore_dodo; remove shore_crowd;
    "~I wish I had our Dinah here, I know I do!~ you say aloud, addressing
     nobody in particular. ~And who is Dinah, if I might venture to ask?~
     says the Lory. You reply eagerly, for you are always ready to talk
     about your pet: ~Dinah's our cat. And she's such a capital one for
     catching mice, you can't think! And oh, I wish you could see her
     after the birds!~^^This speech causes a remarkable sensation. Some of
     the birds hurry off at once; one old Magpie begins wrapping itself up
     very carefully, remarking ~I really must be getting home; the
     night-air doesn't suit my throat!~ and a Canary calls out in a
     trembling voice to its children, ~Come away, my dears! It's high time
     you were all in bed!~ On various pretexts they all move off, and you
     are soon left alone.";
];

Object ShoreScene "(shore scene)"
  with daemon [;
           if (location ~= SandyShore) rfalse;
           ! Race running: handled by the Run action setting dry_run.
           if (shore_stage == 2 && race_on == 0) {
               race_on = 1;
               rfalse;
           }
           if (shore_stage == 6) {
               shore_stage = 7;
               move shore_rabbit to SandyShore;
               "^~I wish I hadn't mentioned Dinah!~ you say to yourself in
                a melancholy tone. ~Nobody seems to like her, down here,
                and I'm sure she's the best cat in the world!~ In a little
                while, however, you hear a little pattering of footsteps
                in the distance: it is the White Rabbit, trotting slowly
                back again, looking anxiously about as it goes, as if it
                had lost something, and muttering ~The Duchess! The
                Duchess! Oh my dear paws! Oh my fur and whiskers! She'll
                get me executed, as sure as ferrets are ferrets! Where CAN
                I have dropped them, I wonder?~";
           }
           if (shore_stage == 7 && shore_rabbit in SandyShore
               && shore_rabbit hasnt general) {
               give shore_rabbit general;
               "^Very soon the Rabbit notices you, and calls out in an
                angry tone, ~Why, Mary Ann, what ARE you doing out here?
                Run home this moment, and fetch me a pair of gloves and a
                fan! Quick, now!~ -- and it points along the little path
                to the east. He has taken you for his housemaid! How
                surprised he'll be when he finds out who you are -- but
                you had better take him his fan and gloves; that is, if
                you can find them.";
           }
           rfalse;
       ];

Object shore_rabbit "White Rabbit"
  with name 'white' 'rabbit',
       description
           "The White Rabbit, hunting anxiously about the shore, and
            plainly convinced that you are Mary Ann, his housemaid.",
       life [;
           Ask, Tell, Answer:
               "~Gloves! A fan! Quick, now!~ says the Rabbit, in no mood
                for explanations, pointing east. There is nothing for it
                but to go and be Mary Ann for the present.";
       ],
  has  animate;

! Called from the Run action in verbs.h.
[ CaucusRun;
    if (location ~= SandyShore)
        "You run a little way, for the exercise, and stop again.";
    if (shore_stage == 0 or 1)
        "There is nothing to run for yet: the party is still consulting
         about how to get dry.";
    if (shore_stage > 2) "The race is over: everybody has won.";
    dry_run++;
    switch (dry_run) {
        1: "You begin running when you like, along the Dodo's circle. Some
            of the party set off at the same moment, some later; the Duck
            runs in short professional bursts; nobody counts anything.
            (Your clothes are beginning to dry nicely.)";
        2: "You run on. The exact shape of the course doesn't matter, the
            Dodo said, and the party is taking full advantage of this:
            the Eaglet passes you twice going opposite ways. (Drier
            still.)";
        default:
            shore_stage = 3;
            "When the party have been running half an hour or so, and are
             quite dry again, the Dodo suddenly calls out ~The race is
             over!~ and they all crowd round it, panting, and asking ~But
             who has won?~^^This question the Dodo cannot answer without a
             great deal of thought, and it stands for a long time with one
             finger pressed upon its forehead, while the rest wait in
             silence. At last it says: ~EVERYBODY has won, and all must
             have prizes.~ ~But who is to give the prizes?~ quite a chorus
             of voices asks. ~Why, SHE, of course,~ says the Dodo,
             pointing at you with one finger; and the whole party at once
             crowds round you, calling out in a confused way, ~Prizes!
             Prizes!~";
    }
];

! Listening to the Mouse's dry history.
[ ShoreListen;
    if (shore_stage == 0) {
        shore_stage = 1;
        "~Ahem!~ says the Mouse with an important air. ~Are you all ready?
         This is the driest thing I know. Silence all round, if you
         please! William the Conqueror, whose cause was favoured by the
         pope, was soon submitted to by the English, who wanted leaders,
         and had been of late much accustomed to usurpation and
         conquest...~^^It goes on in this way for some time -- Edwin and
         Morcar, the earls of Mercia and Northumbria, declare for
         somebody; even Stigand, the patriotic archbishop of Canterbury,
         finds it advisable -- ~Found WHAT?~ says the Duck. ~Found IT,~
         the Mouse replies rather crossly: ~of course you know what `it'
         means.~ ~I know what `it' means well enough, when I find a
         thing,~ says the Duck: ~it's generally a frog or a worm. The
         question is, what did the archbishop find?~^^The Mouse hurries
         on unhearing: ~How are you getting on now, my dear?~ it says,
         turning to you. ~As wet as ever,~ you say in a melancholy tone:
         ~it doesn't seem to dry me at all.~ ~In that case,~ says the Dodo
         solemnly, rising to its feet, ~I move that the meeting adjourn,
         for the immediate adoption of more energetic remedies--~ ~Speak
         English!~ says the Eaglet. ~I don't know the meaning of half
         those long words, and, what's more, I don't believe you do
         either!~";
    }
    if (shore_stage == 4) return MouseTale();
    "You listen: wind, water, and the sound of a party waiting for
     somebody else to make the next move.";
];

! ==========================================================================
!   CHAPTER IV -- the Rabbit's house, and the puppy
! ==========================================================================

Object OutsideRabbitHouse "Outside the Rabbit's House"
  with description [;
           print "A neat little house stands here, and on the door is a
               bright brass plate with the name W. RABBIT engraved upon
               it. ";
           if (rh_stage >= 12)
               print "A crowd of little animals and birds mills anxiously
                   about outside -- guinea-pigs, a lizard held up between
                   two of them, the Rabbit fussing at the centre. ";
           print "The way back to the shore lies west";
           if (puppy_stage > 0 || rh_stage >= 12)
               print ", and a thick wood begins to the north";
           print ".";
           new_line;
       ],
       in_to [; return EnterRabbitHouse(); ],
       n_to [;
           if (rh_stage >= 12) return ThickWood;
           "The thick wood can wait: you are on an errand for a Rabbit,
            absurd as that sounds when one says it aloud.";
       ],
       w_to SandyShore,
       e_to "Fields, hedges, and no errands in that direction.",
  has  light;

[ EnterRabbitHouse;
    if (rh_stage >= 12)
        "Once was quite enough. The house has had all of you it can
         hold, and the crowd at the door feels strongly on the subject.";
    print "You go in without knocking, and hurry upstairs, in great fear
        lest you should meet the real Mary Ann and be turned out of the
        house before you have found the fan and gloves.^";
    PlayerTo(TidyRoom);
    rtrue;
];

Object -> rh_plate "brass plate"
  with name 'brass' 'plate' 'name' 'door' 'plaque',
       description "W. RABBIT, engraved and polished. The W., you suppose,
           is for something like Warren.",
  has  scenery;

Object -> rh_house "neat little house"
  with name 'house' 'neat' 'little' 'windows' 'chimney',
       description [;
           if (rh_stage >= 4 && rh_stage < 12)
               "It is a very well-kept little house, apart from the arm
                sticking out of an upper window. The arm is yours, in a
                manner of speaking, which makes criticism awkward.";
           "A very well-kept little house, two storeys and a chimney, of
            exactly the kind a rabbit of standing would keep.";
       ],
       before [; Enter: return EnterRabbitHouse(); ],
  has  scenery;

Object TidyRoom "Tidy Little Room"
  with description [;
           if (rh_stage >= 1 && rh_stage < 12)
               "There is no describing the room from in here any more:
                you ARE the room, very nearly. One arm is out of the
                window, one foot is up the chimney, and your head is bent
                against the ceiling. You can do no more, whatever
                happens.";
           print "A tidy little room with a table in the window";
           if (rh_fan in rh_table || rh_gloves in rh_table)
               print ", and on it (as you hoped) a fan and two or three
                   pairs of tiny white kid gloves";
           print ". By the looking-glass stands a little bottle";
           if (rh_bottle has general) print ", empty now";
           print ". The stairs lead down and out.";
           new_line;
       ],
       d_to [; return LeaveTidyRoom(); ],
       out_to [; return LeaveTidyRoom(); ],
       cant_go "The room offers a window, a chimney, and the stairs; and
            at your present size, possibly fewer.",
  has  light;

[ LeaveTidyRoom;
    if (rh_stage >= 1 && rh_stage < 12)
        "You cannot so much as turn round, let alone manage stairs. The
         window has one of your arms and the chimney one of your feet,
         and the door opens inwards against your elbow besides.";
    if (rh_stage >= 12) { PlayerTo(OutsideRabbitHouse); rtrue; }
    print "You slip back down the stairs";
    if (rh_fan in player && rh_gloves in player)
        print ", fan and gloves in hand";
    print ".^";
    PlayerTo(OutsideRabbitHouse);
    rtrue;
];

Object -> rh_table "table in the window"
  with name 'table' 'window',
       description "A little table, set in the window where the light is
           good for mending gloves.",
  has  supporter static;

Object -> -> rh_fan "little fan"
  with name 'fan' 'little',
       description "A little fan, the twin of the one the Rabbit dropped
           in the hall. This one, you resolve, is for delivering, not for
           holding overlong.",
       after [;
           Take: if (rh_gloves in player) FetchDone();
       ];

Object -> -> rh_gloves "pair of tiny white kid gloves"
  with name 'gloves' 'glove' 'pair' 'white' 'kid' 'tiny' 'pairs',
       article "a",
       description "Tiny white kid gloves, of the Rabbit's own dapper
           size. There were two or three pairs; you have taken one.",
       after [;
           Take: if (rh_fan in player) FetchDone();
       ];

[ FetchDone;
    if (task_done->T_FETCH) rfalse;
    Achieved(T_FETCH);
    print "^(You have the fan and a pair of gloves: exactly what the
        Rabbit sent Mary Ann for. ~How queer it seems,~ you say to
        yourself, ~to be going messages for a rabbit! I suppose Dinah'll
        be sending me on messages next!~)^";
    rfalse;
];

Object -> rh_glass "looking-glass"
  with name 'looking-glass' 'looking' 'glass' 'mirror',
       description
           "You look, at your present size, like a very small housemaid
            indeed. The glass has the grace to say nothing.",
  has  scenery;

Object -> rh_bottle "little bottle"
  with name 'little' 'bottle',
       description
           "There is no label this time with the words DRINK ME -- but you
            know something interesting is sure to happen whenever you eat
            or drink anything here.",
       before [;
           Drink, Eat:
               if (self has general) "It is quite empty now.";
               give self general;
               rh_stage = 1;
               alice_size = 3;
               StartDaemon(RabbitHouseScene);
               "You uncork it and put it to your lips. ~I know SOMETHING
                interesting is sure to happen,~ you say, ~whenever I eat
                or drink anything: I do hope it'll make me grow large
                again, for really I'm quite tired of being such a tiny
                little thing!~^^It does so indeed, and much sooner than
                you expected: before you have drunk half the bottle you
                find your head pressing against the ceiling, and have to
                stoop to save your neck from being broken. You hastily
                put the bottle down -- ~That's quite enough -- I hope I
                shan't grow any more --~^^Alas! it is too late to wish
                that! You go on growing, and growing, and very soon have
                to kneel down on the floor: in another minute there is
                not even room for that, and you try the effect of lying
                down, one elbow against the door and the other arm curled
                round your head. Still you go on growing, and, as a last
                resource, you put one arm out of the window, and one foot
                up the chimney. ~Now I can do no more, whatever happens.
                What WILL become of me?~";
       ];

Object -> rh_window "window"
  with name 'window',
       description [;
           if (rh_stage >= 1 && rh_stage < 12)
               "Your right arm is out of it up to the elbow, which is all
                the view there is.";
           "A neat window over the little table, with a view of the
            garden and an unsuspecting cucumber-frame or two.";
       ],
  has  scenery;

Object -> rh_chimney "chimney"
  with name 'chimney' 'fireplace' 'flue',
       description [;
           if (rh_stage >= 1 && rh_stage < 12)
               "Your foot is up it. The fireplace is narrow, to be sure;
                but you think you can kick a little.";
           "A narrow little fireplace, swept very clean.";
       ],
  has  scenery;

Object -> rh_cakes "little cakes"
  with name 'cake' 'cakes' 'pebble' 'pebbles' 'little',
       description
           "The pebbles that came rattling in at the window are all
            turning into little cakes as they lie on the floor; and a
            bright idea comes into your head. ~If I eat one of these
            cakes,~ you think, ~it's sure to make SOME change in my size;
            and as it can't possibly make me larger, it must make me
            smaller, I suppose.~",
       before [;
           Eat, Taste, Take: return PebbleEscape();
       ],
  has  scenery concealed;

[ PebbleEscape;
    Achieved(T_PEBBLE);
    rh_stage = 12;
    alice_size = 0;
    StopDaemon(RabbitHouseScene);
    give rh_cakes concealed; remove rh_cakes;
    print "You swallow one of the cakes, and are delighted to find that
        you begin shrinking directly. As soon as you are small enough to
        get through the door, you run out of the house, and find quite a
        crowd of little animals and birds waiting outside: the poor little
        Lizard, Bill, is in the middle, being held up by two guinea-pigs,
        who are giving it something out of a bottle. They all make a rush
        at you the moment you appear; but you run off as hard as you can,
        and soon find yourself safe in a thick wood.^^~The first thing
        I've got to do,~ you say to yourself, as you wander about, ~is to
        grow to my right size again; and the second thing is to find my
        way into that lovely garden. I think that will be the best
        plan.~^";
    PlayerTo(ThickWood);
    rtrue;
];

! The siege of the Rabbit's house.
Object RabbitHouseScene "(rabbit house scene)"
  with daemon [;
           if (location ~= TidyRoom) rfalse;
           switch (rh_stage) {
               1:  rh_stage = 2;
                   "^Luckily for you, the little bottle has now had its
                    full effect, and you grow no larger: still it is very
                    uncomfortable, and there seems no sort of chance of
                    your ever getting out of the room again. ~It was much
                    pleasanter at home,~ you think, ~when one wasn't
                    always growing larger and smaller, and being ordered
                    about by mice and rabbits... and yet -- and yet --
                    there ought to be a book written about me, that there
                    ought!~";
               2:  rh_stage = 3;
                   "^A voice outside: ~Mary Ann! Mary Ann! Fetch me my
                    gloves this moment!~ -- then a little pattering of
                    feet on the stairs. You know it is the Rabbit coming
                    to look for you, and you tremble till you shake the
                    house, quite forgetting that you are now about a
                    thousand times as large as the Rabbit, and have no
                    reason to be afraid of it. The door is pushed --
                    but the door opens inwards, and your elbow is pressed
                    hard against it, so that attempt proves a failure.
                    You hear the Rabbit say to itself, ~Then I'll go round
                    and get in at the window.~";
               3:  rh_stage = 4;
                   "^~THAT you won't!~ you think. Presently you fancy you
                    hear the Rabbit just under the window. (Your hand is
                    out there already, dangling over whatever he is
                    standing on. You might make a SNATCH in the air.)";
               4:  rh_nudge++;
                   if (rh_nudge >= 2) {
                       rh_nudge = 0;
                       "^The scrabbling under the window goes cautiously
                        on. The Rabbit is in no hurry to climb past a hand
                        the size of a dinner-table. (A well-timed SNATCH
                        might discourage the whole undertaking.)";
                   }
               5:  rh_stage = 6;
                   "^Next comes an angry voice -- the Rabbit's -- ~Pat!
                    Pat! Where are you?~ And then a voice you have never
                    heard before: ~Sure then I'm here! Digging for apples,
                    yer honour!~ ~Digging for apples, indeed!~ says the
                    Rabbit angrily. ~Here! Come and help me out of THIS!~
                    (Sounds of more broken glass.) ~Now tell me, Pat,
                    what's that in the window?~ ~Sure, it's an arrum, yer
                    honour!~ ~An arm, you goose! Who ever saw one that
                    size? Why, it fills the whole window!~ ~Sure, it does,
                    yer honour: but it's an arrum for all that.~ ~Well,
                    it's got no business there, at any rate: go and take
                    it away!~";
               6:  rh_stage = 7;
                   "^There is a long silence after this, and you can only
                    hear whispers now and then: ~Sure, I don't like it,
                    yer honour, at all, at all!~ ~Do as I tell you, you
                    coward!~ (Perhaps another SNATCH is in order; or
                    perhaps they will tire of the arm and try something
                    else.)";
               7:  rh_stage = 8;
                   "^At last comes a rumbling of little cartwheels, and
                    the sound of a good many voices all talking together:
                    ~Where's the other ladder? -- Why, I hadn't to bring
                    but one; BILL'S got the other -- Bill! fetch it here,
                    lad! -- Will the roof bear? -- Mind that loose slate
                    -- Oh, it's coming down! Heads below!~ (a loud crash)
                    ~-- Now, who did that? -- It was Bill, I fancy -- Who's
                    to go down the chimney? -- Nay, I shan't! YOU do it!
                    -- Bill's to go down -- Here, Bill! the master says
                    you're to go down the chimney!~";
               8:  rh_stage = 9; bill_tries = 0;
                   "^~Oh! So Bill's got to come down the chimney, has he?~
                    you say to yourself. ~Why, they seem to put everything
                    upon Bill! I wouldn't be in Bill's place for a good
                    deal: this fireplace is narrow, to be sure, but I
                    THINK I can kick a little!~^^You hear a little animal
                    (you can't guess of what sort) scratching and
                    scrambling about in the chimney close above your foot.
                    (Now would be the moment to KICK.)";
               9:  bill_tries++;
                   if (bill_tries % 2 == 0)
                       "^The scrambling pauses -- Bill clinging somewhere
                        in the flue, breathing hard and thinking better
                        of his profession -- and then, goaded from above
                        (~Down you go, lad, the master says so!~), it
                        starts down again. (KICK!)";
                   "^The scratching and scrambling comes lower. ~This is
                    Bill,~ you say to yourself. (KICK, before he arrives!)";
               10: rh_stage = 11;
                   "^A dead silence -- and then the Rabbit's voice, grim
                    with resolution: ~We must burn the house down!~^^\
                    (There is a certain cat at home who would make short
                    work of this committee. You might SAY so, good and
                    loud: SAY DINAH, in fact.)";
               11: if (dinah_said) rfalse;
                   rh_nudge++;
                   if (rh_nudge >= 2) {
                       rh_nudge = 0;
                       "^Outside, a business-like discussion of kindling
                        has begun. (Say something! SAY DINAH -- loudly!)";
                   }
               12: rfalse;
           }
           rfalse;
       ];

! SNATCH, KICK and SAY DINAH handlers, called from verbs.h.

[ RabbitSnatch;
    if (location ~= TidyRoom || rh_stage < 3 || rh_stage >= 12)
        "There is nothing here worth snatching at.";
    snatches++;
    if (rh_stage == 4 or 3) {
        rh_stage = 5;
        "You spread out your hand and make a snatch in the air. You do not
         get hold of anything, but you hear a little shriek and a fall,
         and a crash of broken glass -- from which you conclude that it is
         just possible the Rabbit has fallen into a cucumber-frame, or
         something of the sort.";
    }
    if (rh_stage == 6 or 7) {
        rh_stage = 7;
        "You spread out your hand again, and make another snatch in the
         air. This time there are TWO little shrieks, and more sounds of
         broken glass. ~What a number of cucumber-frames there must be!~
         you think. ~I wonder what they'll do next!~";
    }
    "You snatch at the air, but the moment for snatching has passed;
     matters outside have moved on to committee work.";
];

[ BillKick;
    if (location ~= TidyRoom || rh_stage ~= 9)
        "You kick at nothing in particular, which is at least good
         exercise for a person your size.";
    rh_stage = 10;
    Achieved(T_BILL);
    "You draw your foot as far down the chimney as you can, and wait until
     the little animal is scratching and scrambling just above it; then,
     saying to yourself ~This is Bill,~ you give one sharp kick.^^The
     first thing you hear is a general chorus of ~There goes Bill!~ then
     the Rabbit's voice -- ~Catch him, you by the hedge!~ -- then silence,
     and then another confusion of voices: ~Hold up his head -- Brandy now
     -- Don't choke him -- How was it, old fellow?~ Last comes a little
     feeble squeaking voice (~That's Bill,~ you think): ~Well, I hardly
     know -- No more, thank ye; I'm better now... all I know is, something
     comes at me like a Jack-in-the-box, and up I goes like a
     sky-rocket!~ ~So you did, old fellow!~ say the others.";
];

[ RabbitHouseSay;
    if (rh_stage == 11 && dinah_said == 0
        && (TopicHas('dinah') || TopicHas('cat'))) {
        dinah_said = 1;
        Achieved(T_DINAH);
        move rh_cakes to TidyRoom;
        give rh_cakes ~concealed;
        "You call out, as loud as you can, ~If you do, I'll set Dinah at
         you!~^^There is a dead silence instantly. ~I wonder what they
         WILL do next!~ you think. ~If they had any sense, they'd take the
         roof off.~ After a minute or two they begin moving about again,
         and you hear the Rabbit say, ~A barrowful will do, to begin
         with.~ ~A barrowful of WHAT?~ you think -- but you have not long
         to doubt, for the next moment a shower of little pebbles comes
         rattling in at the window, and some of them hit you in the face.
         And now -- how curious -- the pebbles are all turning into little
         cakes as they lie on the floor. (You might EAT one: it can't
         possibly make you larger, so it must make you smaller, you
         suppose.)";
    }
    if (location == TidyRoom && rh_stage >= 1 && rh_stage < 11)
        "You say it aloud; the house creaks round you by way of applause,
         and the committee outside pauses respectfully and then goes on
         committing.";
    "You say it aloud, to no very great effect.";
];

! --------------------------------------------------------------------------
! The thick wood and the enormous puppy.
! --------------------------------------------------------------------------

Object ThickWood "Thick Wood"
  with description [;
           print "A thick wood -- thick, that is, from where you stand,
               which is some three inches above the moss. Blades of grass
               go by you like park railings, and a buttercup makes
               serviceable shade. ";
           switch (puppy_stage) {
               0: print "Directly in your path, an enormous puppy is
                   looking down at you with large round eyes, feebly
                   stretching out one paw to touch you. A little bit of
                   stick lies near a great thistle.";
               1: print "The puppy is delighted beyond words with the
                   game of the stick, and is charging about like a
                   cart-horse at a fair. The great thistle stands close
                   by.";
               2: print "The puppy sits a good way off, panting, tongue
                   out, its great eyes half shut. The way south lies
                   open past it.";
           }
           new_line;
       ],
       s_to [;
           if (puppy_stage < 2)
               "The puppy is between you and the way south, and at your
                present size a puppy is a natural disaster with paws. (It
                wants a game: perhaps something to worry -- a stick, say
                -- would occupy it.)";
           chapter = 5;
           print "You steal away while its eyes are half shut, and run
               till you are quite tired and out of breath, and the
               puppy's bark sounds faint in the distance. ~And yet what a
               dear little puppy it was!~ you say, leaning against a
               buttercup to rest. ~I should have liked teaching it
               tricks very much, if -- if I'd only been the right size to
               do it!~^";
           return Clearing;
       ],
       n_to "The wood closes that way in a wall of grass-stems; and
            besides, the crowd at the Rabbit's house is in no mood for
            you.",
       cant_go "Grass like park railings, and daisies like trees: the only
            promising way is south, past the puppy.",
  has  light;

Object -> wood_puppy "enormous puppy"
  with name 'enormous' 'puppy' 'dog' 'terrier',
       description [;
           switch (puppy_stage) {
               0: "An enormous puppy -- enormous, at any rate, from three
                   inches: round eyes the size of tea-trays, and a paw
                   feebly stretched out to touch you. ~Poor little
                   thing!~ you say, coaxingly; privately you are terribly
                   frightened that it might be hungry, in which case it
                   would very likely eat you up in spite of all your
                   coaxing.";
               1: "It is having the time of its young life: short charges
                   forward at the stick, long scrambles back, barking
                   hoarsely all the while.";
               2: "Panting, sitting, blinking: a puppy entirely out of
                   puppy for the moment.";
           }
       ],
       life [;
           Ask, Tell, Answer:
               "You try hard to whistle to it, in a coaxing tone; it
                cocks its head, which at that scale is like a house
                deciding something.";
           Attack: "It outweighs you several hundred times over, and
               worse, it would enjoy it.";
           Kiss: "At your size, that is not a kiss, it is mountaineering.";
           Give, Receive, ThrowAt:
               if (noun == wood_stick) return StickGame();
       ],
  has  animate;

Object -> wood_stick "little bit of stick"
  with name 'stick' 'bit' 'twig' 'little',
       description
           "A little bit of stick, which is to say, to a puppy that size,
            a beloved and long-lost toy.",
       before [;
           ThrowAt, ThrownAt: return StickGame();
       ];

Object -> wood_thistle "great thistle"
  with name 'thistle' 'great',
       description
           "A great thistle, spiny and dependable: exactly the sort of
            fortification a person three inches high learns to value.",
       before [;
           Enter: return HideBehindThistle();
       ],
  has  static;

[ StickGame;
    if (puppy_stage == 2)
        "The puppy opens one eye at the stick, sighs enormously, and
         declines. It is quite worn out.";
    if (wood_stick in player || wood_stick in ThickWood) {
        move wood_stick to ThickWood;
        if (puppy_stage == 0) {
            puppy_stage = 1;
            puppy_charges = 0;
            "Hardly knowing what you do, you pick up the little bit of
             stick and hold it out -- and the puppy jumps into the air off
             all its feet at once, with a yelp of delight, and rushes at
             it, making believe to worry it. It is like a game of play
             with a cart-horse, and you are in imminent danger of being
             trampled. (Quick -- get BEHIND THE THISTLE!)";
        }
        "The puppy has the stick, in as much as anybody has anything in
         a game like this. What is wanted now is cover: the THISTLE.";
    }
    rfalse;
];

[ HideBehindThistle;
    if (location ~= ThickWood) "There is no thistle here to hide behind.";
    if (puppy_stage == 0)
        "You take up a position behind the great thistle, on general
         principles. The puppy peers at you round it, mildly puzzled: it
         still hopes you are a game of some kind. (The little bit of
         stick suggests itself.)";
    if (puppy_stage == 2)
        "The emergency is over: the puppy is spent, and the way south lies
         open.";
    puppy_charges++;
    switch (puppy_charges) {
        1: "You dodge behind the great thistle just as the puppy charges;
            the moment you appear on the other side, it rushes at the
            stick again, and tumbles head over heels in its hurry to get
            hold of it. (Keep at it: round the thistle again!)";
        2: "You run round the thistle; the puppy begins a series of short
            charges at the stick, running a very little way forwards each
            time and a long way back, barking hoarsely all the while.
            It is tiring -- the puppy, that is; though you too, rather.";
        default:
            puppy_stage = 2;
            Achieved(T_PUPPY);
            "At last, to your great relief, the puppy sits down a good way
             off, panting, with its tongue hanging out of its mouth and
             its great eyes half shut. This seems a good opportunity for
             making your escape: the way south lies open.";
    }
];
