#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
int n, a[maxn], pos;
long long ans;
char ch[maxn];
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> ch[i];
    }
    pos = n;
    for(int i = 1; i <= pos; i++) {
        while(a[i])
            if(a[i] > a[pos]) {
                if(ch[i] != ch[pos]) ans += 1ll * a[pos];
                a[i] -= a[pos], pos--;
            }
            else {
                if(ch[i] != ch[pos]) ans += 1ll * a[i];
                a[pos] -= a[i];
                break;
            }
    }
    cout << ans;
    return 0;
}
