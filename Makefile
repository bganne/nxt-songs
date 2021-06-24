CXXFLAGS:=-Wextra -Werror -Os

all: $(addsuffix .nxc, $(basename $(wildcard */*.ino)))

%.nxc: %.exe
	./"$<" > "$@"

%.exe: %.ino nxt.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -xc++ -include nxt.cc "$<" -o "$@"

clean:
	$(RM) */*.nxc

.PHONY: clean all
