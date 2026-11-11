#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
typedef long long LL;
int c,t;
int n;
LL d,a[N];
vector <LL> g[N];
LL dist[N],num[N];
void bfs(int s){
    queue <int> q;
    q.push(s);
    dist[s] = 0;
    num[s] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i = 0;i < g[u].size();i++){
            int v = g[u][i];
            if(dist[v] > dist[u] + 1)   dist[v] = dist[u]+1,q.push(v),num[v] = 1;
            else if(dist[u] + 1 == dist[v]) num[v]++;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> c >> t;
    while(t--){
        LL ans = 0;
        cin >> n >> d;
        for(int i = 1;i <= n;i++)   cin >> a[i];
        for(int i = 1;i <= n;i++){
            for(int j = i+1;j <= n;j++){
                if(a[j] - a[i] <= d){
                    g[i].push_back(j);
                } else  break;
            }
        }
        for(int i = 1;i <= n;i++){
            memset(dist,0x3f,sizeof dist);
            memset(num,0,sizeof num);
            bfs(i);
            for(int j = i;j <= n;j++){
                if(num[j] == 2) ans++;
            }
        }
        cout << ans << '\n';
        for(int i = 1;i <= n;i++){
            g[i].clear();
        }
    }
    return 0;
}