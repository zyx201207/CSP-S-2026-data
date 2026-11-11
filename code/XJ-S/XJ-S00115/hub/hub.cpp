#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
typedef long long LL;
int c,t,n,k;
int d[N],dist[N][105],nmax,ans = 1e9;
vector <int> g[N],a;
bool flag[N];
void bfs(int s,int k){
    dist[s][k] = 0;
    queue <int> q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        nmax = max(nmax,dist[u][k]);
        for(int i = 0;i < g[u].size();i++){
            int v = g[u][i];
            if(dist[u][k] + 1 < dist[v][k])   dist[v][k] = dist[u][k] + 1,q.push(v);
        }
    }
}
void solve(int v,int s){
    if(v == k+1){
        nmax = 0;
        for(int i = 1;i <= n;i++)   dist[i][103] = 1e9;
        for(int j = 0;j < k;j++){
            for(int i = 1;i <= n;i++)   dist[i][k] = 1e9;
            bfs(a[j],j);
            for(int i = 1;i <= n;i++)   dist[i][103] = min(dist[i][103],dist[i][j]);
        }
        for(int i = 1;i <= n;i++){
            nmax = max(nmax,dist[i][103]);
        }
        ans = min(ans,nmax);
        return;
    }
    for(int i = s+1;i <= n;i++){
        flag[i] = 1;
        a.push_back(i);
        solve(v+1,s);
        a.pop_back();
        flag[i] = 0;
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> c >> t;
    while(t--){
        
        cin >> n >> k;
        for(int i = 1;i < n;i++){
            int u,v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        solve(1,1);
        cout << ans << '\n';
        for(int i = 1;i <= n;i++)   g[i].clear();
        ans = 1e9;
    }
    return 0;
}