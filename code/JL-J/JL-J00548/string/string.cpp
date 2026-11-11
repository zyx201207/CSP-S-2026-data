#include <bits/stdc++.h>

using namespace std;

long long n;
string s;

long long check () {
    long long ans = 0;
    long long len = s.size();
    for (long long i = 0; i < len / 2; i++) {
        if (s[i] != s[len - 1 - i]) {
            ans++;
        }
    }
    return ans;
}

int main () {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    long long a;
    char c;
    for (long long i = 1; i <= n; i++) {
        cin >> a >> c;
        for (long long j = 1; j <= a; j++) {
            s += c;
        }
    }
    cout << check();
    return 0;
}
