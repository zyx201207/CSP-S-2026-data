#include<bits/stdc++.h>
// #define int long long
#define ll long long
using namespace std;
inline ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0') {if(ch=='-') f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0') {x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2e6+5;const ll inf=5e18;
int n;ll ans,d,a[N];
vector<int> g[5005];int cnt[5005];bool vis[N];
void baoli(){
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n&&a[i]+d>=a[j];j++) g[i].push_back(j);
    queue<int> q,p;ans=0;
    for(int i=1;i<=n;i++) {
        q.push(i);cnt[i]=1;p.push(i);
        while(!q.empty()) {
            const int l=q.size();
            for(int k=1;k<=l;k++) {const int u=p.front();p.pop();vis[u]=1;}
            for(int k=1;k<=l;k++) {
                const int u=q.front();q.pop();
                for(int v:g[u]) {if(!cnt[v]) q.push(v),p.push(v);if(!vis[v]) cnt[v]+=cnt[u];}
            }
        }
        for(int j=i+1;j<=n;j++) {if(cnt[j]==2) ans++;cnt[j]=0,vis[j]=0;}
        cnt[i]=0;vis[i]=0;
    }
    printf("%lld\n",ans);
    for(int i=1;i<=n;i++) g[i].clear();
}
void solve(){
    n=read(),d=read();
    for(int i=1;i<=n;i++) a[i]=read();
    if(n<=5000) {baoli();return ;}
    int cnt=0;bool f=0;a[0]=-inf;ans=0;
    for(int i=n;i>=1;i--) {
        cnt++;
        if(i>3&&a[i-3]+d<a[i]&&a[i-3]+d>=a[i-1]&&a[i-2]+d>=a[i]&&a[i-4]+d<a[i-2]) {
            cnt=1;f=1;i-=3;
        }
        if(f) ans+=cnt;
    }
    printf("%lld\n",ans);
}
signed main(){
    freopen("migrate.in" ,"r",stdin );
    freopen("migrate.out","w",stdout);
    // freopen("1.in" ,"r",stdin );
    // freopen("1.out","w",stdout);
    int cid=read(),T=read();
    while(T--) solve();
    return 0;
}