#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],vis[100005];
long long maxx=0;
void dfs(long long u,long long ans)
{
    if(u==m+1)
    {
        maxx=max(maxx,ans);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==1)continue;
        vis[i]=1;
        if(u==1)
        {
            dfs(u+1,ans|a[i]);
        }
        else
        {
            dfs(u+1,ans&a[i]);
        }
        vis[i]=0;
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
    dfs(1,0);
    cout<<maxx;
    return 0;
}
