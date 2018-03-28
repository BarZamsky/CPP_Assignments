#pragma once
#include <vector>
using namespace std;

int static numUsers=1;
//int count(){ return numUsers;}
class Member
{
    int userId;
    vector<int> following;
    vector<int> followers;   

    public:

    Member() { this->userId=numUsers++;}
    ~Member(){--numUsers;}
    void follow(Member& m);
    void unfollow(Member m);
    int numFollowers ();
    int numFollowing();
};


