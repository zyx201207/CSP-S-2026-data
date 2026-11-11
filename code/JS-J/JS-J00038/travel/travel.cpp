#include<bits/stdc++.h>
#define int long long
#define ln "\n"
using namespace std;
map<char,int> mp;
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    mp['A']=1;
    mp['B']=1;
    mp['C']=1;
    mp['D']=2;
    mp['F']=2;
    string c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)
    {
        cout<<"0000"<<ln;
        return 0;
    }
    else cout<<"1";
    for(int i=0;i<2;i++)
    {
        if(s1[i]!=s2[i])
        {
            cout<<"000"<<ln;
            return 0;
        }
    }
    cout<<"1";
    //cout<<"a"<<mp[s1[2]]<<" "<<mp[s2[2]]<<ln;
    if(mp[s1[2]]!=mp[s2[2]])
    {
        cout<<"00"<<ln;
        return 0;
    }
    cout<<"1";
    if((s1[2]=='A'&&s2[2]=='C')||(s2[2]=='A'&&s1[2]=='C'))
    {
        cout<<"0"<<ln;
    }
    else
    {
        cout<<"1"<<ln;
    }
    return 0;
}