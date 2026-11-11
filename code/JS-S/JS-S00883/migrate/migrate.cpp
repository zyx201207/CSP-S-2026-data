#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, d;
long long x[2000010];

int cnt[2000010];
void bfs(int st)
{
    for (int i = 1; i <= n; i++)
        cnt[i] = 0;
    queue <int> q, f;
    q.push(st); f.push(st);
    q.push(st); f.push(st);
    while (!q.empty())
    {
        int u = q.front(), l = f.front(); q.pop(); f.pop();
        for (int v = u+1; v <= n && x[v] - x[u] <= d; v++) { cnt[v]+=(l != st); q.push(v); f.push(u); }
    }
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int c, T; cin >> c >> T;
    while (T--)
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
            cin >> x[i];
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            bfs(i);
            for (int j = 1; j <= n; j++)
                if (j != i && cnt[j] == 2)
                    ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}
