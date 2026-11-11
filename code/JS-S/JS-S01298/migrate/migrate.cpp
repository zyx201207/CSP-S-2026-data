#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,T;
int n,d;
int a[N];
int ans=0;
int cnt=0;
int vis[N];
int minn;
void dfs(int i,int j,int dep)
{
    //cout<<i<<j<<dep<<'\n';
    if(i==j)
    {
        //cout<<dep;
        if(dep>minn) return ;
        if(dep==minn)
        {
            cnt++;
            return ;
        }
        if(dep<minn)
        {
            minn=dep;
            cnt=1;
        }
    }
    for(int k=1;k<=n;k++) if(i!=k&&abs(a[i]-a[k])<=d&&vis[k]==0) {
        vis[k]=1;
        dfs(k,j,dep+1);
        vis[k]=0;
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--)
    {
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                cnt=0;
                minn=1e9;
                vis[i]=1;
                dfs(i,j,0);
                vis[i]=0;
                if(cnt==2) ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
