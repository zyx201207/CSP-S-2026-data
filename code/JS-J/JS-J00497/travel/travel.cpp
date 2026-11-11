#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else
    {
        cout<<"0000";
        return 0;
    }
    if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
    else
    {
        cout<<"000";
        return 0;
    }
    char cc1=s1[2],cc2=s2[2];
    if((cc1<='C'&&cc2<='C')||(cc1>='D'&&cc2>='D')) cout<<1;
    else
    {
        cout<<"00";
        return 0;
    }
    if((cc1=='D'&&cc2=='F')||(cc1=='F'&&cc2=='D')) cout<<1;
    else if(abs(cc1-cc2)==1) cout<<1;
    else cout<<0;
    return 0;
}
