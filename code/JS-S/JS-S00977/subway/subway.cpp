#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,ans=INT_MAX;
int z[500005];
int x[505][500005];
bool vis[500005];
bool check(int i,int en)
{
     for(int j=1;j<=m;j++)
         {
             if(j==en&&x[i][en]!=0)
                return true;
         }return false;

}
void dfs(int i,int cnt,int en)
{
    if(check(i,en))
    {
        ans=min(ans,cnt+x[i][en]+z[en]);
        return ;
    }
    for(int j=1;j<=m;j++)
    {
        for(int k=1;k<=n;k++)
        {
            if(x[j][k]!=0&&j!=i)
            {
                vis[k]=1;
                dfs(j,cnt+x[i][k]+x[j][k],en);
                vis[k]=0;
            }

        }
    }

}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
cin>>c>>n>>m>>d>>q;
for(int i=1;i<=m;i++)cin>>z[i];
for(int i=1;i<=n;i++)
{
    cin>>x[i][0];
    for(int j=1;j<=x[i][0];j++)
    {
        int temp;
        cin>>temp;
        cin>>x[i][temp];
    }
}
for(int i=1;i<=q;i++)
{
 int st,en;
 cin>>st>>en;
 ans=INT_MAX;
 for(int j=1;j<=m;j++)
 {
     if(x[j][st]!=0)
     {
               vis[st]=1;//cout<<z[st]+x[j][st]<<endl;
      dfs(j,z[st]+x[j][st],en);

      vis[st]=0;

     }
 }
cout<<ans<<endl;
}
}
