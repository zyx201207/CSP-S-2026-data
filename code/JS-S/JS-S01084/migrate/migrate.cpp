#include <bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(int i = a; i <= b; i++)
#define For2(i,a,b) for(int i = a; i >= b; i--)
using namespace std;
const int N = 1e6 + 5;
inline ll read() {
    ll x = 0,fl = 1; char c = getchar();
    while (!isdigit(c)) {{if (c == '-') fl = -1;}c = getchar();}
    while (isdigit(c)) {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * fl;
}
int n;
ll a[N],d;
vector<int> e[N];
ll dis[5001][5001],cnt[5001][5001];
void bfs(int st) {
    For (i,1,n) dis[st][i] = N;
    dis[st][st] = 0; cnt[st][st] = 1;
    queue<int> q; q.push(st);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (n > 300 && cnt[st][u] > 3) continue;
        for (int v : e[u]) {
            if (dis[st][v] == N) {
                dis[st][v] = dis[st][u] + 1;
                cnt[st][v] = cnt[st][u];
                q.push(v);
            }else if (dis[st][v] == dis[st][u] + 1) {
                cnt[st][v] += cnt[st][u];
                if (cnt[st][v] > 2) cnt[st][v] = 3;
            }
        }
    }
}
void work() {
    n = read(),d = read();
    For (i,1,n) {
        For (j,1,n) dis[i][j] = cnt[i][j] = 0;
        e[i].clear();
    }
    For (i,1,n) a[i] = read();
    For (i,1,n) {
        For (j,1,n) {
            if (i == j) continue;
            if (a[j] - a[i] <= d) {
                e[i].push_back(j);
            }
        }
    }
    For (i,1,n) bfs(i);
    int ans = 0;
    For (i,1,n) {
        For (j,i+1,n) {
            if (dis[i][j] != N && cnt[i][j] == 2) ans++;
        }
    }
    cout << ans << endl;
}
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c = read(),tc = read();
    while (tc--) work();
    return 0;
}
