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
inline void MAX(auto &x,auto y){x=x>y?x:y;}
inline void MIN(auto &x,auto y){x=x<y?x:y;}
const int N=505,M=5e5+5;
const ll inf=1e18;
int n,m,w[M],id[M];
ll f[N][N];
vector<pii> a[M];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int C,q;cin>>C>>n>>m>>C>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int len,x,k;cin>>len;
        while(len--)
            cin>>x>>k,a[x].pb({i,k});
    }
    memset(f,0x3f,sizeof f);
    for(int i=1;i<=n;i++)
        f[i][i]=0;
    for(int i=1;i<=m;i++)
        for(auto j:a[i])
            for(auto k:a[i])
                MIN(f[j.fs][k.fs],j.sc+k.sc);
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                MIN(f[i][j],f[i][k]+f[k][j]);
    while(q--)
    {
        int x,y;ll ans=inf;cin>>x>>y;
        for(auto i:a[x])
            for(auto j:a[y])
                MIN(ans,f[i.fs][j.fs]+i.sc+j.sc);
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}