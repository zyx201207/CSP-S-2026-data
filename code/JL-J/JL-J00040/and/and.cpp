#include <bits/stdc++.h>
using namespace std;

int n, m;
int ans = 0;
int maxa = -1e9;

void ck(vector<int> a) {
    int ans = a[1];
    for (int i = 2; i <= m; i++) ans &= a[i];
    maxa = max(ans, maxa);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;

    int x;
    vector<int> a(n + 1);
    cin >> a[1]; x = a[1];
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        x &= a[i], maxa = max(maxa, a[i]);
    }

    if (m == n) { cout << x << '\n'; return 0; }
    if (m == 1) { cout << maxa << '\n'; return 0; }

    maxa = -1e9;
    do {
        ck(a);
    } while (next_permutation(a.begin() + 1, a.end()));

    cout << maxa << '\n';
    return 0;
}
