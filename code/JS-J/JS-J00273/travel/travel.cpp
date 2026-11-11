#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
int ans1=0,ans2=0,ans3=0,ans4=0;

signed main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        ans1=1;
        if(s1[0]==s2[0] && s1[1]==s2[1])
        {
            ans2=1;
            if(s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C')
            {
                ans3=1;
                if(s1[2]=='A' && s2[2]=='B')
                {
                    ans4=1;
                }
                else if(s1[2]=='B' && s2[2]=='A')
                {
                    ans4=1;
                }
                else if(s1[2]=='B' && s2[2]=='C')
                {
                    ans4=1;
                }
                else if(s1[2]=='C' && s2[2]=='B')
                {
                    ans4=1;
                }
            }
            else if(s1[2]=='D' && s1[2]=='E')
            {
                ans3=1;
                ans4=1;
            }
            else if(s1[2]=='E' && s1[2]=='D')
            {
                ans3=1;
                ans4=1;
            }
        }
    }
    cout<<ans1<<ans2<<ans3<<ans4;
    return 0;
}
