#define CATCH_CONFIG_MAIN

#include <iostream>
#include <sstream>
#include <string>

#include "catch.hpp"
#include "money.hpp"


TEST_CASE( "Moneys assigning test", "[money]" ) {
    REQUIRE( Money(0, 100) == Money(1, 0) );
    REQUIRE( Money(0, 255) == Money(2, 55) );
    REQUIRE( Money(1, 255) == Money(3, 55) );
}

TEST_CASE( "Moneys reading test", "[money]" ) {
    Money mon;
    string str = "-1 -1";
    stringstream s_stream(str);

    s_stream >> mon;

    REQUIRE( mon == Money(0, 0) );
}

TEST_CASE( "Moneys comparison test", "[money]" ) {
    REQUIRE( Money(10, 10) < Money(20, 10) );
    REQUIRE( Money(0, 50) < Money(1, 0) );
    REQUIRE( Money(1, 50) > Money(1, 0) );
}

TEST_CASE( "Moneys sum and sub test", "[money]" ) {
    REQUIRE( Money(200, 10) + Money(300, 20) == Money(500, 30));
    REQUIRE( Money(200, 60) + Money(300, 60) == Money(501, 20));

    REQUIRE( Money(400, 60) - Money(300, 80) == Money(99, 80));
    REQUIRE( Money(400, 80) - Money(300, 60) == Money(100, 20));
    REQUIRE( Money(400, 50) - Money(300, 20) == Money(100, 30));
    REQUIRE( Money(400, 10) - Money(300, 20) == Money(99, 90));
    REQUIRE( Money(200, 10) - Money(300, 20) == Money(0, 0));
}

TEST_CASE( "Moneys mult and div test", "[money]" ) {
    REQUIRE( Money(100, 10) * 2.0 == Money(200, 20) );
    // when in rub there is . part (after multiplying rub) move it to pen 
    REQUIRE( Money(123, 80) * 2.5 == Money(307 + 2, 5 + 0) ); 
    REQUIRE( Money(200, 83) * 2.5 == Money(500 + 2, 7) ); 


    REQUIRE( Money(300, 50) / 2.0 == Money(150, 25) );
    REQUIRE( Money(300, 60) / 1.5 == Money(200, 40) );
    // when in rub there is . part (after multiplying rub) move it to pen 
    REQUIRE( Money(300, 60) / 8.0 == Money(37, 5 + 7) );
    REQUIRE( Money(200, 50) / 0.5 == Money(401, 0) );
}
