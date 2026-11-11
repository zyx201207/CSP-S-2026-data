#include <bits/stdc++.h>
using namespace std;
const int N = 2*1e6;
long long d, x[N], ans;
int c, t, n;
int ldfind3(){
    int sum = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            if (x[i]-x[j] == d*2-1 && i-j == d*2-1){//find:ld
                sum++;
            }

    return sum;
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while (t--){
        cin >> n >> d;
        ans = 0;
        memset(x, 0, sizeof(x));
        for (int i = 1; i <= n; i++)
            cin >> x[i];
        ans += ldfind3();
        if (n == 1 || n == 2 || n == 3){
            cout << 0 << endl;
            continue;
        }
        cout << ans << endl;
    }
    return 0;
}
