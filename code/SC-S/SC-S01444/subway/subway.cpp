#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const ll N = 505, M = 5e5+5, D = 22, inf = 1e18;

int c, n, m, d, q;
ll w[M], net[N][N];
vector<PII> node[M];
ll dis[N][N];
bool vis[N];

void dijkstra(int s){
    for(int i=1;i<=n;i++){dis[s][i] = inf; vis[i] = false;}
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({dis[s][s] = 0, s});
    while(q.size()){
        int t = q.top().second; q.pop();
        if(vis[t]){continue;}
        vis[t] = true;
        for(int i=1;i<=n;i++)if(dis[s][t] + net[t][i] < dis[s][i]){
            dis[s][i] = dis[s][t] + net[t][i];
            q.push({dis[s][i], i});
        }
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  cout.tie(nullptr);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){net[i][j] = inf;}
    }
    for(int i=1;i<=m;i++){cin>>w[i];}
    for(int i=1;i<=n;i++){
        int k; cin>>k;
        while(k --){
            int a, t; cin>>a>>t;
            for(PII &x : node[a])if(t + x.second < net[i][x.first]){
                net[i][x.first] = net[x.first][i] = t + x.second;
            }
            node[a].push_back({i, t});
        }
    }
    for(int i=1;i<=n;i++){net[i][i] = 0;}
    /*for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<net[i][j]<<" \n"[j == n];
        }
    }*/
    for(int i=1;i<=n;i++){dijkstra(i);}
    while(q --){
        int s, t; cin>>s>>t;
        ll ans = inf;
        for(PII x : node[s]){
            for(PII y : node[t]){
                ans = min(ans, dis[x.first][y.first] + w[s] + w[t] + x.second + y.second);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}