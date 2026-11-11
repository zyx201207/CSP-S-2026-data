#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<long long> pref(n + 1, 0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    int max_count = 0;
    for (int j = 0; j < n; j++) {
        long long cost = (long long)j * a[j] - pref[j + 1];
        if (cost <= m) {
            max_count = max(max_count, j + 1);
        }
    }
    cout << max_count << endl;
    return 0;
}
