# Alice's Adventures in Wonderland — An Interactive Fiction
## Design Document

An Inform 6 adaptation of Lewis Carroll's *Alice's Adventures in Wonderland*
(1865, public domain). The player is Alice; the game covers all twelve
chapters of the book as playable episodes. Puzzles are expansions of the
story — the player must work out *how* Alice does what the book says she
did, plus a few new challenges built from the book's own logic — but no
puzzle alters the course of the original tale.

## Voice

All prose is written in imitation of Carroll's narration:

- Long, courteous, winding sentences with parenthetical asides addressed
  to the reader ("and you may believe it or not, just as you please").
- Alice frequently talks to herself, scolds herself, and gives herself
  excellent advice which she seldom follows.
- Puns and logical inversions in the creatures' dialogue.
- Failure is dreamlike, never brutal: the dream simply rearranges itself
  and gives you another chance. There is no permanent death and no
  unwinnable state (Merciful on the classic cruelty scale).

## The Size Mechanic

The engine of the game, as of the book. Alice's size is one of:

| # | Size          | Notes |
|---|---------------|-------|
| 0 | three inches  | Caterpillar height |
| 1 | about a foot  | fits the little door, the Duchess's house |
| 2 | her usual height | default |
| 3 | nine feet and more | can reach the key on the glass table; fills rooms |

Size is changed by: the DRINK ME bottle (2 -> 1, slowly), the EAT ME cake
(1 -> 3), the Rabbit's fan (shrinks one step per turn while held — drop it
in time!), the unlabelled bottle in the Rabbit's house (-> 3), the
pebble-cakes (-> 0), and — from Chapter V onward — the two pieces of
mushroom, which give repeatable one-step changes (right bit shrinks, left
bit grows) and serve as the player's size toolkit for the rest of the game.

Dream-tidiness rule for the Long Hall: the little door, once opened, blows
shut after a few turns (its lock is a conscientious little lock and
fastens itself), and whenever it does, the golden key finds its way back
to the glass table. This reproduces the book's events exactly: on the
first visit the bottle shrinks Alice too slowly to beat the door, and only
on the second visit (with instant mushroom-nibbling) can she get through.

## Map

```
Riverbank
   |  (follow rabbit)
Rabbit-Hole -> falling down the well (scripted, marmalade jar to take)
   |
Long, Low Hall  <---------------------(door in tree)-- Wood by the Tea-Party
   |  (little door, at size 0/1, while open)                     |
   |--> Pool of Tears --> Sandy Shore (caucus race)          Tea-Party Table
   |                          | (E, sent by Rabbit)              |
Beautiful Garden          Outside the Rabbit's House --- Upstairs Room
   |                          | (W, after escape)
Croquet-Ground            Thick Wood (puppy) --- (stick, thistle)
   |  (Gryphon)               |
Rocky Ledge (Mock Turtle)  Mushroom Clearing (Caterpillar)
   |  (trial begins)          | (S)
Courtroom                 Open Place (Duchess's house) --- Peppery Kitchen
   |  (pack of cards)         | (NE, via wood w/ Cheshire Cat)
Riverbank again (finale)   Wood by the Tea-Party
```

## Chapters, gates and puzzles

**I. Down the Rabbit-Hole.**
Riverbank: drowsy afternoon, sister's book, daisies. The White Rabbit runs
by — FOLLOW RABBIT / go down the hole. Falling scene (several turns): the
player may take the ORANGE MARMALADE jar from a shelf (empty, of course; a
keepsake worth points if politely put back in a cupboard — but keeping it
is amusing too). Long Hall: locked doors, curtain hiding the little door,
golden key on a glass table, garden beyond. Bottle appears once the door
has been tried; drinking shrinks slowly, so the door blows shut: the
player learns the rule. Cake in glass box under the table -> giant; take
key; unlock; still can't fit; Alice cries (automatic; the pool gathers).

