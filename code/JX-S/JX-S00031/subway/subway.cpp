#include <bits/stdc++.h>

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, N, m, d, q;
    std:: cin >> c >> N >> m >> d >> q;
    std:: vector<int> w(m + 1);

    for (int i = 1; i <= m; ++i)
    {
        int x;
        std:: cin >> x;
        w[i] = x;
    }

    std:: vector<int> k(N + 1);
    std:: vector<std:: vector<int>> arr(N + 1), t(N + 1);

    for (int i = 1; i <= N; ++i)
    {
        int x;
        std:: cin >> x;
        k[i] = x;
        for (int j = 0; j < x; ++j)
        {
            int a, c;
            std:: cin >> a >> c;
            arr[i].push_back(a);
            t[i].push_back(c);
        }
    }

    while (q--)
    {
        int x, y;
        std:: cin >> x >> y;
        std:: cout << w[x] + w[y] << '\n';
    }

    return 0;
}