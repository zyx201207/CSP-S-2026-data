#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MAXN = 31;
constexpr int INF = 1e18;
int n, k, result;
int dist[MAXN][MAXN];
vector<int> E[MAXN];
bool choice[MAXN];
bool vis[MAXN];
bool check() {
    int sum = 0;
    memset(vis, 0, sizeof vis);
    for(int i = 1; i <= n; i++) {
        if(choice[i] && !vis[i]) {
            queue<int> q;
            q.push(i);
            sum++;
            while(!q.empty()) {
                int nnow = q.front(); q.pop();
                vis[nnow] = 1;
                for(int to : E[nnow]) {
                    if(!choice[to] || vis[to]) continue;
                    q.push(to);
                }
            }
        }
    }

    return sum <= 2;
}
void dfs(int idx, int sum) {
    if(sum == k) {
        //for(int i = 1; i <= n; i++) {
        //      cout << choice[i] << ' ';
        //} cout << endl;
        if(check()) {
            int Max = -1;
            for(int i = 1; i <= n; i++) {
                int mmin = INF;
                for(int j = 1; j <= n; j++) {
                    if(choice[j]) mmin = min(mmin, dist[i][j]);
                }
                Max = max(Max, mmin);
            }
            result = min(result, Max);
        }
        return ;
    }
    if(idx == n + 1) {
        return ;
    }
    choice[idx] = 1;
    dfs(idx + 1, sum + 1);
    choice[idx] = 0;
    dfs(idx + 1, sum);
}
void work() {
    result = INF;
    cin >> n >> k;
    for(int i = 1; i <= n; i++) E[i].clear();
    for(int i = 1; i < n; i++) {
        int x, y; cin >> x >> y;
        E[x].push_back(y);
        E[y].push_back(x);
    }
    memset(dist, 0x3f, sizeof dist);
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<tuple<int, int> > > que;
    for(int i = 1; i <= n; i++) {
        dist[i][i] = 0;
        que.push(make_tuple(0, i));
        while(!que.empty()) {
            tuple<int, int> hafsdjhfkldf = que.top();
            que.pop();
            int nnow = get<1>(hafsdjhfkldf);
            int val = get<0>(hafsdjhfkldf);
            if(val > dist[i][nnow]) {
                continue;
            }
            for(int to : E[nnow]) {
                int new_w = val + 1;
                if(new_w < dist[i][to]) {
                    dist[i][to] = new_w;
                    que.push(make_tuple(new_w, to));
                }
            }
        }
    }
    dfs(1, 0);

    cout << result << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, t; cin >> c >> t;
    while(t--) {
        work();
    }
    //cout << "Hello OI_____2023.1" << endl;
    //cout << "Goodbye OI______2026.10.32" << endl;
    //cout << "user: lxy_qwq" << endl;
    return 0;
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
