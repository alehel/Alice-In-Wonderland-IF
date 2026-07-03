! ==========================================================================
!   verbs.h -- new grammar and the action dispatch.
!   (Included after "Grammar", so Extend directives are legal here.)
! ==========================================================================

! --------------------------------------------------------------------------
! FOLLOW.
! --------------------------------------------------------------------------

[ FollowSub;
    if (location == Riverbank) {
        if (rb_stage >= 3) return HoleGate();
        "There is nobody to follow yet; only a sister, a book, and an
         afternoon.";
    }
    if (location == LongPassage) return ChasePassage();
    if (location == PoolOfTears) return MouseToShore();
    if (location == CroquetGround && gryphon_here) return GryphonWay();
    if (location == RockyLedge && ledge_stage >= 9) return CourtRun();
    if (noun ~= nothing && noun has animate)
        "You follow it a little way; it declines to be followed any
         further, in the way of dream creatures.";
    "There is nothing here that wants following.";
];

Verb 'follow' 'chase' 'pursue'
    * -> Follow
    * noun -> Follow;

! --------------------------------------------------------------------------
! RECITE, and other set-pieces.
! --------------------------------------------------------------------------

[ ReciteSub;
    if (location == Clearing) return CaterpillarRecite();
    if (location == RockyLedge) return LedgeRecite();
    "You know quantities of poetry -- or you did this morning -- but
     nobody here has asked for any just now, and reciting uninvited is
     not done, even in a dream.";
];

Verb 'recite' 'declaim'
    * -> Recite
    * topic -> Recite;

[ KickSub; return BillKick(); ];

Verb 'kick'
    * -> Kick
    * noun -> Kick;

[ SnatchSub;
    if (location == TidyRoom) return RabbitSnatch();
    if (noun ~= nothing) <<Take noun>>;
    "You make a snatch in the air, and catch exactly what you deserve,
     which is nothing.";
];

Verb 'snatch'
    * -> Snatch
    * noun -> Snatch;

[ PinchSub;
    if (noun == the_dormouse) return DormouseStory();
    if (noun has animate)
        "Pinching is customary only at tea-parties, and then only for
         dormice.";
    "You pinch it, without result.";
];

Verb 'pinch'
    * noun -> Pinch;

[ HideVbSub; return HideBehindThistle(); ];

Verb 'hide' 'dodge'
    * -> HideVb
    * 'behind' noun -> HideVb;

[ KnockSub;
    if (location == OpenPlace) return DuchessKnock();
    "You knock, politely; nobody answers, there being nobody whose
     business it is.";
];

Verb 'knock' 'rap'
    * -> Knock
    * 'at'/'on' noun -> Knock;

[ TuckSub;
    if (noun == the_flamingo) return TuckFlamingo();
    "That is not a thing that tucks.";
];

Verb 'tuck'
    * noun -> Tuck
    * noun 'under' topic -> Tuck;

[ StrokeSub;
    if (noun == the_flamingo) return CalmFlamingo();
    if (noun == wood_puppy)
        "You reach up and pat what you can reach of it, which is one
         toe. The toe is pleased.";
    if (noun == kitchen_cat or cheshire_cat)
        "It arches what a cat arches, and goes on grinning.";
    if (noun == the_dormouse) return DormouseStory();
    if (noun has animate) "It submits, with dignity.";
    "It is none the better for it, and no worse.";
];

Verb 'stroke' 'calm' 'straighten' 'soothe' 'pet'
    * noun -> Stroke;

[ CryVbSub;
    if (location == LongHall && alice_size == 3 && hall_seen_garden
        && pool_formed == 0) {
        pool_formed = 1;
        cried_beats = 3;
        "You sit down and cry in earnest this time, shedding gallons of
         tears, until there is a large pool all round you, about four
         inches deep, and reaching half down the hall. ~You ought to be
         ashamed of yourself,~ you say, ~a great girl like you, to go on
         crying in this way! Stop this moment, I tell you!~ But you go
         on all the same.";
    }
    "You cry a little, and feel rather better for it. Wonderland is
     patient with tears; it is made of them, in places.";
];

Verb 'cry' 'weep' 'sob'
    * -> CryVb;

[ CurtseySub;
    if (location == DownTheWell)
        "You curtsey as you fall -- fancy CURTSEYING as you're falling
         through the air! Do you think you could manage it?";
    "You drop a very pretty curtsey. Somewhere, a governess is proud of
     you and cannot say why.";
];

Verb 'curtsey' 'curtsy' 'bow'
    * -> Curtsey;

[ RaceVbSub; return CaucusRun(); ];

Verb 'race' 'jog'
    * -> RaceVb;

[ XyzzySub;
    "Nothing happens: that word belongs to quite another burrow.";
];

Verb meta 'xyzzy' 'plugh'
    * -> Xyzzy;

Verb meta 'help' 'hints' 'instructions' 'commands'
    * -> Help;

Verb meta 'about' 'credits'
    * -> Help;

! --------------------------------------------------------------------------
! Croquet strokes: HIT HEDGEHOG WITH FLAMINGO, CROQUET HEDGEHOG.
! --------------------------------------------------------------------------

[ HitWithSub;
    if (noun == the_hedgehog) return CroquetStroke();
    "Hitting things settles remarkably little, even in a dream.";
];

Extend 'attack' first
    * noun 'with' held -> HitWith;

Verb 'croquet' 'strike'
    * noun -> HitWith
    * noun 'with' held -> HitWith;

! --------------------------------------------------------------------------
! Talking: TALK TO, SPEAK TO, SAY <something>, ANSWER <something>.
! --------------------------------------------------------------------------

[ TalkToSub;
    if (RunLife(noun, ##Ask)) rtrue;
    print_ret (The) noun, " has nothing particular to say just now.";
];

Verb 'talk' 'chat'
    * 'to'/'with' creature -> TalkTo
    * creature -> TalkTo;

Extend 'answer' replace
    * 'to' creature -> TalkTo
    * topic -> SayTopic;

! GIVE UP (the riddle).

[ GiveUpSub;
    if (location == TeaParty && riddle_open) return RiddleGiveUp();
    "Never give up; or at any rate, nothing hereabouts is asking to be
     given up.";
];

Extend 'give' first
    * 'up' -> GiveUp;

[ KnotVbSub;
    if (noun == queer_baby) return KnotBaby();
    "There is no obvious way of knotting that.";
];

Extend 'tie' first
    * noun -> KnotVb;

[ DanceVbSub; return JoinQuadrille(); ];

Verb 'dance'
    * -> DanceVb;

Verb 'join'
    * -> DanceVb
    * 'in' -> DanceVb
    * 'the' 'dance' -> DanceVb
    * 'dance' -> DanceVb
    * 'quadrille' -> DanceVb
    * noun -> DanceVb;
