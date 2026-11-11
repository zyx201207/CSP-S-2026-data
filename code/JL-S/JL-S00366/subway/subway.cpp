#include <bits/stdc++.h>
using namespace std;
int w[500005];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    cin >> c >> n >>m >> d >>q;
    for (int i = 1; i <= m; i++)
        cin >> w[i];
    for (int i = 1; i <= q; i++)
    {
        int ans = 0;
        for (int j = 1; j <= 5; j++)
            {
                random_shuffle(w+1, w + 1 +n);
                ans+=w[i];
            }
        cout<<ans<<endl;
    }
    return 0;
}