**II. The Pool of Tears.**
The Rabbit patters in; addressed, he bolts, dropping fan and gloves. The
fan shrinks Alice a step per turn while held — the puzzle is to DROP it at
size 1 and not shrink away altogether (a merciful near-miss if you
forget). Slip into the pool; meet the Mouse; do not mention cats (or
Dinah, or terriers); APOLOGIZE and swim after it to shore.

**III. A Caucus-Race and a Long Tale.**
Dripping assembly (Dodo, Lory, Eaglet, Duck, Crab, etc.). The Mouse's dry
history fails to dry anyone. The Dodo proposes a Caucus-race: RUN when you
like, stop when you like; when it ends, everybody has won. Prize puzzle:
Alice's pocket holds exactly one comfit apiece — GIVE COMFITS TO CREATURES
— and she must be given a prize herself: hand the Dodo her thimble to
receive it back with ceremony. The Mouse's tale/tail follows; offended, it
leaves; Dinah talk empties the shore; the White Rabbit arrives and
mistakes Alice for Mary Ann: "fetch me a pair of gloves and a fan!"

**IV. The Rabbit Sends in a Little Bill.**
The Rabbit's house; upstairs, fan and kid-gloves on the table, and an
unlabelled bottle by the looking-glass. Drinking it (curiosity is
irresistible, and it is the story) wedges giant Alice into the room:
scripted siege with player agency — SNATCH at the Rabbit through the
window; when scrambling is heard in the chimney, KICK (there goes Bill!);
pebbles rattle in and turn to little cakes; EAT one to shrink and run out.
In the Thick Wood an enormous puppy blocks the way: THROW THE STICK, dodge
BEHIND THE THISTLE, repeat till it tires (tiny Alice must not be trampled
— near-misses only).

**V. Advice from a Caterpillar.**
The mushroom exactly her height; LOOK ON TOP of it. The Caterpillar's
catechism: keep your temper. Politeness and patience (RECITE the poem when
asked; do not attack or insult) earn the full parting hint: one side makes
you grow taller, one side shorter. TAKE MUSHROOM gets a bit from each edge
(one in each hand, since it is perfectly round). First right-bite: chin
strikes foot; first left-bite: serpent-neck among the treetops and the
Pigeon scene. Alternate nibbles to come back to your usual height. The
bits are kept in the pockets and are the size-tool from now on. If you
enraged the Caterpillar, he crawls off without the hint — the mushroom
still works, but you experiment blind.

**VI. Pig and Pepper.**
The house is four feet high: Alice will not call on anybody at the wrong
size (nibble down to a foot). The Fish-Footman delivers the Queen's
invitation; the Frog-Footman proves that knocking is useless, for two
reasons — the anti-puzzle is simply to OPEN THE DOOR and walk in. Kitchen:
pepper, sneezing, the cook's crockery barrage (harmless, dodged in the
telling), the grinning Cheshire Cat. The Duchess flings the baby: to carry
the queer little thing safely you must HOLD IT BY ITS RIGHT EAR AND LEFT
FOOT (a sort of knot); take it outside; it grunts, it has a turn-up nose;
it is a pig; SET IT DOWN and it trots off. The Cheshire Cat on the bough
gives directions ("we're all mad here") and mentions the croquet game.

