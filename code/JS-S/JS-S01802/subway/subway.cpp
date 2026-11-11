#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e6;
struct node
{
    int time;
    int to;
};
int cnt[N];
vector <node> a[N];
bool f[N];
int c, n, m, d, p;
int minn;
void dfs(int fa, int now, int to, int time)
{
    //cout << now << " " << time << endl;
    if (to == now)
    {
        minn = min (minn, time);
        return;
    }
    if (time >= minn)
    {
        return;
    }
    for (int i = 0; i < a[now].size(); i++)
    {
        if (a[now][i].to != fa && !f[a[now][i].to])
        {
            f[now] = true;
            dfs(now, a[now][i].to, to, time + a[now][i].time);
            f[now] = false;

        }
    }
}
signed main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> p;
    for (int i = 1; i <= m; i++)
    {
        int start = i * 30;
        int to = i * 30 + 1;
        int time;
        cin >> time;
        a[start].push_back({time, to});
        a[to].push_back({time, start});
        cnt[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        int k;
        cin >> k;
        int last = -1;
        for (int j = 1; j <= k; j++)
        {
            int tmp, time;
            cin >> tmp >> time;
            cnt[tmp]++;
            a[tmp * 30].push_back({time, tmp * 30 + cnt[tmp]});
            a[tmp * 30 + cnt[tmp]].push_back({time, tmp * 30});
            if (last != -1)
            {
                a[last * 30 + cnt[last]].push_back({0, tmp * 30 + cnt[tmp]});
                a[tmp * 30 + cnt[tmp]].push_back({0, last * 30 + cnt[last]});
            }

            last = tmp;
        }
    }
    for (int i = 1; i <= p; i++)
    {
        memset(f, false, sizeof(f));
        int start, to;
        cin >> start >> to;
        minn = INT_MAX;
        dfs(-1, start * 30 + 1, to * 30 + 1, 0);
        cout << minn << '\n';
       // a[start * 30 + 1].push_back({minn, to * 30 + 1});
      //  a[to * 30 + 1].push_back({minn, start * 30 + 1});
    }
    return 0;
}
