#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxn;
void dfs(int depth,int sum,int l)
{
    if(depth==m+1)
    {
        maxn=max(maxn,sum);
        return;
    }
    for(int i=l+1;i<=n;i++)
    {
        if((sum&a[i])<=maxn) continue;
        dfs(depth+1,sum&a[i],i);

    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]<=maxn) continue;
        dfs(1,a[i],i-1);
    }
    cout<<maxn;
    return 0;
}
