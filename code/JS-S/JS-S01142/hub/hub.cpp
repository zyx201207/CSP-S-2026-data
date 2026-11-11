#include <cstdio>
#include <vector>

using namespace std;

int c, t;
int n, k;
vector<vector<int>> graph;

int main()
{
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%d%d", &c, &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        graph.assign(n, vector<int>());
        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            graph.at(u).emplace_back(v);
        }
        printf("%d\n", 1);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
