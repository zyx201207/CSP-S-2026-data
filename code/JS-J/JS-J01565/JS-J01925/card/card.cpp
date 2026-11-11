#include <bits/stdc++.h>

using namespace std;
int n, m;
int arr[50005];
int ans[30005];
void print() {
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << " ";
    }
    return;
}
void solve(int jump) {
    map <int, int> t;
    map <int, int> f;
    for (int i = jump - 1; i < n; i++) {
        t[arr[i]] ++;
        if (t[arr[i]] > 1) {
            for (int j = f[arr[i]] + 1; j < i; j++) {
                t[arr[j]] = 0;
            }
        }
        t[arr[i]] = 1;
        f[arr[i]] = i;
    }
    for (int i = 1; i <= m; i++) {
        if (t[i] == 1) ans[i]++;
    }
    return;
}
int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        solve(i);
    }
    print();
    return 0;
}
