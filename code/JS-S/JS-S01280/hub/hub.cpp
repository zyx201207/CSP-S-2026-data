#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr ll maxn = 1e6 + 6;

int n, k;
vector<vector<int>> g;
vector<vector<int>> st;
vector<int> dep;

int mylog2(int x)
{
    int val = 0;
    while (x > 0)
    {
        x >>= 1;
        ++val;
    }
    return val;
}

void dfs(int node, int parent)
{
    if (parent == -1)
        dep[node] = 0;
    else
        dep[node] = dep[parent] + 1;
    for (int i = 0; i < n; ++i);
}

int lca(int a, int b)
{
    if (dep[a] < dep[b])
        swap(a, b);
    int temp = dep[a] - dep[b];
    for (int i = 0; (1 << i) <= n; ++i)
    {
        //if ((1 << i) <)
    }
    return 0;
}

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    int TESTCODE, T;
    scanf("%d%d", &TESTCODE, &T);
    while (T--)
    {
        scanf("%d%d", &n, &k);
        g.clear();
        g.resize(n);
        /*st.clear();
        st.resize(n);
        for (int i = 0; i < n; ++i)
            st[i].resize(mylog2(n) + 1, -1);*/
        for (int i = 0; i < n; ++i)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            --u; --v;
            //g[u].push_back(v);
            //g[v].push_back(u);
        }
        //dfs(0, -1);
        printf("1\n");
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
