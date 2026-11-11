#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1200000],v[1000000];
long long Max=0;
void dfs(long long x,long long l,long long last)
{
    if(x==m)
    {
        Max=max(Max,l);
        return;
    }
    for(long long i=last;i<n;i++)
    {
        if(v[i]) continue;
        v[i]=1;
        if(l==-1) dfs(x+1,a[i],i);
        else dfs(x+1,l&a[i],i);
        v[i]=0;
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];
    }
    dfs(0,-1,0);
    cout<<Max;
    return 0;
}
