#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005], n, ll, rr, ans = 0, cnt = 0;
char c[200005];
string s;
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string .out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
        for (int j = 1; j <= a[i]; j++){
            s[++cnt] = c[i];
        }
    }
    int l = 1, r = cnt;
    while (l < r){
        if (s[l] != s[r]){
            ans++;
        }
        l++;
        r--;
    }
    cout << ans;
    return 0;
}
