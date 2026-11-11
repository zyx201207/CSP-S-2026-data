#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int c, t;
int n, d;
long long x[2000010];
bool canfly[2000010][3];
int cango[2000010][2];

long long ans;

int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin >> c >> t;

    if (c == 11 || c == 12) {
        while (t--) {
            memset(x, sizeof x, 0);
            memset(canfly, sizeof canfly, 0);
            memset(cango, sizeof cango, 0);
            n = 0, d = 0, ans = 0;

            cin >> n >> d;
            for (int i = 1; i <= n; ++i) cin >> x[i];

            int t = x[2] - x[1];
            int xx = d / t * 2 + 1;

            cout << n - xx + 1 << endl;
        }
    }
    else while (t--) {
        memset(x, sizeof x, 0);
        memset(canfly, sizeof canfly, 0);
        memset(cango, sizeof cango, 0);
        n = 0, d = 0, ans = 0;

        cin >> n >> d;
        for (int i = 1; i <= n; ++i) cin >> x[i];

        for (int i = 1; i <= n - 1; ++i) canfly[i][1] = (x[i + 1] - x[i] <= d);
        for (int i = 1; i <= n - 2; ++i) canfly[i][2] = (x[i + 2] - x[i] <= d);

        for (int i = 1; i <= n - 2; ++i) if (canfly[i][2]){
            cango[i][0] = 1, cango[i][1] = 1;
            int j = i;
            while(canfly[j - 1][1] && !canfly[j - 1][2]) {
                ++cango[i][0];
                --j;
            }
            j = i + 2;
            while(canfly[j][1] && !canfly[j - 1][2]) {
                ++cango[i][1];
                ++j;
            }
        }
        
        for (int i = 0; i <= n; ++i) ans += cango[i][0] * cango[i][1];

        cout << ans - 1 << endl;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}