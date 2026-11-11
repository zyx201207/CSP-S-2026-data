#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

int c, n, m, d, q, w[100010];

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 0;i < m;i++){
        cin >> w[i];
    }
    for(int i = 0;i < n;i++){
        int k, x;
        cin >> k;
        for(int i = 0;i < 2 * k;i++){
            cin >> x;
        }
    }
    for(int i = 0;i < q;i++){
        int x, y, ans;
        cin >> x >> y;
        for(int i = x - 1;i < y;i++){
            ans += w[i];
        }
        cout << ans << endl;
    }

    return 0;
}

