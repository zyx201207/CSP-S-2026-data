#include <iostream>
using namespace std;

const int N = 2e5 + 5;

long long n, m, tmp, cnt, ans = (1ll << 31) - 1;
long long a[N];
bool er[N][32], shi[N];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    //cout << ans;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        tmp = a[i];
        for (int j = 0; tmp != 0; j++) {
            if (tmp % 2 == 0) {
                er[i][j] = 0;
            } else {
                er[i][j] = 1;
            }
            tmp /= 2;
        }
    }

    for (int j = 31; j >= 0; j--) {
        cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (shi[i] == 0 && er[i][j] == 1) {
                cnt++;
            }
        }
        if (cnt < m) {
            continue;
        }
        if (cnt == m) {
            for (int i = 1; i <= n; i++) {
                if (er[i][j] == 0) {
                    shi[i] = 1;
                }
            }
            break;
        }
        if (cnt > m) {
            for (int i = 1; i <= n; i++) {
                if (er[i][j] == 0) {
                    shi[i] = 1;
                }
            }
        }
    }

    cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt > m) {
            break;
        }
        if (shi[i] == 0) {
            ans = ans & a[i];
            cnt++;
        }
    }
    cout << ans << endl;

    //for (int i = 1; i <= n; i++) {
    //    for (int j = 31; j >= 0; j--) {
    //        cout << er[i][j];
    //    }
    //    cout << ' ' << (int)shi[i] << endl;
    //}

    return 0;
}
