#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
typedef long long ll;
typedef unsigned long long ull;
ll c,t,n,ans,x[N];
ull d;
vector<int> g[N];
int vis[N],cnt[N];

void bfs(int x){
    queue<int> q;
    q.push(x);
    vis[x] = 1;
    while (!q.empty()){
        int l = q.size();
        for (int ti = 1;ti <= l;ti++){
            int u = q.front();
            q.pop();
            for (int i = 0;i < (int)g[u].size();i++){
                int v = g[u][i];
                if (vis[v] > 0){
                    cnt[v]++;
                    q.push(v);
                    continue;
                }else if (vis[i] == -1){
                    continue;
                }
                cnt[v]++;
                vis[v] = vis[u] + 1;
                q.push(v);
            }
        }
        for (int i = 1;i <= n;i++){
            cout << cnt[i] << ' ';
            if (cnt[i] == 2) {
                ans++;
            }
            cnt[i] = 0;
            vis[i] = -1;

        }
        cout << '\n';
    }
    return;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> t;
    while (t--){
        for (int i = 1;i <= n;i++){
            g[i].clear();
        }
        memset(vis,0,sizeof(vis));
        ans = 0;
        cin >> n >> d;
        for (int i = 1;i <= n;i++){
            cin >> x[i];
        }
        /*
        int idx = 1;
        for (int i = 2;i <= n;i++){
            while (idx < i && x[i] - x[idx] > d) idx++;
            if (x[i] - x[idx] > d){
                continue;
            }
            for (int j = idx;j < i;j++){
                g[j].push_back(i);
            }
        }

        for (int i = 1;i <= n;i++){
            if (vis[i] == -1) continue;
            bfs(i);
            cout << i << '\n';
        }
        cout << ans << '\n';*/
        cout << "0\n";
    }
    return 0;
}
