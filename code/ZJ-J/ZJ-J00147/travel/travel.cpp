#include<bits/stdc++.h>
using namespace std;
#define int long long
#define gc getchar_unlocked
#define debug(num) printf("%s:%lld\n",#num,num)
signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1 == c2)
    {
        cout<<"1";
    }
    else
    {
        cout<<"0000";
        return 0;
    }
    if(s1.size()!=s2.size())
    {
        cout<<"000";
        return 0;
    }
    for(int i = 0;i<s1.size();++i)
    {
        if(!isdigit(s1[i])) break;
        if(s1[i]!=s2[i])
        {
            cout<<"000";
            return 0;
        }
    }
    cout<<"1";
    int i = s1.size()-1;
    if(s1[i] == 'A'||s1[i] == 'B'||s1[i] == 'C')
    {
        if(s2[i] == 'A'||s2[i] == 'B'||s2[i] == 'C')
        {
            cout<<'1';
            bool p1 = s1[i] == 'B'||s2[i] == 'B';
            if(p1) cout<<'1';
            else cout<<'0';
        }
        else cout<<"00";
    }
    else
    {
        if(s2[i] == 'A'||s2[i] == 'B'||s2[i] == 'C')
        {
            cout<<"00";
        }
        else cout<<"11";
    }
}