**VII. A Mad Tea-Party.**
"No room! No room!" — SIT DOWN anyway. The riddle of the raven and the
writing-desk (any answer is wrong; give up, and learn that the Hatter
hasn't the slightest idea either — points for asking). The buttery watch.
The quarrel with Time. To actually get any tea you must wait for (or
provoke) the move-round — one place on — and mind the milk-jug. Wake the
Dormouse (pinching is customary) for the treacle-well story of Elsie,
Lacie and Tillie. When the rudeness passes bearing, LEAVE — and notice,
in the wood, that one of the trees has a door leading right into it.

**VIII. The Queen's Croquet-Ground.**
Through the tree-door to the Long Hall for the mastery test: take the key
FIRST, unlock and open the little door, nibble down to a foot, and walk
through before it blows shut — into the beautiful garden at last. The
gardeners (Two, Five, Seven) painting the white rose-tree red; the
procession; the Queen's "Off with her head!" — the player must answer
"NONSENSE!" (boldly: they're only a pack of cards). When the Queen orders
the gardeners' execution, PUT THE GARDENERS IN THE FLOWERPOT before the
soldiers reach them. Croquet: a timing puzzle in three moving parts — the
flamingo must be tucked with its head down, the hedgehog must be unrolled
and nearby, and a soldier-arch must have doubled itself up in range; all
three states drift turn by turn and are clearly telegraphed; HIT THE
HEDGEHOG on the turn they align to send it through an arch (possibly the
first fair croquet stroke ever played on that ground). The Cheshire Cat's
head appears; the King, Queen and executioner dispute whether a head can
be cut off without a body; resolve it by pointing out THE CAT BELONGS TO
THE DUCHESS.

**IX. The Mock Turtle's Story.**
The Duchess, in a pepper-free temper, walks with you finding morals in
everything, until the Queen's ultimatum scatters her. The Gryphon (asleep
in the sun) is detailed to take you to the Mock Turtle: sobbing on his
ledge, once a real Turtle, schooled in Reeling and Writhing and the
branches of Arithmetic — Ambition, Distraction, Uglification and
Derision. The lessons riddle, turned on the player: ten hours the first
day, nine the next — what was the eleventh day? ANSWER: A HOLIDAY.

**X. The Lobster Quadrille.**
The dance demonstrated (JOIN IN for points and trodden toes); the whiting
and the porpoise; RECITE when ordered — the words come out all about the
Lobster, do what you will. The Turtle Soup song, interrupted by "The
trial's beginning!" — run with the Gryphon.

**XI. Who Stole the Tarts?**
The court assembles: King-as-judge (crown over wig), twelve jurors writing
their names lest they forget them, the Knave in chains, the tarts on the
table. Sneak behind Bill the Lizard and TAKE THE SQUEAKING PENCIL (he
writes with a finger thereafter). The Hatter's evidence; the cook's
pepper; all the while Alice is quietly growing. Then the name called is
"Alice!"

**XII. Alice's Evidence.**
Jumping up tips over the jury-box: PICK UP THE JURORS and set them back —
but the Lizard has gone in head-downwards and must be TURNED RIGHT WAY UP
before the trial can proceed. "What do you know about this business?" —
NOTHING (very important; unimportant, of course). Rule Forty-two. The
unsigned verses; sentence first, verdict afterwards — cry NONSENSE once
more, and when the Queen calls for your head, the winning stroke: TELL
THEM THEY'RE NOTHING BUT A PACK OF CARDS. The pack rises, flies down, and
becomes dead leaves; Alice wakes on the bank with her head in her
sister's lap, and runs in to her tea, thinking what a wonderful dream it
had been.

## Scoring

100 points across ~27 achievements (each awarded once, Infocom-style),
covering every story beat and expansion puzzle above, plus a few flourishes
(putting the marmalade jar politely into a cupboard mid-fall; joining the
quadrille; the pencil). FULL / FULLSCORE lists them. Ranks run from "quite
a common little girl (with no pictures or conversations in her)" up to
"the Wonder of Wonderland".

## Fairness rules

- No permanent death: fatal-looking outcomes shake the dream and restore
  you to the start of the scene, with everything as it was.
- No unwinnable states: consumables are either replenished (mushroom bits
  never run out) or guarded (Alice refuses to eat the comfits before the
  race is won; the fan slips from her fingers at the last instant rather
  than let her go out altogether, like a candle).
- Every gated action is hinted in scene text, and THINK gives Alice's
  own gentle advice for the current chapter (she generally gives herself
  very good advice, though she very seldom follows it).

## Technical

- Inform 6.41, library 6/12, compiled to Z-machine v8 (`-v8`).
- Source in `src/`, split by area; `Makefile` builds `alice.z8`.
- Scripted walkthrough in `tests/walkthrough.txt`, playable end-to-end
  with `dfrotz -m -q alice.z8 < tests/walkthrough.txt`.
