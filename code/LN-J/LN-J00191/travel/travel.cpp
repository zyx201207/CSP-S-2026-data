#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1.size()==c2.size())
    {
        for(int i=0;i<c1.size();i++)
        {
            if(c1[i]!=c2[i])
            {
                cout<<"0000";
                return 0;
            }
        }
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if(s1.size()==s2.size())
    {
        for(int i=0;i<s1.size()-1;i++)
        {
            if(s1[i]!=s2[i])
            {
                cout<<"1000";
                return 0;
            }
        }
    }
    else
    {
        cout<<"1000";
        return 0;
    }
    if(!((s1[s1.size()-1]=='F'&&s2[s2.size()-1]=='D')||((s1[s1.size()-1]=='D'&&s2[s2.size()-1]=='F')||(s1[s1.size()-1]<'D'&&s2[s2.size()-1]<'D'))))
    {
        cout<<"1100";
        return 0;
    }
    if(abs(s1[s1.size()-1]-s2[s1.size()-1])==1||(s1[s1.size()-1]=='F'&&s2[s2.size()-1]=='D')||((s1[s1.size()-1]=='D'&&s2[s2.size()-1]=='F')))
    {
        cout<<"1111";
        return 0;
    }
    else
    {
        cout<<"1110";
        return 0;
    }
    return 0;
}
