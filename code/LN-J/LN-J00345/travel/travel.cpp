#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    if(s1!=s3)
    {
        cout<<"0000";
        return 0;
    }
    cout<<1;
    if(s2[0]!=s4[0]||s2[1]!=s4[1])
    {
        cout<<"000";
        return 0;
    }
    cout<<1;
    if('A'<=s2[2]&&s2[2]<='C'&&'D'<=s4[2]&&s4[2]<='E'||'A'<=s4[2]&&s4[2]<='C'&&'D'<=s2[2]&&s2[2]<='E')
    {
        cout<<"00";
        return 0;
    }
    cout<<1;
    cout<<((s2[2]<='C'&&s2[2]!='B'&&s4[2]!='B')?0:1);
    return 0;
}
