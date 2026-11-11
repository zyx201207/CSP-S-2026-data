#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s1,s2,s3,s4,ans;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3)
    {
        ans=ans+'1';
        if(s2[0]==s4[0]&&s2[1]==s4[1])
        {
            ans=ans+'1';
            if(s2[2]-'A'<=2&&s2[2]-'A'>=0&&s4[2]-'A'<=2&&s4[2]-'A'>=0)
            {
                ans=ans+'1';
                if(s2[2]=='A'&&s4[2]=='B') ans=ans+'1';
                else if(s2[2]=='B') ans=ans+'1';
                else if(s2[2]=='c'&&s4[2]=='B') ans=ans+'1';
                else ans=ans+'0';
            }else if(s2[2]-'A'>=3&&s2[2]-'A'<=4&&s4[2]-'A'>=3&&s4[2]-'A'<=4)
            {
                ans=ans+'1';
                ans=ans+'1';
            }else
            {
                ans=ans+'0';
                ans=ans+'0';
            }
        }else
        {
            ans=ans+'0';
            ans=ans+'0';
            ans=ans+'0';
        }
    }else
    {
        ans=ans+'0';
        ans=ans+'0';
        ans=ans+'0';
        ans=ans+'0';
    }
    cout<<ans;
    return 0;
}
