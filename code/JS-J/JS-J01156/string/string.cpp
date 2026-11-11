#include <bits/stdc++.h>

using namespace std;

struct el {
    int n;
    char c;
};

el str[200000];
int n;
long long ans = 0;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        el l;
        cin >> l.n >> l.c;
        str[i] = l;
    }
    int l_i = 0, r_i = n - 1, l_p = str[0].n, r_p = str[n -1].n;
    while (l_i - r_i != 1) {
        if (l_p > r_p) {
            if (str[l_i].c != str[r_i].c) {
                ans += r_p;
            }
            --r_i;
            l_p -= r_p;
            r_p = str[r_i].n;
        }  else if (l_p == r_p) {
            if (str[l_i].c != str[r_i].c) {
                ans += r_p;
            }
            ++l_i;
            --r_i;
            l_p = str[l_i].n;
            r_p = str[r_i].n;
        } else {
            if (str[l_i].c != str[r_i].c) {
                ans += l_p;
            }
            ++l_i;
            r_p -= l_p;
            l_p = str[l_i].n;
        }
    }

    cout << ans;

    return 0;
}
