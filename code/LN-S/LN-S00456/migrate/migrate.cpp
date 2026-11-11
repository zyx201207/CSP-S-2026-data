#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i <= b; ++i)
#define ll long long
#define make_pair m_p
using namespace std;
ll read() {
    ll w = 0, f = 1;
    char c = getchar();
    while(c < '0' || c > '9') {
        if(c == '-') {
            f = -f;
        }
        c = getchar();
    }
    while('0' <= c && c <= '9') {
        w = w * 10 + c - '0';
        c = getchar();
    }
    return w * f;
}
void write(ll x) {
    if(x < 0) {
        putchar('-');
        x = -x;
    }
    if(x > 9) {
        write(x / 10);
    }
    putchar(x % 10 + '0');
}
const int N = 5005;
ll c, t, n, d, x[N];
ll dis[N], cnt[N];
vector<int> e[N];
void bfs(int s) {
    queue<int> q;
    q.push(s);
    fill(dis, dis + n + 1, (ll)1e18);
    fill(cnt, cnt + n + 1, 0);
    dis[s] = 0;
    while(!q.empty()) {
        int now = q.front();
        q.pop();
        for(const int to : e[now]) {
            if(dis[now] + 1 < dis[to]) {
                cnt[to] = 1;
                dis[to] = dis[now] + 1;
                q.push(to);
            } else if(dis[now] + 1 == dis[to]) {
                cnt[to] += cnt[now];
                q.push(to);
            }
        }
    }
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    c = read(), t = read();
    while(t--) {
        ll ans = 0;
        n = read(), d = read();
        rep(i, 1, n) {
            x[i] = read();
            e[i].clear();
        }
        rep(i, 1, n) {
            rep(j, 1, n) {
                if(i != j && abs(x[i] - x[j]) <= d) {
                    e[i].push_back(j);
                }
            }
        }
        rep(i, 1, n) {
            bfs(i);
            rep(j, 1, n) {
                if(i == j) {
                    continue;
                }
                if(cnt[j] == 2) {
                    ++ans;
                }
            }
        }
        cout << ans / 2 << '\n';
    }
    return 0;
}