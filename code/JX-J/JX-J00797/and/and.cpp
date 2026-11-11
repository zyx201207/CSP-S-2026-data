#include <iostream>
#include <cmath>
using namespace std;
int n, m, a[2000], mn = 0, ns[2000];
int f(int c, int s) {
    for (int i = s; i < n - 1; i++) {
        for (int j = m - 1; j >= 0; j++) {
            if (ns[i] < m - 2) {
                ns[i]++;
                break;
            }
        }
        mn = max(mn, r);
    }
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    f(m);

    cout << mn;
    return 0;
}
