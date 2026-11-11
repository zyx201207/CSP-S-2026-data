#include <bits/stdc++.h>
using namespace std;

string s1, s2, s3, s4;
int ans1, ans2, ans3, ans4;

inline int check(string s) {
    if (s.length() == 3 && s[2] > 'C') {
        return 1;
    }
    return 0;
}

inline bool f(string z1, string z2) {
    int t1 = check(z1), t2 = check(z2);
    if (t1 == t2 && abs(z1[2] - z2[2]) == 1) {
        return true;
    }
    return false;
}

signed main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s1 >> s2 >> s3 >> s4;
    if (s1 == s3) {
        ans1 = 1;
        if (s2[0] == s4[0] && s2[1] == s4[1]) {
            ans2 = 1;
            int c2 = check(s2), c4 = check(s4);
            if (c2 == c4) {
                ans3 = 1;
                if (f(s2, s4)) {
                    ans4 = 1;
                }
            }
        }
    }
    cout << ans1 << ans2 << ans3 << ans4;
    return 0;
}
