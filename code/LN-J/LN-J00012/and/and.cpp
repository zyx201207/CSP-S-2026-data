#include<bits/stdc++.h>
using namespace std;
long long ans=0,n,m;
long long a[200005],vis[200005];
void dfs(int y,long long sum)
{
    if(sum<ans)
    {
        return;
    }
    if(y==m)
    {
        ans=max(ans,sum);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            dfs(y+1,sum&a[i]);
            vis[i]=0;
        }
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
    dfs(0,2147483647);
    cout<<ans;
    return 0;
}
