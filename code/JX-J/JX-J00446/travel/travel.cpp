#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check(char a,char b)
{
    if((a-'A'<=2&&b-'A'<=2)||(a-'A'>=3&&b-'A'>=3))return 1;
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)cout<<1;
    else cout<<0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
    else cout<<0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])
    {
        if(check(s1[2],s2[2]))
        {
            cout<<1;
        }
        else cout<<0;
    }
    else cout<<0;
    if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1])
    {
        if(check(s1[2],s2[2]))
        {
            if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1)cout<<1;
            else cout<<0;
        }
        else cout<<0;
    }
    else cout<<0;
    return 0;
}
