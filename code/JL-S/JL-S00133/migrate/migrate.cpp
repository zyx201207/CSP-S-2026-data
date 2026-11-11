#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
const int mod = 998244353;
const int inf = 0x3f3f3f3f;
const int N = 2000005;
int id, n;
LL x[N], d;
int dis[N], cnt[N];
int to[N], pre[N];
int c1[N], c2[N];
void work()
{
    cin >> n >> d;
    for (int i=1;i<=n;i++)
        cin >> x[i];
    if (id <= 10)
    {
        int ans = 0;
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<=n;j++)
                dis[j] = inf;
            dis[i] = 0, cnt[i] = 1;
            queue<int> q;
            q.push(i);
            //int sum = 0;
            while (!q.empty())
            {
                int t = q.front();
                q.pop();
                cnt[t] = min(cnt[t], 3);
                if (cnt[t] == 2)
                    ans ++;
                for (int i=t+1;i<=n;i++)
                {
                    if (x[i] - x[t] > d)
                        break;
                    if (dis[i] > dis[t] + 1)
                        dis[i] = dis[t] + 1, cnt[i] = cnt[t], q.push(i);
                    else if (dis[i] == dis[t] + 1)
                        cnt[i] += cnt[t];
                }
            }
            //for (int j=i+1;j<=n;j++)if (cnt[j]==2)cout<<i<<' '<<j<<'\n';
        }
        cout << ans << '\n';
        return;
    }
    if (id <= 12)
    {
        LL v = min((LL)n, 1 + d / (x[2] - x[1]));
        if (v <= 2)
            cout << "0\n";
        else
            cout << max(0ll, n + 3 - 2 * v) << '\n';
        return;
    }
    for (int i=1;i<=n;i++)
        c1[i] = c2[i] = 0;
    for (int i=1,j=1;i<=n;i++)
    {
        while (j < n && x[j + 1] - x[i] <= d)
            j ++;
        to[i] = j;
        c1[to[i]] ++;
    }
    for (int i=n,j=n;i;i--)
    {
        while (j > 1 && x[i] - x[j - 1] <= d)
            j --;
        pre[i] = j;
        c2[pre[i]] ++;
    }
    if (id <= 14 || 1)
    {
        LL ans = 0;
        for (int i=2;i<n;i++)
            ans += (LL)c2[i - 1] * c1[i];
        cout << ans << '\n';
        return;
    }
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T = 1;
    cin >> id>>T;
    while (T--)work();
    return 0;
}
