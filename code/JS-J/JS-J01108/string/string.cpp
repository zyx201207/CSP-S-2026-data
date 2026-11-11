#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    long long sum = 0;
    string s = "";
    while (n--) {
        int a;
        char c;
        cin >> a >> c;
        while (a--) {
            s += c;
        }
    }
    long long ans = 0;
    for (int i = 0; i <= (s.size() - 1) / 2; i++) {
        if (s[i] != s[s.size() - 1 - i]) ans++;
    }
    cout << ans << endl;
    return 0;
}
