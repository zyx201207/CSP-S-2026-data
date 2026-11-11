#include<bits/stdc++.h>
#define FL(a, b, c) for(int a = (b), a##end = (c); a <= a##end; ++a)
#define FR(a, b, c) for(int a = (b), a##end = (c); a >= a##end; --a)
using namespace std;
#define endl '\n'
#define int long long
constexpr int N = 5e5 + 10;
int a[N], n, ans, s[N], m;
int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m, ans = 1;
    FL(i, 1, n)cin >> a[i];
    sort(a + 1, a + 1 + n);
    FL(i, 1, n){
        s[i] = s[i - 1] + a[i];
        // cout << i << " " << ans << " " << endl;
        while(i - ans > 0){
            int l = i - ans;
            int g = (ans + 1) * a[i] - (s[i] - s[l - 1]);
            // cout << g << " " << ans << " " << i << endl;
            if(g > m)break;
            ans++;
        }
    }
    cout << ans << endl;
}