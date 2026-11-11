#include <bits/stdc++.h>//t4 - hub

using namespace std;

vector<vector<int> >tree(1000007,vector<int>());
vector<int>son(1000007,0),dep(1000007,0);
int n,c,t,k;

void dfs(int u,int pa)
{
    for (auto v : tree[u])
    {
        if (v != pa)
        {
            dfs(v,u);
            son[u] += son[v];
            dep[u] = max(dep[u],dep[v] + 1);
        }
    }
    son[u]++;
}

void dfs2(int u,int pa,int val,int &r)
{
    if (dep[u] < val)
    {
        r -= son[u];
        return;
    }
    for (auto v : tree[u])
    {
        if (v != pa)
        {
            dfs(u,v);
        }
    }
}

int solve(int x)
{
    //1
    int r = son[1];
    dfs2(1,0,x,r);
    if (k >= r)return 1;
    //2
    return 0;
}

int main()
{
    //freopen("hub.in","r",stdin);
    //freopen("hub.out","w",stdout);
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> k;
        tree.clear();
        son.clear();dep.clear();
        for (int i = 1;i <= n - 1;i++)
        {
            int u,v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        dfs(1,0);
        int l = 0,r = n - 1;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            int ddd = solve(mid);
            if (ddd)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << l << endl;
    }
    return 0;
}
