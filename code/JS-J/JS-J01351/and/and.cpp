#include <bits/stdc++.h>
using namespace std;

const long long N = 2e5 + 10;
long long a[N];
long long and_solve(long long x, long long y) {
    string s, s2, s3;
    while(x != 0) {
        s += x % 2 + '0';
        x /= 2;
    }
    while(y != 0) {
        s2 += y % 2 + '0';
        y /= 2;
    }

    long long maxn = max(s.size(), s2.size());
    if(s.size() < s2.size()) {
        for(long long i = 1; i <= 1 + s2.size() - s.size(); i++) {
            s += '0';
        }
    }else if(s.size() > s2.size()) {
        for(long long i = 1; i <= 1 + s.size() - s2.size(); i++) {
            s2 += '0';
        }
    }
    //cout << s << endl << s2 << endl;
    for(long long i = 0; i < s.size() / 2; i++) {
        long long t = s[i];
        s[i] = s[s.size() - i - 1];
        s[s.size() - i - 1] = t;
    }
    for(long long i = 0; i < s2.size() / 2; i++) {
        long long t2 = s2[i];
        s2[i] = s2[s2.size() - i - 1];
        s2[s2.size() - i - 1] = t2;
    }

    for(long long i = 0; i < maxn; i++) {
        if(s[i] == s2[i] && s[i] == '1') {
            s3 += '1';
        }else {
            s3 += '0';
        }
    }
    //cout << s3 << endl;
    long long ans = 0;
    for(long long i = s3.size() - 1; i >= 0; i--) {
        ans += (s3[i] - '0') * pow(2, s3.size() - i - 1);
    }
    return ans;
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    for(long long i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if(m == 1) {
        sort(a + 1, a + n + 1);
        cout << a[n] << endl;
        return 0;
    }else if(m == n) {
        long long ans = and_solve(a[1], a[2]);
        for(long long i = 3; i <= n; i++) {
            ans = and_solve(ans, a[i]);
        }
        cout << ans << endl;
    }else if(m == 2) {
        long long ans;
        for(long long i = 1; i <= n; i++) {
            for(long long j = i + 1; j <= n; j++) {
                ans = max(ans, and_solve(a[i], a[j]));
            }
        }
        cout << ans << endl;
    }
    return 0;
}
