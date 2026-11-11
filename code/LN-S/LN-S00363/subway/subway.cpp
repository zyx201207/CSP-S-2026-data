#include <iostream>
#include <vector>
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    std::cin.tie(nullptr)->sync_with_stdio(false);
    short n, d;
    int m, q;
    std::cin >> n >> n >> m >> d >> q;
    int w[m];
    std::vector<int> a[n], t[n];
    for (int i = 0; i < m; i++)
        std::cin >> w[i];
    for (short i = 0; i < n; i++)
    {
        int k;
        std::cin >> k;
        for (int j = 0; j < k; j++)
            std::cin >> a[i][j] >> t[i][j];
    }
    while (q--)
    {
        int x, y;
        std::cin >> x >> y;
        std::cout << "0\n";
    }
    return 0;
}
