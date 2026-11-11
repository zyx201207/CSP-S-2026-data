/*
CSP-J 2026 T1
Author:DFLJ
Oh no! I forgot to bring my water.
So I need to AC fast and have a sleep.

ACed at 08:40
The code is very long.
*/
#include<bits/stdc++.h>
using namespace std;
bool chk(char ch1,char ch2)
{
    if(ch1=='A'&&ch2=='B') return 1;
    if(ch1=='A'&&ch2=='C') return 1;
    if(ch1=='B'&&ch2=='C') return 1;
    if(ch1=='C'&&ch2=='B') return 1;
    if(ch1=='B'&&ch2=='A') return 1;
    if(ch1=='C'&&ch2=='A') return 1;
    if(ch1=='D'&&ch2=='F') return 1;
    if(ch1=='F'&&ch2=='D') return 1;
    return 0;
}
bool chk1(char ch1,char ch2)
{
    if(ch1=='A'&&ch2=='B') return 1;
    if(ch1=='B'&&ch2=='C') return 1;
    if(ch1=='C'&&ch2=='B') return 1;
    if(ch1=='B'&&ch2=='A') return 1;
    if(ch1=='D'&&ch2=='F') return 1;
    if(ch1=='F'&&ch2=='D') return 1;
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) 
    {
        cout<<1;
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout<<1;
            if(chk(s1[2],s2[2]))
            {
                cout<<1;
                if(chk1(s1[2],s2[2]))
                {
                    cout<<1;
                }
                else cout<<0;
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    
    return 0;
}