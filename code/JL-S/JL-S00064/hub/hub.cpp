#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define mem(a,b) memset(a,b,sizeof(a));
#define all(x) (x).begin(),(x).end()
#define abs_(x) ((x)<0?-(x):(x))
#define sz(x) ((int)(x).size())
#define ull unsigned long long
#define pb push_back
#define fi first
#define se second
using namespace std;
int c,T;
int n,k;
vector<int>mp[1000005];
namespace bitmask{
    bool col[1000005];
    bool vis[1000005];
    int dep[1000005];
    int fa[1000005];
    int ans;
    int qwq;//黑点抠出来子图边数
    void get_tetr(int u,int faa){
        dep[u]=dep[faa]+1;
        fa[u]=faa;
        rep(i,0,sz(mp[u])-1){
            int v=mp[u][i];
            if(v==faa) continue;
            get_tetr(v,u);
            qwq+=(col[u]&col[v]);
        }
    }
    int lca(int u,int v){
        while(u!=v){
            if(dep[u]<dep[v]) swap(u,v);
            u=fa[u];
        }
        return u;
    }
    int dis(int u,int v){return dep[u]+dep[v]-2*dep[lca(u,v)];}
    void solve(){
        ans=1e18;
        rep(s,0,(1<<n)-1){
            if(__builtin_popcount(s)!=k) continue;
            qwq=0;
            rep(i,1,n) col[i]=vis[i]=0;
            rep(i,1,n){
                if(s&(1<<i-1)) col[i]=1;
            }
            get_tetr(1,0);
            if(k-qwq>2) continue;
            int res=0;
            rep(i,1,n){
                if(!col[i]){
                    int qwqq=1e18;
                    rep(j,1,n){
                        if(!col[j]) continue;
                        qwqq=min(qwqq,dis(i,j));
                    }
                    // cout<<i<<' '<<qwq<<"<------\n";
                    res=max(res,qwqq);
                }
            }
            // rep(i,1,n) cout<<col[i]<<' ';
            // cout<<res<<"\n";
            ans=min(ans,res);
        }
        cout<<ans<<"\n";
    }
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        rep(i,1,n-1){int u,v;cin>>u>>v;mp[u].pb(v);mp[v].pb(u);}
        bitmask::solve();
        rep(i,1,n) mp[i].clear();
    }
    return 0;
}