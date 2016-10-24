target := main
source := $(target).c
depens := $(filter-out $(source), $(wildcard *.c))
header := $(depens:%.c=%.h)

override CFLAGS += -std=c11 -O3 -fdiagnostics-color -Wall -pedantic
override LDLIBS += -lm

$(target): $(source) $(depens) $(header)

.PHONY: run
run: $(target)
	./$(target)

.PHONY: clean
clean:
	$(RM) $(target)
