#include "Member.h"
#include <algorithm>

void Member::follow(Member& m)
{ 
    // check if the member already exist in the vector
        for(int i=0; i<followers.size(); i++){
            if(m.userId == (*followers[i]).userId) return;
        }
    // else- adding it 
        followers.push_back(&m);
        m.following.push_back(&(*this));
}

void Member::unfollow(Member& m)
{
    for (int i = 0 ; i < followers.size(); i++)
    {
        if (m.userId==(*followers[i]).userId)
        {
            followers.erase(followers.begin()+i);
        }
    }

    for (int i = 0 ; i < m.following.size(); i++)
    {
        if (m.following[i]->userId == userId)
        {
            m.following.erase(m.following.begin()+i);
        }
    }
}

int Member::numFollowers()
{
    return following.size();
}

int Member::numFollowing()
{
    return followers.size();
}

// destructor
Member::~Member()
{
   following.erase(following.end()-1);
   followers.erase(followers.end()-1);
    --numUsers;
}

