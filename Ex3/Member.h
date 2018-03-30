#pragma once
#include <vector>

using namespace std;

int static numUsers=0;
static vector<int> _id;
class Member
{
    int userId;
    vector<int> following;
    vector<int> followers;   

    public:
    Member() { userId=++numUsers; _id.push_back(numUsers);}
    ~Member();
    int static count(){return numUsers;}
    void follow(Member& m);
    void unfollow(Member& m);
    int numFollowers();
    int numFollowing();
};




