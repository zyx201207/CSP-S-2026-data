#include<bits/stdc++.h>
using namespace std;
string c[3],s[3];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c[1]>>s[1];
    cin>>c[2]>>s[2];
    string s1,s2;
    s1=s[1];
    s2=s[2];
    if(c[1]==c[2])
        {
            cout<<1;
        }
    else
        {
            cout<<"0000";
            return 0;
        }
    if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout<<1;
        }
    else
        {
            cout<<"000";
            return 0;
        }
    if((s1[2]<='C' && s2[2]<='C')||(s1[2]>='D' && s2[2]>='D'))
        {
            cout<<1;
        }
    else
        {
            cout<<"00";
            return 0;
        }
    if(s1[2]<='C'&&s2[2]<='C'&&(int(s1[2]-s2[2])==1)
    ||((s1[2]>='D'&&s2[2]>='D')&&((int(s2[2]-s1[2])==1)
    ||(int(s1[2]-s2[2])==2||int(s2[2]-s1[2])==2))))
        {
            cout<<1;
        }
    else
        {
            cout<<0;
        }
    return 0;
}
