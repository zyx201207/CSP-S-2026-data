#include <bits/stdc++.h>
using namespace std;
const int N=105;
int num1(int x){
    int ans=0;
    while(x){
        ans+=x&1;
        x>>=1;
    }
    return ans;
}
bool sel[N];
int n,K,f[N],dep[N];
vector<int> a[N];
void dfs(int rt=1,int fa=0){
    f[rt]=fa; dep[rt]=dep[fa]+1;
    for(int v:a[rt]) if(v!=fa){
        dfs(v,rt);
    }
    return ;
}
int dis(int u,int v){
    int ans=0;
    if(dep[u]<dep[v]) swap(u,v);
    while(dep[u]!=dep[v]) ans++,u=f[u];
    while(u!=v) ans+=2,u=f[u],v=f[v];
    return ans;
}
int ltcheck(int rt=1,int fa=0){
    int ans=sel[rt];
    for(int v:a[rt]) if(v!=fa){
        int vans=ltcheck(v,rt);
        ans+=vans-(sel[rt]&&sel[v]);
    }
    return ans;
}
void solve(){
    cin>>n>>K;
    for(int i=1;i<=n;i++){
        a[i].clear(); f[i]=0;
    }
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs();
    int ans=1e9;
    for(int k=3;k<(1<<n);k++){
        if(num1(k)!=K) continue;
        for(int i=1;i<=n;i++) sel[i]=k&(1<<i-1);
        if(ltcheck()>2) continue;
        int tans=0;
        for(int i=1;i<=n;i++){
            if(sel[i]) continue;
            int ttans=1e9;
            for(int j=1;j<=n;j++){
                if(!sel[j]) continue;
                ttans=min(ttans,dis(i,j));
            }
            tans=max(tans,ttans);
        }
        ans=min(ans,tans);
    }
    cout<<ans<<'\n';
    return ;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int qgd,T; cin>>qgd>>T;
    while(T--) solve();
    return 0;
}
