#include<bits/stdc++.h>
using namespace std;
long long n, m, f = 1;
long long a[500005], ans[300005] = {0}, dis[300005];
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    while(f <= n) {
        for (int i = f; i <= n; i++) {
            if (dis[a[i]] == 0) {
                dis[a[i]] = i;
            }
            else {
                for(int j = 1; j <= m; j++) {
                    if (dis[a[i]] <= dis[j] && dis[j] < i) {
                        dis[j] = 0;
                    }
                }
                dis[a[i]] = i;
            }
        }
        for (int i = 1; i <= m; i++) {
            if (dis[i] != 0) {
                ans[i]++;
            }
        }

        f++;
        for (int i = 1; i <= m; i++) {
            dis[i] = 0;
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
