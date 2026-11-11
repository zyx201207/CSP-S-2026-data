#include<bits/stdc++.h>
using namespace std;
struct str {
    int num;
    bool ejz[32], f[32];
} a[200005];
int n, m, p = 1, p2[32], cnt[32], ans;
void get_ans(int ws) {
    int c = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i].f[ws - 1] == 1 && a[i].ejz[ws] == 1) {
            c++;
        }
    }
    if (c < m) {
        for (int i = 1; i <= n; i++) {
            if (a[i].f[ws - 1] == 1) {
                a[i].f[ws] = 1;
            }
        }
    }
    else {
        cnt[ws] = c;
        for (int i = 1; i <= n; i++) {
            if (a[i].f[ws - 1] == 1 && a[i].ejz[ws] == 1) {
                a[i].f[ws] = 1;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    for (int i = 31; i > 0; i--) {
        p2[i] = p;
        p *= 2;
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].num;
        a[i].f[0] = 1;
        int num = a[i].num;
        for (int j = 1; j < 32; j++) {
            if (num >= p2[j]) {
                a[i].ejz[j] = 1;
                num -= p2[j];
            }
        }
    }

    /*for (int i = 1; i <= n; i++) {
        for (int j = 1; j < 32; j++) {
            cout << a[i].ejz[j];
        }
        cout << "\n";
    }*/

    for (int i = 1; i < 32; i++) {
        get_ans(i);
    }

    /*for (int i = 1; i < 32; i++) {
        cout << cnt[i] << " ";
    }
    cout << "\n";*/

    for (int i = 31; i > 0; i--) {
        if (cnt[i] >= m) {
            bool f = 0;
            for (int j = 1; j <= n; j++) {
                if (a[j].f[i] == 1) {
                    if (f == 0) {
                        f = 1;
                        ans = a[j].num;
                    }
                    else {
                        ans &= a[j].num;
                    }
                }
            }
            break;
        }
    }
    cout << ans;
    return 0;
}
