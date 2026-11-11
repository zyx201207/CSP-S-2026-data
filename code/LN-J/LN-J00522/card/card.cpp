#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],ans[300010],vis[300010];
void game(int time)
{
    for(int i=time;i<=n;i++)
    {
        if(vis[a[i]]==0) vis[a[i]]=i;
        else{
            for(int k=vis[a[i]];k<i;k++) vis[a[k]]=0;
        }
        vis[a[i]]=i;
    }
    for(int i=1;i<=m;i++)
    {
        if(vis[i]>0) ans[i]++;
    }
}
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++) ans[i]=0;
    for(int i=1;i<=n;i++)
    {
        game(i);
        for(int j=1;j<=n;j++)
        {
            vis[j]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
}
