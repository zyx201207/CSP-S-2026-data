#include <bits/stdc++.h>
using namespace std;
int c, T;
int n, k;
vector<vector<int>> edg;
vector<unordered_map<int, int>> fa;
vector<int> ord;
int Ufind(int x, int ve)
{
    if (ve == 0)
        return x;
    if (!fa[x].count(ve))
        return fa[x][ve] = Ufind(x, ve - 1);
    return fa[x][ve] = Ufind(fa[x][ve], ve);
}
void dfs(int idx)
{
    if (ord.size() == k)
    {
        unordered_set<int> cnter;
        for (auto X : ord)
            cnter.insert(Ufind(X, idx));
        if (cnter.size() > 2)
            return;
        ;
        return;
    }
    dfs(idx + 1);
    ord.push_back(idx);
    dfs(idx + 1);
    ord.pop_back();
}
int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cin >> c >> T;
    while (T--)
    {
        edg.clear();
        cin >> n >> k;
        edg.resize(n + 1);
        for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            edg[u].push_back(v);
            edg[v].push_back(u);
        }
        dfs(1);
    }
    return 0;
}