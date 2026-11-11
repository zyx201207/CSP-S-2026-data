#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int N = 2e5+5;

vector<char> w;
ll n, a[N], L, ans;
string s;
int main() {
	freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    s += " ";
    for (int i = 1; i <= n; i++) {
        char temp;
        cin >> a[i] >> temp;
        // cout << a[i] << ' ' << temp << endl;
        for (int j = 1; j <= a[i]; j++) s += temp;
        L += a[i];
    }
    // cout << s << endl;
    // cout << L << endl;
    for (int i = 1; i <= L/2; i++) {
        if (s[i] != s[L + 1 - i]) ans++;
    }
    cout << ans << endl;
	return 0;
}
