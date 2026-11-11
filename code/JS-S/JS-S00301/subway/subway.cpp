#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,ll>
using namespace std;
const int maxN = 5e5+10;
int c,n,m,d,q;
ll w[maxN],dis[505][505];
vector<pii> pst[maxN];
pii pcs[50];

bool vis[505];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i <= m;i++) scanf("%lld",w+i);
    for(int i = 1;i <= n;i++){
        int k;cin>>k;
        for(int j = 1;j <= k;j++){
            ll a,t;cin>>a>>t;
            pii tmp = make_pair(i,t);
            pst[a].push_back(tmp);
        }
    }

    for(int u = 1;u <= n;u++){
        for(int v = 1;v <= n;v++){
            if(u == v) dis[u][v]=0;
            else dis[u][v] = 1e15;
        }
    }

    for(int i = 1;i <= m;i++){
        int len = 0;
        for(pii tmp:pst[i]) pcs[++len]=tmp;
        for(int l = 1;l <= len;l++){
            int u = pcs[l].first;
            ll w1 = pcs[l].second;
            for(int r = l+1;r <= len;r++){
                int v = pcs[r].first;
                ll w2 = pcs[r].second;
                if(w1+w2 < dis[u][v]){
                    dis[u][v]=dis[v][u]=w1+w2;
                }
            }
        }
    }

    for(int st = 1;st <= n;st++){
        for(int i = 1;i <= n;i++) vis[i] = 0;
        for(int cnt = 1;cnt <= n;cnt++){
            int u = 0;
            for(int i = 1;i <= n;i++){
                if(!vis[i] && !u) u = i;
                else if(!vis[i] && dis[st][i] < dis[st][u]){
                    u = i;
                }
            }
            vis[u] = 1;
            for(int v = 1;v <= n;v++){
                if(vis[v]) continue;
                if(dis[st][v] > dis[st][u]+dis[u][v]){
                    dis[st][v] = dis[st][u]+dis[u][v];
                }
            }
        }
    }

    //for(int i = 1;i <= n;i++){
    //    for(int j = 1;j <= n;j++){
    //        cout<<dis[i][j]<<' ';
    //    }
    //    cout<<'\n';
    //}

    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        ll ans = 1e15;
        for(pii awa:pst[x]){
            int u = awa.first,w1 = awa.second;
            for(pii qwq:pst[y]){
                int v = qwq.first,w2 = qwq.second;
                ans = min(ans,dis[u][v]+w1+w2);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}
