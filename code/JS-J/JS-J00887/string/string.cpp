#include<bits/stdc++.h>
using namespace std;
long long n, ans = 0;
string s;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        long long a;
        string c;
        cin >> a >> c;
        for (long long j = 1; j <= a; j++) {
            s += c;
        }
    }
    long long l = 0;
    long long r = s.length() - 1;
    while (l < r) {
        if (s[l] != s[r]) ans++;
        l++, r--;
    }
    cout << ans << '\n';
    return 0;
}