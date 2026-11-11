#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    string s="";
    long long n, a, len=0, cnt=0; string c;
    cin >> n;

    for (long long i = 0; i < n; i++) {
        cin >> a >> c;
        len += a;
        for (long long j = 0; j < a; j++) s.append(c);
    }
    for (long long i = 0; i < len/2; i++) {
        if (s[i] != s[len-1-i]) cnt++;
    }
    cout << cnt;
    return 0;
}
