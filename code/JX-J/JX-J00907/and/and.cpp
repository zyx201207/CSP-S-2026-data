#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool vis[200005];
int ans=-1;
void dfs(int step,int sum)
{
    if(step==m)
    {
        ans=max(ans,sum);
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            if(step==0)
                dfs(step+1,a[i]);
            else
            {
                if(sum&a[i]==0) continue;
                dfs(step+1,(sum&a[i]));
            }
            vis[i]=0;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)   cin>>a[i];
    dfs(0,1);
    if(ans==-1)
    {
        cout<<0;
        return 0;
    }
    cout<<ans;
    return 0;
}
