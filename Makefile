# Alice's Adventures in Wonderland — Inform 6 build
#
# Requires: inform6 (the compiler) and the Inform 6/12 library.
# On Debian/Ubuntu:  apt install inform6-compiler inform6-library frotz

INFORM  = inform6
LIBRARY = /usr/share/inform6/library
SWITCHES = -v8 -s -E1 -w

SOURCES = src/alice.inf src/core.h src/world1.h src/world2.h src/world3.h src/verbs.h

alice.z8: $(SOURCES)
	$(INFORM) $(SWITCHES) +include_path=src,$(LIBRARY) src/alice.inf alice.z8

.PHONY: test clean play

# Run the full scripted walkthrough and show the final screens.
test: alice.z8
	dfrotz -m -q -w 400 alice.z8 < tests/walkthrough.txt > tests/transcript.txt; \
	tail -40 tests/transcript.txt

play: alice.z8
	frotz alice.z8

clean:
	rm -f alice.z8 tests/transcript.txt
