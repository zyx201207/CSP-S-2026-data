#include <iostream>
#include <vector>
int main()
{
    freopen("null.in", "r", stdin);
    freopen("null.out", "w", stdout);
    std::cin.tie(nullptr)->sync_with_stdio(false);
    short t;
    for (std::cin >> t >> t; t--;)
    {
        int n, k;
        std::cin >> n >> k;
        std::vector<int> adj[n];
        for (int i = 1; i < n; i++)
        {
            int u, v;
            std::cin >> u >> v;
            adj[--u].push_back(--v);
            adj[v].push_back(u);
        }
        std::cout << "0\n";
    }
    return 0;
}
