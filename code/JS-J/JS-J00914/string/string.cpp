#include<bits/stdc++.h>
#define FILENAME "string"
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    int tmp = -1;
    char lst = '$';
    deque<pair<int, char> > s;
    for (int i = 0; i < n; i++) {
        int a;
        char b;
        cin >> a >> b;
        if (b == lst) tmp += a;
        else {
            if (tmp != -1 && lst != '$') s.push_back({ tmp, lst });
            tmp = a;
            lst = b;
        }
    }
    s.push_back({ tmp, lst });
    int ans = 0;
    while(!s.empty()) {
        if (s.size() == 1) break;
        auto a = s.front(), b = s.back();
        s.pop_front();s.pop_back();
        if (a.second == b.second) {
            if (a.first < b.first) {
                b.first -= a.first;
                s.push_back(b);
            }
            else if (a.first > b.first) {
                a.first -= b.first;
                s.push_front(a);
            }
        }
        else {
            if (a.first == b.first) {
                ans += a.first;
            }
            else if (a.first < b.first) {
                ans += a.first;
                b.first -= a.first;
                s.push_back(b);
            }
            else if (a.first > b.first) {
                ans += b.first;
                a.first -= b.first;
                s.push_front(a);
            }
        }
    }
    cout << ans;
}

signed main() {
    freopen(FILENAME ".in", "r", stdin);
    freopen(FILENAME ".out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t = 1;
    //cin >> t;
    while(t--) solve();

    return 0;
}