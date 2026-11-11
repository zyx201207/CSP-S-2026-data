#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
string s0,s01;
int f=0;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    s0=(s1[0]+s1[1]);
    s01=(s2[0]+s2[1]);
    if(c1==c2) cout<<1;
    else
    {
        f=1;
        cout<<0;
    }
    if(s0==s01&&!f) cout<<1;
    else
    {

        f=1;
        cout<<0;
    }
    if((s1[2]>='D'&&s2[2]>='D')||(s1[2]<'D'&&s2[2]<'D')&&!f) cout<<1;
    else
    {
        f=1;
        cout<<0;
    }
    if(((abs(s1[2]-s2[2])==1&&((s1[2]>='D'&&s2[2]>='D')||(s1[2]<'D'&&s2[2]<'D')))||min(s1[2],s2[2])=='D'&&max(s1[2],s2[2])=='F')&&!f) cout<<1;
    else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
