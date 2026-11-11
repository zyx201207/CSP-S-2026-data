#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

//fo zu bao you, bu yao zha a
//xie le 2:30 le zen me zhi chu le yi ti
//wo yao zha le
//17:32
const int N = 2e5 + 5;
int arr[N], g[N][N], ans;


int main() {
    //freopen("subway.in", "r", stdin);
    //freopen("subway.out", "w", stdout);
    int c, t, n, d;
    cin >> c >> t;
    while (t--) {
        //memset(a, 0, sizeof(a));
        //memset(g, 0x3f, sizeof(g));
        ans = 0;
        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (abs(arr[j] - arr[i]) <= d) {
                    g[i][j] = g[j][i] = 1;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    if (g[i][j] + g[j][k] < g[i][k]) {
                        g[i][k] = g[i][j] + g[j][k];
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    if (g[i][j] + g[j][k] == g[i][k]) {
                        ans++;
                    }
                }
            }
        }
        cout << ans << ' ';
    }

    return 0;
}
