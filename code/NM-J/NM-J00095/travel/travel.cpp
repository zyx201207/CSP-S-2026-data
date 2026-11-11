#include<bits/stdc++.h>
using namespace std;
string c,c2,s,s2;
bool check(string s,string s2)
{
    if((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(s2[2]=='D'||s2[2]=='F'))return 0;
    return 1;
}
bool check2(string s,string s2)
{
    if((s[2]=='A'&&s2[2]=='B')||(s[2]=='B'&&s2[2]=='C')||(s[2]=='D'&&s2[2]=='F')||(s2[2]=='A'&&s[2]=='B')||(s2[2]=='B'&&s[2]=='C')||(s2[2]=='D'&&s[2]=='F'))return 1;
    return 0;
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>s>>c2>>s2;
    if(c==c2)
    {
        cout<<1;
        if(s[0]==s2[0]&&s[1]==s2[1])
        {
            cout<<1;
            if(check(s,s2))
            {
                cout<<1;
                if(check2(s,s2))cout<<1;
                else cout<<0;
            }
            else cout<<0;
        }
        else cout<<0;
    }
    return 0;
}
