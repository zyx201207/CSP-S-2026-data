#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int const N=505,M=500005,D=25,Q=100005;
pair<int,ll> g[M][D];
int cnt[M];
ll w[M],f[N][N];
int read() {
    int r=0;
    char ch=getchar();
    while(ch<'0'||'9'<ch) ch=getchar();
    while('0'<=ch&&ch<='9') r=r*10+ch-48,ch=getchar();
    return r;
}
void chkmin(ll &a,ll b) { if(a>b) a=b; }
int main() {
#ifndef DEBUG
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
#endif // DEBUG
    int c=read(),n=read(),m=read(),d=read(),q=read();
//    cerr<<"1"<<endl;
    for(int i=1;i<=m;i++) w[i]=read();
    for(int i=1,k;i<=n;i++) {
        k=read();
        while(k--) {
            int u=read();
            ll v=read();
            g[u][++cnt[u]]={i,v};
        }
    }
//    cerr<<"2"<<endl;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) if(i!=j) f[i][j]=1e18;
//    cerr<<"3"<<endl;
    for(int u=1;u<=m;u++) {
        for(int i=1;i<=cnt[u];i++) {
            int s=g[u][i].first;
            ll a=g[u][i].second;
            for(int j=i+1;j<=cnt[u];j++) {
                int t=g[u][j].first;
                ll b=g[u][j].second+a;
                chkmin(f[s][t],b);
                chkmin(f[t][s],b);
            }
        }
    }
//    cerr<<"4"<<endl;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                chkmin(f[i][j],f[i][k]+f[k][j]);
//    cerr<<"5"<<endl;
    while(q--) {
        int s=read(),t=read();
        ll ans=1e18;
        for(int ii=1;ii<=cnt[s];ii++) {
            int i=g[s][ii].first;
            ll x=g[s][ii].second;
            for(int jj=1;jj<=cnt[t];jj++) {
                int j=g[t][jj].first;
                ll y=g[t][jj].second;
                chkmin(ans,f[i][j]+x+y);
            }
        }
        cout<<ans+w[s]+w[t]<<'\n';
    }
//    cerr<<"6"<<endl;
    return 0;
}
