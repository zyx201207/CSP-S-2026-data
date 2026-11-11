#include <iostream>
#define ll long long
using namespace std;
ll n, m, a[(int)5e5+10], b[(int)3e3+10][(int)1e3+10];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int r = 1; r <= n; r++) {
        for (int i = r-1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i] == b[r][j]) {
                    for (int k = j+1; k <= n; k++) b[r][k] = 0;
                    break;
                }
                if (b[r][j] == 0) {
                    b[r][j] = a[i];
                    break;
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        int count = 0;
        for (int r = 1; r <= n; r++) {
            for (int j = 0; j < n; j++) {
                if (b[r][j] == i) {
                    count++;
                    break;
                }
            }
        }
        cout << count << ' ';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
