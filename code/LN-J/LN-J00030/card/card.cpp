#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, m, arr[N], cnt[N];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++) {
        map<int, int> mp;
        for (int j = i; j <= n; j++) {
            mp[arr[j]]++;
            if (mp[arr[j]] > 1) {
                mp.clear();
                mp[arr[j]]++;
            }
        }
        for (int j = 1; j <= m; j++) {
            if (mp.count(j)) {
                cnt[j]++;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << cnt[i] << ' ';
    }
    return 0;
}
