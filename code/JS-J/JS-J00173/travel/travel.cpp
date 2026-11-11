#include <bits/stdc++.h>
using namespace std;

string c, s, cc, ss;
int ans[10];

int main () {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> c >> s >> cc >> ss, ans[1] = ans[2] = ans[3] = ans[4] = 0;
    if (c == cc) {
        ans[1] = 1;
        string pos = "", pospos = "";
        pos += s[0], pos += s[1], pospos += ss[0], pospos += ss[1];
        if (pos == pospos) {
            ans[2] = 1;
            if ((s[2] <= 'C' && ss[2] <= 'C') || (s[2] > 'C' && ss[2] > 'C')) {
                ans[3] = 1;
                if ((s[2] > 'C' && ss[2] > 'C') || (abs((int)(s[2] - ss[2])) == 1))
                    ans[4] = 1;
            }
        }
    }
    cout << ans[1] << ans[2] << ans[3] << ans[4] << '\n';
    return 0;
}
