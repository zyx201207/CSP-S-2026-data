#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2,ans;
bool f;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        ans+="1";
    }
    else
    {
        cout<<"0000";return 0;
    }
    string a,b;
    char d,e;
    for(int i=0;i<2;i++)
    {
        a+=s1[i];b+=s2[i];
    }
    d=s1[2],e=s2[2];
    if(a==b) ans+="1";
    else
    {
        cout<<"1000";return 0;
    }
    if((d=='D'||d=='F')&&(e=='D'||e=='F')) {ans+="1";f=1;}
    else if((d>='A'&&d<='C')&&(e>='A'&&e<='C')) ans+="1";
    else
    {
        cout<<"1100";return 0;
    }
    if(f==1) ans+="1";
    else if((d=='A'&&e=='B')||(d=='b'&&(e=='A'||e=='C'))||(d=='C'&&e=='B'))
    {
        ans+="1";
    }
    else ans+="0";
    cout<<ans;
    return 0;
}
