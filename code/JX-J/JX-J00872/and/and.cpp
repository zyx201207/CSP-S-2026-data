#include<bits/stdc++.h>
using namespace std;
long long ans=-1e18;
long long n,m;
long long a[200005];
void dfs(long long k,long long i,long long j)
{
    if(k==m)
    {
        ans=max(ans,j);
        return;
    }
    if(i>n||i-k>n-m) return;
    if(j==0)
    {
    dfs(k+1,i+1,a[i]);
    dfs(k,i+1,j);
    }
    else
    {
    dfs(k+1,i+1,j&a[i]);
    dfs(k,i+1,j);
    }
    return;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    long long ma=-1e18;
    long long an;
    for(long long i=1; i<=n; ++i)
    {
        cin>>a[i];
        ma=max(ma,a[i]);
    }
    if(m==1)
    {
        cout<<ma;
        return 0;
    }
    if(n==m)
    {
        an=a[1];
        for(int i=2; i<=n; ++i)
        an=an&a[i];
        cout<<an;
        return 0;
    }
    dfs(0,1,0);
    cout<<ans;
    return 0;
}
