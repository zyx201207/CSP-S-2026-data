#include <bits/stdc++.h>
#define qi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
#define MP(a,b) make_pair(a,b)
#define pb(x) push_back(x)
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef pair<int,int> pii;
typedef pair<int,string> pis;
const int N = 5e5+5;
int c,n,m,d,q;
set <int> p[501];
int dist[501][501];
map <int,set<int> > Map;
map <pii,int> cost;
int w[N];
signed main(){
    qi;
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dist,0x3f,sizeof(dist));
    cin >> c >> n >> m >> d >>q;
    for(int i=1;i<=m;i++){
        cin >> w[i];
    }
    for(int i=1;i<=n;i++){
        int k;
        cin >> k;
        for(int j=1;j<=k;j++){
            int a,t;
            cin >> a >> t;
            cost[MP(a,i)]=t;
            p[i].insert(a);
            Map[a].insert(i);
        }
    }
    for(int i=1;i<=m;i++){
        if(Map[i].size()<=1)continue;
        for(int u:Map[i]){
            for(int v:Map[i]){
                if(u!=v){
                    dist[u][v]=min(dist[u][v],cost[MP(i,u)]+cost[MP(i,v)]);
                    dist[v][u]=min(dist[v][u],cost[MP(i,u)]+cost[MP(i,v)]);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        dist[i][i]=0;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(i!=j&&i!=j&&j!=k){
                    dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
                    dist[j][i]=min(dist[j][k]+dist[k][i],dist[j][i]);
                }
            }
        }
    }
    int ans=0x3f3f3f3f3f3f3f3f;
    while(q--){
        int s,t;
        cin >> s >> t;
        ans=0x3f3f3f3f3f3f3f3f;
        for(auto u:Map[s]){
            if(p[u].count(t)){
                ans=min(ans,w[s]+w[t]+cost[MP(s,u)]+cost[MP(t,u)]);
                continue;
            }
            for(int v:Map[t]){
                ans=min(ans,w[s]+w[t]+cost[MP(s,u)]+cost[MP(t,v)]+dist[u][v]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
