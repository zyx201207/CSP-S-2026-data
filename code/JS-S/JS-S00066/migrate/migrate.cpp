#include <bits/stdc++.h>
#define int long long
using namespace std;
int x[2000010];
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c, t;
    cin >> c >> t;
    cout << t << endl;
    while(t--){
        int n, d;
        cin >> n >> d;
        for(int i = 1; i <= n; i++)cin >> x[i];
        int m = x[2] - x[1];
        int q = (d / m) * 2 - 1;
        int s = n - q;
        if(s > 0)cout << s << endl;
        else cout << 0 << endl;
    }
    return 0;
}
