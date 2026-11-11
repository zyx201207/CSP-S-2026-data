#include<bits/stdc++.h>
using namespace std;
int main () {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    vector<pair<int, char>> s(n + 1), l, r;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s[i].first >> s[i].second;
        sum += s[i].first;
    }
    long long suml = 0, sumr = 0;
    for (int i = 1; i <= n; i++) {
        if (suml == sum / 2)
            break;
        if (suml + s[i].first <= sum / 2)
            suml += s[i].first, l.push_back(s[i]);
        else
            l.push_back({sum / 2 - suml, s[i].second}), suml += sum / 2 - suml;
    }
    for (int i = n; i >= 1; i--) {
        if (sumr == sum / 2)
            break;
        if (sumr + s[i].first <= sum / 2)
            sumr += s[i].first, r.push_back(s[i]);
        else
            r.push_back({sum / 2 - sumr, s[i].second}), sumr += sum / 2 - sumr;
    }
    long long ans = 0;
    reverse(l.begin(), l.end());
    reverse(r.begin(), r.end());
    while (!(l.empty() && r.empty())) {
        if (l.back().first == r.back().first) {
            if (l.back().second != r.back().second)
                ans += l.back().first;
            l.pop_back(), r.pop_back();
        }
        else if (l.back().first > r.back().first) {
            if (l.back().second != r.back().second)
                ans += r.back().first;
            l.back().first -= r.back().first;
            r.pop_back();
        }
        else {
            if (l.back().second != r.back().second)
                ans += l.back().first;
            r.back().first -= l.back().first;
            l.pop_back();
        }
    }
    cout << ans << '\n';
    return 0;
}
