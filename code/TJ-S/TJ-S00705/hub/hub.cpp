// pwd: j:Trick||Treat! s:Oct31==Dec25?
// shen ren kao chang, kai kao 5 fen zhong hai mei fa ti
#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;

const int N = 2e6 + 5;
int c, T;
int n, k;
int hd[N], nxt[N], to[N], tot;
bool f[N], vis[N];
int vis2[N];
int minn;

void add(int u, int v)
{
    ++tot;
    to[tot] = v;
    nxt[tot] = hd[u];
    hd[u] = tot;
}

queue<int> q;

void sol()
{
    int cntl = 0;
    fill(vis + 1, vis + n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (f[i] == 1 && vis[i] == 0)
        {
            if (cntl >= 2) return;
            cntl++;
            vis[i] = 1;
            q.push(i);
            while (!q.empty())
            {
                int now = q.front();
                q.pop();
                for (int e = hd[now]; e; e = nxt[e])
                {
                    int nn = to[e];
                    if (!f[nn]) continue;
                    if (vis[nn]) continue;
                    vis[nn] = 1;
                    q.push(nn);
                }
            }
        }
    }
    // cout << "aaa: " << cntl << '\n';
    int maxn = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << f[i] << ' ';
    // }
    // cout << '\n';
    for (int i = 1; i <= n; i++)
    {
        if (f[i]) continue;
        // cout << "--------i: " << i << '\n';
        fill(vis2 + 1, vis2 + n + 1, -1);
        q.push(i);
        vis2[i] = 0;
        while (!q.empty())
        {
            bool flag = 0;
            int now = q.front();
            q.pop();
            // cout << "now: " << now << '\n';
            for (int e = hd[now]; e; e = nxt[e])
            {
                int nn = to[e];
                // cout << nn << '\n';
                if (vis2[nn] != -1) continue;
                vis2[nn] = vis2[now] + 1;
                q.push(nn);
                // cout << "vis2: " << vis2[nn] << '\n';
                if (f[nn])
                {
                    // cout << "f[" << nn << "] = 1 "; 
                    maxn = max(maxn, vis2[nn]);
                    // cout << "maxn: " << maxn << '\n';
                    flag = 1;
                    break;
                }
            }
            // cout << '\n';
            if (flag) break;
        }
        while (!q.empty()) q.pop();
    }
    // cout << "maxn: " << maxn << '\n';
    minn = min(minn, maxn);
}

// void dfs(int u, int fa, int cnt)
// {
//     cout << "dfs " << u << ' ' << fa << ' ' << cnt << '\n';
//     if (cnt == k)
//     {
//         cout << "cnt == k" << '\n';
//         sol();
//         return;
//     }
//     for (int e = hd[u]; e; e = nxt[e])
//     {
//         int v = to[e];
//         if (v == fa) continue;
//         f[v] = 1;
//         dfs(v, u, cnt + 1);
//         f[v] = 0;
//         dfs(v, u, cnt);
//     }
// }

void solve()
{
    minn = 4e18;
    fill(hd + 1, hd + n + 1, 0);
    fill(nxt + 1, nxt + n + 1, 0);
    fill(to + 1, to + n + 1, 0);
    cin >> n >> k;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << ' ';
    // }
    // cout << '\n';
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    for (int i = 0; i <= (1 << n) - 1; i++)
    {
        int cnt1 = 0;
        int tmp = i, cur = 0;
        while (tmp > 0)
        {
            ++cur;
            if (tmp % 2 == 1)
            {
                // cout << "f[" << i << 
                f[cur] = 1, cnt1++;
            }
            tmp /= 2;
        }
        if (cnt1 == k) sol();
        fill(f + 1, f + n + 1, 0);
    }
    // f[1] = 1;
    // dfs(1, 0, 1);
    // f[1] = 0;
    // dfs(1, 0, 0);
    cout << minn << '\n';
}

signed main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    cin >> c >> T;
    while (T--)
    {
        solve();
    }
	return 0;
}
