#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
// const ll N=1e6+10;
const ll N=1e5+10;
ll c,T,n,k,x,y,fa[N],ct[N],d[N],f[N][22],d1[N],ans;
bool p[N];
vector<ll> e[N];
ll getfa(ll x){return fa[x]==x?x:fa[x]=getfa(fa[x]);}
void hb(ll x,ll y){
    x=getfa(x),y=getfa(y);
    if(x!=y) fa[x]=y;
}
bool chk(){
    for(int i=1;i<=n;i++) fa[i]=i,ct[i]=0;
    for(int i=1;i<=n;i++)
        if(p[i])
        for(auto y:e[i])
            if(p[y]) hb(i,y);
    for(int i=1;i<=n;i++)
        if(p[i]) ct[getfa(i)]=1;
    ll res=0;
    for(int i=1;i<=n;i++) res+=ct[i];
    return res<=2;
}
void dfs2(ll x,ll fa){
    d[x]=d[fa]+1,f[x][0]=fa;
    for(int i=1;i<=20;i++) f[x][i]=f[f[x][i-1]][i-1];
    for(auto y:e[x])
        if(y!=fa) dfs2(y,x);
}
ll lca(ll x,ll y){
    if(d[x]<d[y]) swap(x,y);
    for(int i=20;~i;i--)
        if(d[f[x][i]]>=d[y]) x=f[x][i];
    if(x==y) return x;
    for(int i=20;~i;i--)
        if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i];
    return f[x][0];
}
ll dis(ll x,ll y){
    ll l=lca(x,y);
    return d[x]+d[y]-d[l]*2;
}
ll solve(){
    ll res=0;
    for(int i=1;i<=n;i++)
        if(!p[i]){
            ll cnt=1e18;
            for(int j=1;j<=n;j++)
                if(p[j]) cnt=min(cnt,dis(i,j));
            res=max(res,cnt);
        }
    return res;
}
void dfs(ll x,ll ct){
    if(ct>k) return;
    if(x>n){
        if(ct==k&&chk()) ans=min(ans,solve());
        return;
    }
    dfs(x+1,ct);p[x]=1,dfs(x+1,ct+1),p[x]=0;
}
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    if(c==7){
        while(T--){
            cin>>n>>k;ans=1e18;
            for(int i=1;i<=n;i++) e[i].clear();
            for(int i=1;i<n;i++) cin>>x>>y,e[x].pb(y),e[y].pb(x);
            for(int i=1;i<n;i++){
                dfs2(i,0);
                for(int j=1;j<=n;j++) d1[j]=d[j];
                for(int j=i+1;j<=n;j++){
                    dfs2(j,0);
                    ll cnt=0;
                    for(int k=1;k<=n;k++)
                        cnt=max(cnt,min(d1[k],d[k]));
                    ans=min(ans,cnt);
                }
            }
            cout<<ans<<"\n";
        }
        return 0;
    }
    while(T--){
        cin>>n>>k;ans=1e18;
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1;i<n;i++) cin>>x>>y,e[x].pb(y),e[y].pb(x);
        dfs2(1,0);
        dfs(1,0);
        cout<<ans<<"\n";
    }
    return 0;
}