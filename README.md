# Alice's Adventures in Wonderland

**An interactive fiction after the book by Lewis Carroll, written in Inform 6.**

Play as Alice through all twelve chapters of the 1865 novel — down the
rabbit-hole, through the pool of your own tears, past the Caterpillar and
the Duchess and the maddest of tea-parties, into the beautiful garden at
last, and on to the trial of the Knave of Hearts. The prose is written in
imitation of Carroll's narration, and the puzzles are expansions of the
book's own logic: nothing in them alters the story — the challenge is
working out *how* Alice does what the book says she did, plus a few new
riddles built from Wonderland's own rules.

The original novel is in the public domain, and so is this game.

## Playing it

You need a Z-machine interpreter. Almost any will do:

- **Frotz** (`apt install frotz`, `brew install frotz`)
- **Gargoyle**, **WinFrotz**, **Spatterlight**, **Lectrote**, or the
  [Parchment](https://iplayif.com) web interpreter

Then:

```
frotz alice.z8
```

A pre-built `alice.z8` is included in the repository.

### If you have never played interactive fiction

You type short commands at the `>` prompt: `LOOK`, `EXAMINE` things,
`TAKE` and `DROP` them, `NORTH`/`SOUTH`/`EAST`/`WEST` (or `N`/`S`/`E`/`W`)
to move, and `WAIT` (or `Z`) to let a moment pass. In Wonderland you will
also get a good deal of use out of:

- `TALK TO` someone, and `ASK` someone `ABOUT` something
- `SAY` something out loud (bold words, said loudly, move mountains here)
- `FOLLOW` whoever is in a hurry
- `EAT` and `DRINK` what you find — reading the label first, like a wise
  child
- `RECITE`, when you are asked to
- `THINK` — Alice gives herself very good advice, chapter by chapter
  (though she very seldom follows it)

`HELP` explains all this in the game; `SCORE` shows your progress and
`FULL` shows how you earned it. There are 100 points across 31 deeds,
from the sensible to the purely ornamental. Nothing in the dream can kill
you or lock you out of finishing: it is, after all, your dream.

If you are properly stuck, `WALKTHROUGH.md` contains complete spoilers.

## Building from source

Requires the Inform 6 compiler and the 6/12 library
(`apt install inform6-compiler inform6-library`):

```
make            # builds alice.z8
make test       # plays the scripted walkthrough via dfrotz
```

## Repository layout

| Path | What it is |
|------|------------|
| `src/alice.inf` | main file: constants, scoring table, includes |
| `src/core.h` | the size machinery, tasks, THINK/HELP, GamePreRoutine |
| `src/world1.h` | Chapters I–IV: riverbank, hall, pool, caucus-race, the Rabbit's house |
| `src/world2.h` | Chapters V–VII: Caterpillar, Pig and Pepper, the Mad Tea-Party |
| `src/world3.h` | Chapters VIII–XII: croquet, the Mock Turtle, the trial |
| `src/verbs.h` | new grammar (FOLLOW, RECITE, SNATCH, TUCK, CROQUET...) |
| `tests/walkthrough.txt` | a full 100-point playthrough, used by `make test` |
| `DESIGN.md` | the design document: map, puzzle rationale, fairness rules |
| `WALKTHROUGH.md` | the same playthrough, annotated, with spoilers |

## A note on fidelity

Room descriptions, dialogue and scene text are adapted from — and often
quote — Carroll's public-domain original, compressed for play. The game's
inventions (the conscientious little lock, the counting of the croquet
turns, the Gryphon's lessons-quiz, and so on) are built to sit inside the
story without bending it: every chapter begins and ends where the book
says it does.
