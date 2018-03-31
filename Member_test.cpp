#include "Member.h"
#include "Member.cpp"
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("follow twice after same member :"){
    Member bar, shahar;
    shahar.follow(bar);
    CHECK(bar.numFollowers() == 1);
    shahar.follow(bar);
    CHECK(bar.numFollowers() == 1);
}

TEST_CASE("check active members : "){
    Member bar,shahar,avi;
    CHECK(numUsers == 3);
    Member dana,beni;
    CHECK(numUsers == 5);
}

TEST_CASE("check follow :"){
    Member avi,noa,dani,beni, bar,shahar;
    avi.follow(noa);
    noa.follow(dani);
    dani.follow(avi);
    beni.follow(shahar);
    bar.follow(shahar);
    beni.follow(bar);
    CHECK(avi.numFollowing() == 1);
    CHECK(noa.numFollowing() == 1);
    CHECK(beni.numFollowing() == 2);
    CHECK(bar.numFollowing() == 1);
}

TEST_CASE("check unfollow :"){
    Member bar,shahar,dana;
    bar.follow(shahar);
    dana.follow(shahar);
    CHECK(shahar.numFollowers() == 2);
    CHECK(dana.numFollowers() == 0);
    CHECK(dana.numFollowing()==1);
    dana.unfollow(shahar);
    CHECK(shahar.numFollowers() == 1);
    CHECK(dana.numFollowing() == 0);
}