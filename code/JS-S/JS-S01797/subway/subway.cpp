#include<bits/stdc++.h>
using namespace std;
int w[500001];
vector<int> a[501];
vector<int> t[501];
vector<int> b[500001];
int ranks[501][500001];
pair<int, int> que[100001];
int c, n, m, d, q;
bool visited[501];
long long best = LONG_LONG_MAX;
void dfs(int u, long long sum, int ed/*, vector<int> path*/)
{
    //cout << "now:" << u << " sum:" << sum << " end:" << ed << " the best:" << best << '\n';
    if(u == ed)
    {
        best = min(best, sum);
        //cout << "a path:\n";
        //for(auto it : path)
        //{
            //cout << it << " ";
        //}
        //cout << '\n';
    }
    if(sum > best)
    {
        return ;
    }
    for(int j = 0;j < b[u].size();j ++)
    {
        for(int i = 0;i < a[b[u][j]].size();i ++)
        {
            int temp = b[u][j];
            int v = a[temp][i];
            if(!visited[temp])
            {
                visited[temp] = 1;
                //path.push_back(v);
                dfs(v, sum + t[temp][ranks[temp][u]] + t[temp][i], ed/*, path*/);
                //path.pop_back();
                visited[temp] = 0;
            }

        }
    }
}
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i ++)
    {
        cin >> w[i];
    }
    for(int i = 1;i <= n;i ++)
    {
        int k;
        cin >> k;
        for(int j = 1;j <= k;j ++)
        {
            int x, y;
            cin >> x >> y;
            a[i].push_back(x);
            t[i].push_back(y);
            b[x].push_back(i);
            ranks[i][x] = a[i].size() - 1;
        }
    }
    for(int i = 1;i <= q;i ++)
    {
        best = LONG_LONG_MAX;
        memset(visited, 0, sizeof(visited));
        cin >> que[i].first >> que[i].second;
        dfs(que[i].first, w[que[i].first], que[i].second/*, vector<int>()*/);
        cout << best + w[que[i].second] << "\n";
    }
    return 0;
}
