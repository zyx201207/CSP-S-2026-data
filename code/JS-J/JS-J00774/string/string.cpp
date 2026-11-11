#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    vector<pair<char, int>> v, v1, v2;
    int n, sum = 0, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        int a;
        cin >> a >> c;
        sum += a;
        v.push_back({c, a});
    }
    int i = 0, j = 0;
    bool b = false;
    while (true) {
        if (j == sum / 2) {
            break;
        }
        else if (j + v[i].second > sum / 2) {
            v1.push_back({v[i].first, sum / 2 - j});
            v[i].second -= sum / 2 - j;
            j = sum / 2;
            b = true;
            break;
        }
        else {
            j += v[i].second;
            v1.push_back(v[i++]);
        }
    }
    if (b) v2.push_back(v[i++]);
    while (i < n) v2.push_back(v[i++]);
    reverse(v2.begin(), v2.end());
    i = j = 0;
    if (sum % 2 != 0) {
        if (v2[0].second > 1) v2.back().second--;
        else v2.pop_back();
    }
    while (i < v1.size() && j < v2.size()) {
        int& s1 = v1[i].second, &s2 = v2[j].second;
        if (v1[i].first != v2[j].first) {
            if (s1 > s2) {
                s1 -= s2;
                ans += s2;
                j++;
            }
            else if (s1 < s2) {
                s2 -= s1;
                ans += s1;
                i++;
            }
            else {
                i++, j++;
                ans += s1;
            }
        }
        else {
            if (s1 > s2) {
                s1 -= s2;
                j++;
            }
            else if (s1 < s2) {
                s2 -= s1;
                i++;
            }
            else {
                i++, j++;
            }
        }
    }
    cout << ans;
    return 0;
}