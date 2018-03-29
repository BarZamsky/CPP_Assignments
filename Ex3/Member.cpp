#include "Member.h"
#include <algorithm>

void Member:: follow(Member& m)
{ 
   if(find(this->followers.begin(),this->followers.end(), m.userId) == this->followers.end() ){
        this->followers.push_back(m.userId);
        m.following.push_back(this->userId);
     }
}

void Member:: unfollow(Member& m)
{
    for (int i=0; i<this->followers.size(); i++)
    {
        if (m.userId==this->followers.at(i))
        {
            this->followers.erase(followers.begin()+i);
        }
    }

    for (int j=0; j<m.followers.size(); j++)
    {
        if (this->userId==m.following.at(j))
        {
            m.following.erase(following.begin()+j);
        }
    }
}

int Member :: numFollowers()
{
    return this->following.size();
}

int Member :: numFollowing()
{
    return this->followers.size();
}

int count()
{
    return numUsers;
}
