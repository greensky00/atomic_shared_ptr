LDFLAGS =
CXXFLAGS = \
	-g -D_GNU_SOURCE \
	-I. -I./src -I./tests \

CXXFLAGS += -Wall
CXXFLAGS += -O3

TEST = \
	tests/ashared_ptr_test.o \

PROGRAMS = \
	tests/ashared_ptr_test \

all: $(PROGRAMS)

tests/ashared_ptr_test: $(TEST)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -rf $(PROGRAMS) ./*.o ./*.so ./*/*.o ./*/*.so