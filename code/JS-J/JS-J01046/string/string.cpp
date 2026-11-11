#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 1e6 + 7;
int n, ans,mul = 1;
int a[MAXN];
string c[MAXN];
string s;
signed main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        mul = __gcd(a[i], mul);
    }
    for (int i = 1; i <= n; i++) {
        a[i] /= mul;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= a[i];j++) {
            s += c[i];
        }
    }

    for (int i = 0; i <s.size()/2; i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            ans++;
        }
    }
    cout << ans * mul << endl;
    return 0;
}

/*
1 a
4 b
1 c
2 b
3 a

abbbbcbbaaa
aaabbcbbbba


*/
