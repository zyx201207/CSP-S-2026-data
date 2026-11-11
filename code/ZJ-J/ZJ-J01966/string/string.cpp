#include <bits/stdc++.h>
using namespace std;
#define int long long
#define cout std::cout
typedef pair<int, char> str;
string a;
int n, ans, len;
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    vector<str> s(n), ns;
    for (int i = 0; i < n; i++)
        cin >> s[i].first >> s[i].second;
    for (int i = 0; i < n; i++) {
        if (ns.empty())
            ns.push_back(s[i]);
        else if (s[i].second == ns.back().second) {
            auto p = ns.back();
            ns.pop_back();
            ns.emplace_back(s[i].first + p.first, p.second);
        } else
            ns.push_back(s[i]);
    }
    vector<vector<str>> ls(ns.size());
    for (int i = 0; i < ns.size(); i++)
        ls[i].push_back(ns[i]);
    int __ = ls.size();
    for (int p = 0, p1 = 0, q = __ - 1, q1 = 0; p;) {
        if (ls[p][p1].first > ls[q][q1].first) {
            str tmp = ls[p][p1];
            vector<str> tt = ls[p], ttt;
            int _ = ls.size();
            while (_ > p1 && !ls.empty()) {
                _--;
                auto k = ls[p].back();
                ttt.push_back(k);
                ls[p].pop_back();
            }
            ls[p].pop_back();
            ls[p].emplace_back(ls[q][q1].first, tmp.second);
            ls[p].emplace_back(tmp.first - ls[q][q1].first, tmp.second);
            while (!ttt.empty())
                ls[p].push_back(ls[p].back()), ttt.pop_back();
        }
        if (ls[q][q1].first > ls[p][p1].first) {
            str tmp = ls[q][q1];
            vector<str> tt = ls[q], ttt;
            int _ = ls.size();
            while (_ > q1 && !ls.empty()) {
                auto k = ls[q].back();
                ttt.push_back(k);
                ls[q].pop_back();
                _--;
            }
            ls[q].pop_back();
            ls[q].emplace_back(ls[p][p1].first, tmp.second);
            ls[q].emplace_back(tmp.first - ls[p][p1].first, tmp.second);
            while (!ttt.empty())
                ls[q].push_back(ls[q].back()), ttt.pop_back();
        }
        if (p1 == ls[p].size() - 1)
            p++, p1 = 0;
        else
            p1++;
        if (q1 == ls[q].size() - 1)
            q++, q1 = 0;
        else
            q1++;
    }
    vector<str> ab;
    for (const auto &x : ls)
        for (const auto &y : x)
            ab.push_back(y);
    int len = ab.size();
    for (int i = 0; i * 2 < len; i++)
        if (ab[i].second != ab[len - 1 - i].second) ans += ab[i].first;
    cout << ans;
    return 0;
}