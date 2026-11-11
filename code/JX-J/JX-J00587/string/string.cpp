#include <bits/stdc++.h>
using namespace std;

bool hui(string s) {
    string s1 = s;
    reverse(s.begin(), s.end());
    if (s1 == s) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n;
    cin >> n;
    string s;
    while (n--) {
        int a;
        cin >> a;
        char c;
        cin >> c;
        for (int i = 0; i < a; i++) {
            s += c;
        }
    }

    if (hui(s) == true) {
        cout << 0 << "\n";
        return 0;
    }

    int ans = 0;
    int l = s.size();
    string s1 = s;
    reverse(s.begin(), s.end());
    for (int i = 0; i < l; i++) {
        if (s1[i] != s[i]) {
            s1[i] = s[i];
            ans++;
        }
        if (hui(s1) == true) {
            cout << ans << "\n";
            return 0;
        }
    }


    return 0;
}
