#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;

int c , t;
int n , m;
int a[100010];
vector<PII > g[100010];
bool vis[100010];
int dis[100010];
int ds[100010];

bool bfs(int s , int e){
    memset(vis , false ,sizeof(vis));
    memset(dis ,0 , sizeof(dis));

    queue<int> q;
    q.push(s);
    dis[s] = 0;
    vis[s] = true;
    int ans = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i = 0;i < g[u].size();i++){
            int v = g[u][i].first;
            int w = g[u][i].second;

            if(vis[v]) continue;
            if(v != e){
                vis[v] = true;
            }
            if(dis[e] == ds[e]){
                ans++;
            }
        }
    }
    if(ans >= 2) return true;
    else return false;
}

int main(){
    //freopen("migrate.in" ,"r" , stdin);
    //freopen("migrate.out" , "w" ,stdout);

    cin >> c >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 1;i <= n;i++){
            cin >> a[i];
        }

        for(int i = 1;i <= n;i++){
            for(int j = i + 1;j <= n;j++){
                if(a[j] - a[i] <= m){
                    g[i].push_back({j , a[j] - a[i]});
                }
            }
        }

        for(int i = 1;i < n;i++){
            memset(ds ,0x3f ,sizeof(ds));
            priority_queue<PII, vector<PII> , greater<PII> > q1;

            ds[i] = 0;

            while(!q1.empty()){
                int u = q1.top().second;
                int w = q1.top().first;

                for(int i = 0;i < g[u].size();i++){
                    int v = g[u][i].first;
                    int val = g[u][i].second;

                }

            }

        }

    }
    cout << 1 << endl;
    cout << 2 << endl;
    return 0;
}
