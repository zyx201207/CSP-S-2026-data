#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,maxsz=1,temp,ans,m;
struct node{
    ll n;
    string s2;
}s[200005];
string p;
string chai(ll p)
{
    ll l=p;
    string tmp;
    while(l>0)
    {
        tmp+=char(l%2+'0');
        l/=2;
    }
    reverse(tmp.begin(),tmp.end());
    return tmp;
}
bool cmp(node a,node b)
{
    return a.s2>b.s2;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].n;
        s[i].s2=chai(s[i].n);
        maxsz=max(maxsz,ll(s[i].s2.size()));
    }
    for(int i=1;i<=n;i++)
    {
        temp=maxsz-s[i].s2.size();
        for(int j=1;j<=temp;j++)
            s[i].s2="0"+s[i].s2;
    }
    sort(s+1,s+n+1,cmp);
    ans=s[1].n;
    for(int i=2;i<=m;i++)
        ans=ans&s[i].n;
    cout<<ans;
    return 0;
}