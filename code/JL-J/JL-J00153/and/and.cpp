#include <iostream>
#include <vector>
using namespace std;
vector <int> a;
int m, n, ans = -1;
void dfs(int r) {
    if (r > m) return;
    if (ans == -1) {
        int mi, mj;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i; j < n; j++) {
                if (a[i] & a[j] > ans) {
                    ans = a[i] &a[j];
                    mi = i, mj = j;
                }
            }
        }
        a.erase(a.begin() + mi);
        a.erase(a.begin() + mj);
    }
    int t = -1, mi;
    for (int i = 0; i < n; i++) {
        if (a[i] & ans > t) {
            t = a[i] & ans;
            mi = i;
        }
    }
    ans = t;
    a.erase(a.begin() + mi);
    dfs(r + 1);
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> m >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    //dfs(1);
    cout << (a[0] & a[1]);
    return 0;
    fclose(stdin);
    fclose(stdout);
}
