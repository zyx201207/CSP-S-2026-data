#include <iostream>
#include <cstring>
using namespace std;
int n, m;
int a[500050], desk[500050], r = 1, lct[300050];
int ans[500050];
void check() {
    for (int i = 1; i < r; i++) cout << desk[i] << " ";
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    //memset(lct, -0x3f, sizeof lct);
    for (int i = 1; i <= n; i++) {
        r = 1;
        memset(lct, 0, sizeof lct);
        for (int j = i; j <= n; j++) {
            if (lct[a[j]] <= 0) {
                desk[r] = a[j];
                lct[a[j]] = r++;
                //check();
            }
            else {
                r = lct[a[j]] + 1;
                for (int k = 1; k <= m; k++) if (lct[k] >= r) lct[k] = 0;
                //check();
            }
        }

        for (int j = 1; j < r; j++) {
            ans[desk[j]] += 1;
        }
    }

    for (int i = 1; i <= m; i++) cout << ans[i] << " ";
    return 0;
}
