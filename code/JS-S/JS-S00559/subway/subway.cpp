#include<bits/stdc++.h>
#define pcr(i,a,b,c) for(int i=a;i<=b;i+=c)
#define rcp(i,a,b,c) for(int i=a;i>=b;i-=c)
#define pii pair<int,int>
#define pil pair<int,ll>
#define f first
#define s second
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N=5e5+3;
const int mod=998244353;
const ll inf=1e18;
int n,m,d,q,x[N],y[N];
ll w[N],dis[1003][1003],dij[N];
vector<pil> edge[505],scc[N];
void dfs(int st,int ed){
    bool vis[N],flag[505];
    memset(vis,0,sizeof(vis));
    memset(flag,0,sizeof(flag));
    queue<int> q;
    pcr(i,1,m,1) dij[i]=inf;
    dij[st]=0;vis[st]=1;
    for(auto e : scc[st]){
        flag[e.f]=1;
        for(auto x : edge[e.f]){
            if(x.f==st) continue;
            if(e.s+x.s<dij[x.f]) dij[x.f]=e.s+x.s;
            if(!vis[x.f]){q.push(x.f);vis[x.f]=1;}
        }
    }
    if(vis[ed]==1) return;
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto e : scc[u]){
            if(flag[e.f]) continue;
            for(auto x : edge[e.f]){
                if(x.f==u) continue;
                if(dij[u]+e.s+x.s<dij[x.f]) dij[x.f]=dij[u]+e.s+x.s;
                if(!vis[x.f]){q.push(x.f),vis[x.f]=1;}
            }
        }
    }
    return;
}
void solve1(){
    pcr(i,1,n,1){
        int k;
        cin>>k;
        pcr(j,1,k,1){
            int a;
            ll t;
            cin>>a>>t;
            edge[i].pb({a,t});
            scc[a].pb({i,t});
        }
    }
    pcr(i,1,q,1){
        int x,y;
        cin>>x>>y;
        dfs(x,y);
        cout<<dij[y]+w[x]+w[y]<<"\n";
    }
    return;
}
void solve2(){
    pcr(k,1,m,1){
        pcr(i,1,m,1){
            if(dis[i][k]==inf) continue;
            pcr(j,1,m,1){
                if(dis[k][j]==inf) continue;
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    pcr(i,1,q,1){
        int x,y;
        cin>>x>>y;
        cout<<dis[x][y]+w[x]+w[y]<<"\n";
    }
    return;
}
int bfs(int st,int ed){
    bool visx[N],visy[N],flag[505];
    memset(visx,0,sizeof(visx));
    memset(visy,0,sizeof(visy));
    memset(flag,0,sizeof(flag));
    queue<int> q;
    for(auto e : scc[st]){
        flag[e.f]=1;
        for(auto x : edge[e.f]){
            if(x.f==ed) return 1;
            dij[x.f]=1;
            if(!visx[x.f]){q.push(x.f);visx[x.f]=1;}
        }
    }
    for(auto e : scc[ed]){
        flag[e.f]=1;
        for(auto x : edge[e.f]){
            if(visx[x.f]) return 2;
            dij[x.f]=1;
            visy[x.f]=1;
        }
    }
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto e : scc[u]){
            if(flag[e.f]) continue;
            for(auto x : edge[e.f]){
                if(visx[x.f]) continue;
                if(visy[x.f]) return dij[u]+dij[x.f]+1;
                dij[x.f]=dij[u]+1;
                if(!visx[x.f]){q.push(x.f),visx[x.f]=1;}
            }
        }
    }
    return 0;
}
void solve3(ll t){
    pcr(i,1,q,1){
        int x,y;
        cin>>x>>y;
        int cnt=bfs(x,y);
        cout<<w[x]+w[y]+2*cnt*t<<"\n";
    }
    return;
}
void solve(){
    cin>>n>>m>>d>>q;
    pcr(i,1,m,1) cin>>w[i];
    if(n==1){
        pcr(i,1,q,1){
            int x,y;
            cin>>x>>y;
            cout<<w[x]+w[y]<<"\n";
        }
        return;
    }
    if(n==2){
        bool vis[3][N];
        memset(vis,0,sizeof(vis));
        pcr(i,1,n,1){
            int k;
            cin>>k;
            pcr(j,1,k,1){
                int a,t;
                cin>>a>>t;
                vis[i][a]=1;
                scc[a].pb({i,t});
            }
        }
        ll mint=inf;
        pcr(i,1,m,1) if(scc[i].size()==2) mint=min(mint,scc[i][0].s+scc[i][1].s);
        pcr(i,1,q,1){
            int x,y;
            cin>>x>>y;
            if((vis[1][x]&&vis[1][y])||(vis[2][x]&&vis[2][y])){
                if((vis[1][x]&&vis[1][y])&&(vis[2][x]&&vis[2][y])){
                    cout<<w[x]+w[y]+min(scc[x][0].s+scc[y][0].s,scc[x][1].s+scc[y][1].s)<<"\n";
                }else if(vis[1][x]&&vis[1][y]){
                    ll ans=0;
                    for(auto e : scc[x]) if(e.f==1) ans+=e.s;
                    for(auto e : scc[y]) if(e.f==1) ans+=e.s;
                    cout<<ans+w[x]+w[y]<<"\n";
                }else{
                    ll ans=0;
                    for(auto e : scc[x]) if(e.f==2) ans+=e.s;
                    for(auto e : scc[y]) if(e.f==2) ans+=e.s;
                    cout<<ans+w[x]+w[y]<<"\n";
                }
            }
            else{
                if((vis[1][x]&&vis[2][y])&&(vis[2][x]&&vis[1][y])){
                    cout<<w[x]+w[y]+mint+min(scc[x][0].s+scc[y][1].s,scc[x][1].s+scc[y][0].s)<<"\n";
                }else cout<<w[x]+w[y]+mint+scc[x][0].s+scc[y][0].s<<"\n";
            }
        }
        return;
    }
    if(n<=50){solve1();return;}
    int maxk=0,a[3];
    ll t[3],lst=0;
    bool flag1=true;
    if(m<=1000) pcr(i,1,m,1) pcr(j,1,m,1) dis[i][j]=inf;
    if(m<=1000) pcr(i,1,m,1) dis[i][i]=0;
    pcr(i,1,n,1){
        int k;
        cin>>k;
        maxk=max(maxk,k);
        pcr(j,1,k,1){
            int aa;
            ll tt;
            cin>>aa>>tt;
            if(lst==0) lst=tt;
            if(lst!=tt) flag1=false;
            if(j<=2) a[j]=aa;t[j]=tt;
            edge[i].pb({aa,tt});
            scc[aa].pb({i,tt});
        }
        if(k==2) dis[a[1]][a[2]]=dis[a[2]][a[1]]=t[1]+t[2];
    }
    if(maxk<=2){solve2();return;}
    if(flag1){solve3(lst);return;}
    //if(d<=2){solve3();return;}
    pcr(i,1,q,1){
        int x,y;
        cin>>x>>y;
        cout<<w[x]+w[y]<<"\n";
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c;
    cin>>c;
    int T;
    T=1;
    while(T--) solve();
    return 0;
}
