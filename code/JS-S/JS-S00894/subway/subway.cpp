#include<bits/stdc++.h>
using namespace std;
long long w[500005],a[503][23],t[503][23],x[100003],y[100003],k[505],vis[503][23]={0},anss[100003];
long long n,m,c,d,q;
void dfs(long long d,long long i1,long long j1, long long l,long long ans)
{
    if(l==1)
    {

        anss[d]=min(anss[d],ans);
    }
    if(ans>=anss[d])
    {
        return ;
    }
    for(int e=1;e<=k[i1];e++)
               {
                   if(a[i1][e]==y[d])
                      {
                          dfs(d,i1,e,1,ans+w[a[i1][e]]+t[i1][e]);
                      }
                   for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=k[i];j++)
        {

             if(a[i][j]==a[i1][e] && vis[i][j]==0)
            {
                       vis[i][j]=1;
                 dfs(d,i,j,0,ans+t[i][j]+t[i1][e]);
                 vis[i][j]=0;
            }
        }
    }
               }


}
int main()
{
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
for(int i=1;i<=100003;i++)
{
    anss[i]=9e9;
}
cin >>c >>n >> m >> d >> q;
for(int i=1;i<=m;i++)
{
   cin >> w[i];
}
for(int i=1;i<=n;i++)
{
   cin >> k[i];
   for(int j=1;j<=k[i];j++)
   {
       cin >> a[i][j] >> t[i][j];
   }
}
 for(int i=1;i<=q;i++)
    {
        cin >> x[i] >> y[i];
    }
     for(int e=1;e<=q;e++)
    {

           for(int i=1;i<=n;i++)
    {

        for(int j=1;j<=k[i];j++)
        {

            if(a[i][j]==x[e])
            {
                long long mu=0;
                mu+=w[a[i][j]];
                mu+=t[i][j];
                vis[i][j]=1;
                 dfs(e,i,j,0,mu);
            }
        }
    }
cout << anss[e] << "\n";
    }

return 0;
}
