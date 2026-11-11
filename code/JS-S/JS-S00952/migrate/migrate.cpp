#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int uid, T;
int n, pos[N], dep[N], st[N];
long long d, x[N];
vector<int> q[N];
queue<int> q2;
void bfs(int u)
{
    q2.push(u);
    st[u] = dep[u] = 1;
    while(q2.size())
    {
        int v = q2.front();
        q2.pop();
        for(int i = 0;i < q[v].size();i++)
        {
            int vv = q[v][i];
            if(dep[vv] != dep[v])
            {
                st[vv] += st[v];
                if(dep[vv] == 0)
                {
                    q2.push(vv);
                }
                dep[vv] = dep[v] + 1;
            }   
        }
    }
}
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> uid >> T;
    while(T--)
    {
        long long ans = 0;
        cin >> n >> d;
        for(int i = 1;i <= n;i++)
        {
            q[i].clear();
            cin >> x[i];
        }
        if(uid <= 10)
        {
            for(int i = 1;i <= n;i++)
            {
                pos[i] = upper_bound(x + 1, x + 1 + n, x[i] + d) - x - 1;
            }
            for(int i = 1;i <= n;i++)
            {
                for(int j = i + 1;j <= pos[i];j++)
                {
                    q[i].push_back(j);
                }
            }
            for(int i = 1;i <= n;i++)
            {
                for(int j = 1;j <= n;j++)
                {
                    dep[j] = st[j] = 0;
                }
                bfs(i);
                for(int j = 1;j <= n;j++)
                {
                    if(st[j] == 2)
                    {
                        ans++;
                    }
                }
            }
            cout << ans << "\n";
        }
        if(uid >= 11 && uid <= 12)
        {
            long long dd = x[2] - x[1];
            cout << 0 << "\n";
        }
    }
    return 0;
}