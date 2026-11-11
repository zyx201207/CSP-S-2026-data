#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int C, T, n, d, a[N];
int cnt[N];
long long ans = 0;
vector<int> g[N];

void dfs(int u, int t, int step)
{
    if(u == t)
    {
        cnt[step]++;
        return;
    }
    for(int v : g[u])
    {
        if(v > t) continue;
        dfs(v, t, step + 1);
    }
}

bool chk()
{
    for(int i = 1; i <= n; i++)
        if(cnt[i] != 0)
        {
            if(cnt[i] == 2) return true;
            else return false;
        }
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> C >> T;
    while(T--)
    {
        memset(g, 0, sizeof(g));
        cin >> n >> d;
        for(int i = 1; i <= n; i++) cin >> a[i];
        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++)
            {
                if(abs(a[i] - a[j]) <= d) g[i].push_back(j);
                else break;
        	}

        ans = 0;
        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++)
            {
                memset(cnt, 0, sizeof(cnt));
                dfs(i, j, 0);
                if(chk()) ans++;
            }

        cout << ans << "\n";
    }
    return 0;
}
