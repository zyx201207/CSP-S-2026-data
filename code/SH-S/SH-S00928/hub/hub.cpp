#include<bits/stdc++.h>
using namespace std;
const int N=1000010; int cnt,h[N];
struct Edge { int v,nxt; }e[N<<1];
void add(int u,int v) { e[++cnt]={v,h[u]},h[u]=cnt; }
namespace Brute {
    bool mark[N],vis[N];
    void dfs(int u) {
        vis[u]=true;
        for(int i=h[u];i;i=e[i].nxt) {
            int v=e[i].v;
            if(mark[v]&&!vis[v]) dfs(v);
        }
    }
    int dis[25][25];
    void solve() {
        int n,k; cin>>n>>k;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j) dis[i][j]=1e9;
        for(int i=1,u,v;i<n;i++) cin>>u>>v,add(u,v),add(v,u),dis[u][v]=dis[v][u]=1;
        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
        int ans=1e9;
        for(int s=0;s<(1<<n);s++) {
            if(__builtin_popcount(s)!=k) continue;
            for(int i=1;i<=n;i++) mark[i]=((s>>(i-1))&1),vis[i]=false;
            int cnt=0; bool f=true;
            for(int i=1;i<=n;i++) {
                if(!mark[i]||vis[i]) continue;
                if(cnt==2) { f=false; break; }
                cnt++,dfs(i);
            }
            if(!f) continue;
            int mx=0;
            for(int i=1;i<=n;i++) {
                int mn=1e9;
                for(int j=1;j<=n;j++) if(mark[j]) mn=min(mn,dis[i][j]);
                mx=max(mx,mn);
            }
            ans=min(ans,mx);
        }
        cout<<ans<<'\n',cnt=0;
        for(int i=1;i<=n;i++) h[i]=0;
    }
}
namespace K2 {
    int anc[N],dis[N],mx; bool vis[N];
    void dfs(int u,int fa) {
        mx=max(mx,dis[u]);
        for(int i=h[u];i;i=e[i].nxt) {
            int v=e[i].v;
            if(!vis[v]&&v!=fa) anc[v]=u,dis[v]=dis[u]+1,dfs(v,u);
        }
    }
    int seq[N],m;
    bool check(int x) {
        int l=x+1,r=m-x;
        for(int i=l;i<=r;i++) {
            anc[seq[i]]=dis[seq[i]]=mx=0;
            dfs(seq[i],0);
            if(min(i-l,r-i)+mx>x) return false;
        }
        return true;
    }
    void solve() {
        int n,k; cin>>n>>k;
        for(int i=1,u,v;i<n;i++) cin>>u>>v,add(u,v),add(v,u);
        mx=dis[1]=anc[1]=0,dfs(1,0); int x=0;
        for(int i=1;i<=n;i++) if(dis[i]==mx) { x=i; break; }
        mx=dis[x]=anc[x]=0,dfs(x,0); int y=0;
        for(int i=1;i<=n;i++) if(dis[i]==mx) { y=i; break; }
        m=0;
        for(int i=y;i;i=anc[i]) seq[++m]=i,vis[i]=true;
        int l=0,r=n,ans=n+1;
        while(l<=r) {
            int mid=(l+r)>>1;
            if(check(mid)) ans=mid,r=mid-1;
            else l=mid+1;
        }
        cout<<ans<<'\n',cnt=0;
        for(int i=1;i<=n;i++) h[i]=0,vis[i]=false;
    }
}
namespace Special {
    int n,k;
    bool check(int x) {
        int l=x+k/2-1,r=n/2-x-(k+1)/2+1;
        return (r-l-1)/2+1<=x;
    }
    void solve() {
        cin>>n>>k;
        for(int i=1,u,v;i<n;i++) cin>>u>>v,add(u,v),add(v,u);
        if(k==n) cout<<"0\n";
        else
            for(int i=1;i<=n;i++) if(check(i)) { cout<<i<<'\n'; break; }
        cnt=0;
        for(int i=1;i<=n;i++) h[i]=0;
    }
}
int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int c,t; cin>>c>>t;
    if(c==7||c==11||c==12) while(t--) K2::solve();
    else if(c==13||c==14) while(t--) Special::solve();
    else while(t--) Brute::solve();
    return 0;
}
