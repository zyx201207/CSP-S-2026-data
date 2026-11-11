#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace annika{
    const int N=13;
    int n,k,f[N],b[N],TTT,ans;
    int Next[N<<1],ver[N<<1],head[N],tot;
    void add(int u,int v){
        Next[++tot]=head[u],head[u]=tot;
        ver[tot]=v;
    }
    void dfs(int u){
        b[u]=0;
        for (int i=head[u];i;i=Next[i]){
            int v=ver[i];
            if (b[v]){
                dfs(v);
            }
        }
    }
    void dfss(int u,int fa,int stp){
        if (f[u]){
            TTT=stp;
            return;
        }
        for (int i=head[u];i;i=Next[i]){
            int v=ver[i];
            if (v==fa) continue;
            dfss(v,u,stp+1);
        }
    }
    bool chk(){
        int cnt=0;
        for (int i=1;i<=n;i++) b[i]=f[i];
        for (int i=1;i<=n;i++){
            if (b[i]){
                cnt++;
                if (cnt>2) return 0;
                dfs(i);
            }
        }
        return 1;
    }
    void main(){
        ans=1e18;
        cin>>n>>k;
        for (int i=1;i<=n;i++) head[i]=0; tot=0;
        for (int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            add(u,v); add(v,u);
        }
        for (int U=0;U<(1<<n);U++){
            int cnt=0;
            for (int i=0;i<n;i++){
                f[i+1]=(U>>i)&1;
                cnt+=f[i+1];
            }
            if (cnt!=k) continue;
            if (!chk()) continue;
            int cur=0;
            for (int i=1;i<=n;i++){
                TTT=1e18;
                dfss(i,0,0);
                cur=max(cur,TTT);
            }
            ans=min(ans,cur);
        }
        cout<<ans<<"\n";
    }
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int c,T;
    cin>>c>>T;
    while (T--) annika::main();

    return 0;
}