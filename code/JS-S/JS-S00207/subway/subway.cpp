#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<ll,int>
#define mkpr make_pair
#define fori(a,b) for(int i=a; i<=b; i++)
#define forj(a,b) for(int j=a; j<=b; j++)
const int MAXN=505, MAXM=500005, MAXD=22;
const ll INF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
int w[MAXM];
ll dis[MAXN][MAXN];
vector<pii> adj[MAXN];
ll disn[MAXN][MAXN];
vector<pii> sta2line[MAXM];
bool vis[MAXN];
void dij(int s){
    memset(vis,0,sizeof(vis));
    disn[s][s]=0;
    priority_queue<pii, vector<pii>, greater<> > pq;
    pq.push(mkpr(0,s));
    while(!pq.empty()){
        auto [dn,u]=pq.top();
        pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        for(auto [v,w]:adj[u]){
            if(vis[v]) continue;
            if(dn+w<=disn[s][v]){
                disn[s][v]=dn+w;
                pq.push(mkpr(disn[s][v],v));
            }
        }
    }
    return;
}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    fori(1,m){
        cin >> w[i];
    }
    memset(dis, 0x3f, sizeof(dis));
    memset(disn, 0x3f, sizeof(disn));
    fori(1,n){
        int k;
        cin >> k;
        forj(1,k){
            int a, t;
            cin >> a >> t;
            for(auto [line,t2]:sta2line[a]){
                if(t2+t<=dis[line][i]){
                    dis[line][i]=dis[i][line]=t2+t;
                }
            }
            sta2line[a].push_back(mkpr(i,t));
        }
    }
    fori(1,n){
        forj(1,n){
            if(i!=j && dis[i][j]<INF){
                adj[i].push_back(mkpr(j,dis[i][j]));
            }
        }
    }
    fori(1,n){
        dij(i);
    }

    while(q--){
        int s,t;
        cin >> s >> t;
        ll ans=LLONG_MAX;
        for(auto [line1,t1]:sta2line[s]){
            for(auto [line2,t2]:sta2line[t]){
                ans=min(ans, disn[line1][line2]+t1+t2+w[s]+w[t]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}