#include <bits/stdc++.h>
#define int long long
using namespace std;

constexpr int maxn = 1e2+10;

string s1,s2,t1,t2;
unordered_map<char,int> mp;

signed main()
{
    #ifndef ONLINE_JUDGE
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    #endif // ONLINE_JUDGE

    cin>>s1>>t1>>s2>>t2;
    mp['A']=0;
    mp['B']=1;
    mp['C']=2;
    mp['D']=4;
    mp['F']=5;
    int flag=0;
    if(s1==s2)
    {
        flag|=1<<3;
        if(t1.substr(0,2)==t2.substr(0,2))
        {
            flag|=1<<2;
            int w1=mp[t1[2]];
            int w2=mp[t2[2]];
            if((w1<3 && w2<3 )|| (w1>3 && w2>3))
            {
                flag|=1<<1;
                if(abs(w1-w2)==1)
                {
                    flag|=1;
                }
            }
        }
    }
    for(int i=3;~i;--i)
    {
        if(flag&(1<<i))
        {
            putchar('1');
        }
        else
        {
            putchar('0');
        }
    }


    return 0;
}
















