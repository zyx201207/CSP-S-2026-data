#include <bits/stdc++.h>
using namespace std;
long long n, cnt = 0, ans;
string s;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        long long  m;
        char c;
        cin >> m >> c;
        for(long long i = 1; i <= m; i++) {
            s += c;
        }
    }
    long long len = s.size();
    //cout << len << endl;
    for(int i = 0; i < len / 2; i++) {
        //cout << s[i] << " " << s[len - i - 1] << endl;
        if(s[i] != s[len - i - 1]) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
