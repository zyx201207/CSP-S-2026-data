#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int maxn=3e2+10;
constexpr int INF=(LLONG_MAX>>1)-1ll;
int dp[maxn][maxn];
int f[maxn];
int gra[maxn][maxn];
int ans[maxn][maxn];
signed main()
{
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(nullptr);
int c,d,q,u,v,w,last=-1,k,t,n,m;
cin>>c>>t;
while(t--)
{
    c=0;
    cin>>n>>m;
for(int i=1;i<=n;++i)cin>>f[i];
for(int i=1;i<=n;++i)for(int j=1;j<=n;++j){dp[i][j]=INF;gra[i][j]=0;ans[i][j]=0;}
for(int i=1;i<=n;++i){dp[i][i]=0;gra[i][i]=1;}
for(int i=1;i<=n;++i)
{
    for(int j=1;j<=n;++j)
    {
        if(abs(f[i]-f[j])<=m){gra[i][j]=1;dp[i][j]=1;}
    }
}
for(int k=1;k<=n;++k)
{
    for(int i=1;i<=n;++i)
{
    for(int j=i;j<=n;++j)
    {
        if(gra[j][k]&&gra[i][k])
        {
dp[i][j]=min(dp[i][j],dp[i][k]+dp[j][k]);
        }
    }
}
}
for(int k=1;k<=n;++k)
{
    for(int i=1;i<=n;++i)
{
    for(int j=i;j<=n;++j)
    {
        if(gra[i][k]&&gra[j][k])
        {
if(dp[i][j]==dp[i][k]+dp[j][k])
{
    ++ans[i][j];
}
        }
    }
}
}
 for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)if(ans[i][j]==2)++c;
cout<<c<<'\n';
}
return 0;
}
