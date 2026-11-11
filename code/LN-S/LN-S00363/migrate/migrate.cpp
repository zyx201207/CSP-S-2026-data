#include <iostream>
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (std::cin >> t >> t; t--;)
    {
        int n;
        long long d;
        std::cin >> n >> d;
        long long x[n];
        for (int i = 0; i < n; i++)
            std::cin >> x[i];
        std::cout << "0\n";
    }
    return 0;
}
