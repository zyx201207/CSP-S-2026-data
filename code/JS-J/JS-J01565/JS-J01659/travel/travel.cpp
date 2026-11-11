#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int a,b;
    string ai,bi;
    cin>>a>>ai>>b>>bi;
    if(a==b) cout<<1;
    else
    {
        cout<<0<<0<<0<<0<<'\n';
        return 0;
    }
    if(ai[0]==bi[0]&&ai[1]==bi[1]) cout<<1;
    else
    {
        cout<<0<<0<<0<<'\n';
        return 0;
    }
    if(ai[2]<='C'&&bi[2]<='C'||ai[2]>'C'&&bi[2]>'C') cout<<1;
    else
    {
        cout<<0<<0<<'\n';
        return 0;
    }
    if(abs(ai[2]-bi[2])==1||ai[2]=='D'&&bi[2]=='F'||bi[2]=='D'&&ai[2]=='F') cout<<1<<'\n';
    else cout<<0<<'\n';
    return 0;
}
