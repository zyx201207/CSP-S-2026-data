#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define all(v) v.begin(),v.end()
#define pb push_back
#define ppb pop_back
using namespace std;
inline void MAX(auto &x,auto y){x=max(x,y);}
inline void MIN(auto &x,auto y){x=min(x,y);}
const int N=5e3+5,inf=1e9;
int n,nxt[N],f[N][N],g[N][N];
ll m,a[N];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    nxt[n]=n;
    for(int i=n-1;i>=1;i--)
    {
        nxt[i]=nxt[i+1];
        while(a[nxt[i]]-a[i]>m)
            nxt[i]--;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        f[i][i]=0,g[i][i]=1;
        for(int j=i+1;j<=n;j++)
        {
            f[i][j]=inf,g[i][j]=0;
            for(int k=i;k<j;k++)
            {
                if(a[j]-a[k]>m)
                    continue;
                if(f[i][k]+1<f[i][j])
                    f[i][j]=f[i][k]+1,g[i][j]=g[i][k];
                else if(f[i][k]+1==f[i][j])
                    g[i][j]=min(g[i][j]+g[i][k],3);
            }
            ans+=g[i][j]==2;
        }
    }
    cout<<ans<<'\n';
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.ans","w",stdout);
    int C,T;cin>>C>>T;
    while(T--) solve();
    return 0;
}