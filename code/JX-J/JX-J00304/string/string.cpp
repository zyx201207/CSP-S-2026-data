#include <bits/stdc++.h>
using namespace std;

vector<pair<int, char>> s(1, {-1, -1});
int n;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    long long l = 1, r = 0;
    long long len = 0;
    for (int i = 1; i <= n; i++) {
        int a;
        char c;
        cin >> a >> c;
        r += a;
        len += a;
        s.push_back({a, c});
    }
    long long ans = 0;
    long long yqc = 0;
    int i = 1;
    int j = n;
    while (l <= r) {
        if (i > j) {
            break;
        }
        int x = s[i].first;
        if (yqc + x > len / 2) {
            x = len / 2 - yqc;
        }
        if (x == 0) {
            i++;
            continue;
        }
        yqc += x;
        cerr << "qu chu " << x << " ge yuan su zuo wei ben lun cao zuo\n";
        l += x;
        int y = 0;
        while (x > 0) {
            cerr << "zuo bian sheng yu " << x << " ge yuan su\n";
            if (l > r) {
                break;
            }
            int t = s[j].first;
            int num = min(x, t);
            if (t == 0) {
                j--;
            }
            cerr << "dang qian you bian qu chu " << num << " ge yuan su\n";
            s[j].first -= num;
            r -= num;
            x -= num;
            y += num;
            int temp = num * (s[i].second != s[j].second);
            ans += temp;
            cerr << "dang qian gong xian " << temp << " ge yuan su\n";
            cerr << "liang ge fen bie shi " << s[i].second << " he " << s[j].second << "\n";
            cerr << "liang ge fen bie shi " << i << " he " << j << "\n";
        }
        i++;
        if (y == s[j].second) j--;
    }
    cout << ans << endl;
    return 0;
}
