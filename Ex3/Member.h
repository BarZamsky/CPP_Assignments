#pragma once
#include <vector>
using namespace std;

int static numUsers=0;

class Member
{
    int userId;
    vector<Member*> following;
    vector<Member*> followers;   

    public:
    Member() { userId=++numUsers;}
    ~Member();
    int static count(){return numUsers;}
    void follow(Member& m);
    void unfollow(Member& m);
    int numFollowers();
    int numFollowing();
};




