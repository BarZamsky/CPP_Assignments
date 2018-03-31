#include "Member.h"
#include <algorithm>

void Member::follow(Member& m)
{ 
   if(find(followers.begin(),followers.end(), m.userId) == followers.end() ){
        followers.push_back(m.userId);
        m.following.push_back(userId);
     }
}

void Member::unfollow(Member& m)
{
    for (int i=0; i<followers.size(); i++)
    {
        if (m.userId==followers[i])
        {
            followers.erase(followers.begin()+i);
        }
    }

    for (int j=0; j<m.following.size(); j++)
    {
        if (userId==m.following[j])
        {
            m.following.erase(m.following.begin()+j);
        }
    }
}
int Member::numFollowers()
{
    for(int i=0; i<following.size();i++){
        auto it =find(_id.begin(), _id.end(), following[i]);
            if (it == _id.end())
            {
                auto index = distance(following.begin(), it);
                following.erase(following.begin()+index);
                }
            }
    return following.size();
}

int Member::numFollowing()
{
      for(int i=0; i<followers.size();i++){
        auto it =find(_id.begin(), _id.end(), followers[i]);
            if (it == _id.end())
            {
                auto index = distance(followers.begin(), it);
                followers.erase(followers.begin()+index);
                }
            }
    return followers.size();
}

// destructor
Member::~Member()
{
// checks in _id vector for the userId and erase it
   vector<int>::iterator it;
   it =find(_id.begin(), _id.end(),userId);
        if (it != _id.end())
        {
            _id.erase(it);
        }

   --numUsers;
}

