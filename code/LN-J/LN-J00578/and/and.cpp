#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long a[200005];
long long maxn=0;
void dfs(long long x,long long z,long long ii)
{
    if(x==m)
    {
        maxn=max(maxn,z);
        return;
    }
    for(long long i=ii+1;i<=n;i++) dfs(x+1,z&a[i],i);
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    for(long long i=1;i<=n-m+1;i++)
    {
        dfs(1,a[i],i);
    }
    cout<<maxn;
    return 0;
}
