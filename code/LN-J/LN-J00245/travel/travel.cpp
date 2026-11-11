#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
    string a,s,d,f;
    cin>>a>>s>>d>>f;
    if(a==d)
    {
        cout<<"1";
    }
    else{cout<<"0";}
    if((s[0]==f[0]&&s[1]==f[1])&&(a==d))
    {
        cout<<"1";
    }
    else{cout<<"0";}
    if(((s[2]=='A'||s[2]=='B'||s[2]=='C')&&(f[2]=='A'||f[2]=='B'||f[2]=='C'))&&(a==d)&&(s[0]==f[0]&&s[1]==f[1]))
    {
        cout<<"1";
    }
    else{cout<<"0";}
    if(((s[0]==f[0]&&s[1]==f[1])&&(a==d)&&((s[2]=='A'&&f[2]=='B')||(s[2]=='B'&&f[2]=='A')||(s[2]=='B'&&f[2]=='C')||(s[2]=='C'&&f[2]=='B')))||((s[2]=='D'&&f[2]=='E')||s[2]=='E'&&f[2]=='D'))
    {
        cout<<"1";
    }
    else{cout<<"0";}
    return 0;
}
