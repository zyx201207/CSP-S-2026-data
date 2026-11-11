#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 24, M = 524;
int C, T;
int n, k;
int a[N];
vector<int> g[N];
int d[N], cnt[N];
int deg[N], in[N];
int ans = 0;
void topo(int s)
{
    queue<int> q;
    for(int i = 1; i < s; i++)
    {
        d[i] = 1e7;
        cnt[i] = 0;
        in[i] = deg[i];
    }
    d[s] = 0;
    cnt[s] = 1;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        //cout << u << " " << d[u] << " " << cnt[u] << " " << "\n";
        q.pop();
        for(auto v : g[u])
        {
            if(d[u] + 1 < d[v])
            {
                cnt[v] = 0;
                d[v] = d[u] + 1;
            }
            if(d[u] + 1 == d[v])
            {
                cnt[v] += cnt[u];
            }
            in[v]--;
            if(in[v] == 0) q.push(v);
        }
    }
    for(int i = 1; i < s; i++)
    {
        if(cnt[i] == 2)
        {
            //cout << s << " " << i << "\n";
            ans++;
        }
    }
    //cout << "\n";
}
signed main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> C >> T;
    while(T--)
    {
        cin >> n >> k;
        bool flg = 1;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if(i >= 3)
                if(a[i] - a[i - 1] != a[i - 1] - a[i - 2])
                    flg = 0;
            deg[i] = 0;
            g[i].clear();
        }
        if(n <= 3)
        {
            cout << "0\n";
            continue;
        }
        if(flg && n > 5000)
        {
            int ch = a[2] - a[1];
            int mx = k / ch;
            //cout << n << " " << mx << "\n";
            if(mx <= 1 || n < (2 * mx - 1)) cout << "0\n";
            else cout << n - (2 * mx - 1) << "\n";
            continue;
        }
        ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j < i; j++)
            {
                if(a[i] - a[j] <= k)
                {
                    //cout << i << " " << j << "\n";
                    g[i].push_back(j);
                    deg[j]++;
                }
            }
            topo(i);
        }
        cout << ans << "\n";
    }
    return 0;
}
