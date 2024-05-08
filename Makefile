CC := g++
LD := ld

CXXFLAGS ?= -Wall -Wpedantic -O3 -Isrc
LDFLAGS ?= -lm

DEBUG ?= 1
ifeq ($(DEBUG), 1)
	CXXFLAGS += -DDEBUG -g3
endif

NAME=rayseif

CXXFILES=$(shell find src -name "*.cpp" -type f)
OBJ=$(CXXFILES:.cpp=.o)

.PHONY: all
all: $(NAME) # Build everything

.PHONY: format
format: # Format the code as described in .clang-format
	find src -type f -name "*.c" -o -name "*.h" | xargs clang-format -i

.PHONY: help
help: # Print help
	@grep '^[^.#]\+:\s\+.*#' Makefile | \
	gsed "s/\(.\+\):\s*\(.*\) #\s*\(.*\)/`printf "\033[93m"`\1`printf "\033[0m"`	\3 [\2]/" | \
	expand -t20

%.o: %.cpp
	@printf " CC  $^\n"
	@$(CC) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@printf " LD  $@\n"
	@$(CC) $^ $(LDFLAGS) -o $@

.PHONY: clean
clean: # Clean generated files
	@rm -rf $(OBJ) $(NAME)
