#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[500005], dif[500005], sum[500005];
bool check(int num) {
    int p = num - 1;
    for (int i = num; i <= n; i++) {
        int j = i - num + 1;
        int need = p * dif[i] - (sum[i - 1] - sum[j - 1]);

        //cout << j << "-" << i << ":" << need << "\n";

        if (need <= m) {
            return 1;
        }
    }
    return 0;
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        dif[i] = a[i] - a[1];
        sum[i] = sum[i - 1] + dif[i];
    }

    /*for(int i = 1; i <= n; i++) {
        cout << dif[i] << " ";
    }
    cout << "\n";
    for(int i = 1; i <= n; i++) {
        cout << sum[i] << " ";
    }
    cout << "\n";*/

    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r + 1) / 2;

        //cout << "mid:" << mid << "\n";

        if (check(mid)) {
            l = mid;
        }
        else {
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}





//18:16
//I can't understand what T4 tell me.

//I always recall the past...
//Where should I stop? I ask myself.

//Time is over.
//I finish my OI life here.

