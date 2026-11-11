#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a);i <= (b);i++)
typedef long long ll;
typedef pair<int, int> pii;
const int Max = 1e6+5;
int n, k, ans;
int f[Max];
bool in[Max];
vector<int> g[Max];
int find_fa(int x){return (f[x] == x?x:f[x] = find_fa(f[x]));}
void join(int x, int y){x = find_fa(x),y = find_fa(y);if(x^y)f[x] = y;}
int bfs(int x)
{
    queue<pii> q;q.push(make_pair(x, 0));
    vector<int> vis(n+5, 0);vis[x] = 1;
    while(!q.empty())
    {
        pii p = q.front();q.pop();int u = p.first, len = p.second;
        if(in[u])return len;
        for(int v:g[u])
        {
            if(!vis[v])
                q.push(make_pair(v, len+1)), vis[v] = 1;
        }
    }
}
void dfs(int x, int num)
{
    if(x == n&&num < k)return ;
    if(num == k)
    {
        rep(i, 1, n)f[i] = i;
        rep(i, 1, n)
        {
            if(in[i])
            {
                for(int v:g[i])
                {
                    if(in[v])
                        join(v, i);
                }
            }
        }
        set<int> s;
        rep(i, 1, n)
        {
            if(in[i])s.insert(find_fa(i));
        }
        if((int)s.size() > 2)return ;
        int res = 0;
        rep(i, 1, n)
            res = max(res, bfs(i));
        if(ans > res)
        {
            //rep(i, 1, n)cout << in[i] << " ";
            //cout << "\n";
            ans = min(ans, res);
        }
        return ;
    }
    rep(i, x+1, n)
    {
        in[i] = 1;
        dfs(i, num+1);
        in[i] = 0;
    }
}
void solve()
{
    cin >> n >> k;ans = 1e8;
    rep(i, 1, n-1)
    {
        int u, v;cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, 0);
    cout << ans << "\n";
}
int main()
{
    //My last year and thank you for watching this!
    //luogu uid 687685
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c, _;cin >> c >> _;
    while(_--)solve();
    return 0;
}
