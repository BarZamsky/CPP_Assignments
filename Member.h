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
   inline int static count(){return numUsers;}
   inline void follow(Member& m);
   inline void unfollow(Member& m);
   inline int numFollowers();
   inline int numFollowing();
};


