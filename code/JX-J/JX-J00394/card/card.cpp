// hao xiang TLE le! shei lai jiu jiu wo a!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// No!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// CCF wo qiu qiu ni rang wo ka gua ba !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// CCF bu yao ka wo a !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// qiu qiu ni, rang hai zi wo guo ba !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;
int n, m;
int a[N], cnt[N], lst[M], sum[N];
map <int, bool> mp;
int main () {
    freopen ("card.in", "r", stdin);
    freopen ("card.out", "w", stdout);
    ios::sync_with_stdio (false);
    cin.tie (0), cout.tie (0);
    cin >> n >> m;
    bool f1 = true;
    for (int i = 1; i <= n; i++) cin >> a[i], lst[a[i]] = i;
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1];
        if (lst[a[i]] != i) ++ sum[i];
    }
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i + 1]) f1 = false;
    }
    if (n <= 5000) {
        for (int i = 1; i <= n; i++) {
            map <int, bool> mp;
            for (int j = i; j <= n; j++) {
                mp[a[j]] = true;
                j = lst[a[j]];
            }
            for (int j = 1; j <= m; j++) cnt[j] += mp[j];
        }
        for (int j = 1; j <= m; j++) cout << cnt[j] << ' ';
        cout << "\n";
        return 0;
    }
    if (f1) {
        for (int i = 1; i <= n; i++) {
            if (a[i] != a[i + 1]) {
                cnt[a[i]] += i;
            }
        }
        for (int i = 1; i <= m; i++) cout << cnt[i] << ' ';
        cout << "\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        mp.clear ();
        for (int j = i; j <= n; ) {
            int L = j, R = n, res = j;
            while (L <= R) {
                int mid = (L + R) / 2;
                if (sum[mid] - sum[j - 1] > 0) R = mid - 1, res = mid;
                else L = mid + 1;
            }
            if (!mp.count (a[j])) ++ cnt[a[j]];
            mp[a[j]] = true;
            if (lst[a[res]] != res) j = lst[a[res]];
            else ++ j;
        }
    }
    for (int j = 1; j <= m; j++) cout << cnt[j] << ' ';
    cout << "\n";
    /*
    if (n <= 5000) {
        for (int i = 1; i <= n; i++) {
            map <int, bool> mp;
            for (int j = i; j <= n; j++) {
                mp[a[j]] = true;
                j = lst[a[j]];
            }
            for (int j = 1; j <= m; j++) cnt[j] += mp[j];
        }
        for (int j = 1; j <= m; j++) cout << cnt[j] << ' ';
        cout << "\n";
        return 0;
    }
    */
    return 0;
}
