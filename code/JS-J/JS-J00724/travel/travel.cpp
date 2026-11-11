#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4,ans="";
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3)
        ans.push_back('1');
    else
    {
        cout<<"0000";
        return 0;
    }
    if(s2[0]==s4[0]&&s2[1]==s4[1])
        ans.push_back('1');
    else
    {
        cout<<1000;
        return 0;
    }
    if((s2[2]<='C'&&s4[2]<='C')||(s2[2]>'C'&&s2[2]>'C'))
        ans.push_back('1');
    else
    {
        cout<<1100;
        return 0;
    }
    if((s2[2]=='A'&&s4[2]=='B')||(s2[2]=='B'&&s4[2]=='C')||(s2[2]=='D'&&s4[2]=='F')||(s4[2]=='A'&&s2[2]=='B')||(s4[2]=='B'&&s2[2]=='C')||(s4[2]=='D'&&s2[2]=='F'))
        ans.push_back('1');
    else
        ans.push_back('0');
    cout<<ans;
    return 0;
}