#include "catch.hpp"
#include "BuddySystem.h"

int Buddy_test()
{
	Buddy by;
	by.dump();
	unsigned p = by.alloc(1);
	by.dump();
	p = by.alloc(5);
	by.dump();
	p = by.alloc(16);
	by.dump();
	by.free(p);
	by.dump();
	return 0;
}
TEST_CASE("Buddy_test", "one") {
	REQUIRE(Buddy_test() == 0);
}

