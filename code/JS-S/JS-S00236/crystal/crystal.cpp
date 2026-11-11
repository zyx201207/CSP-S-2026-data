//This keyboard is too hard to use.
#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define mid ((l + r + 1) / 2)
#define pb push_back
using namespace std;
int a[500005];
int qzh[500005];
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m, l, r, ans, mmax = 0;
    cin >> n >> m;
    a[0] = LONG_LONG_MIN;//I use 30min 2 find this bug 
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a, a + n + 1);
    for (int i = 1; i <= n; i++) {
        qzh[i] = qzh[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        l = i;
        r = n;
        //[i,mid]can generate a big crystal
        while (l < r) {
            //clog << l << " " << mid << " " << r <<" ";
            ans = (a[mid] * (mid - i + 1)) - (qzh[mid] - qzh[i - 1]);
            //clog << ans << endl;
            /*if (ans < 0) {
                clog << "ans<0!!!";
                exit(9178);
            }*/
            if (ans <= m) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        ans = a[mid] * (mid - i + 1) - (qzh[mid] - qzh[i - 1]);
        //if (mmax < (mid - i + 1)) clog << i << " " << mid << " " << mid - i + 1 << endl;
        /*if (ans > m) {
            clog << "What's Frank??\n";
            clog << i << " " << mid << " " << ans;
            exit(114514);
        }*/
        mmax = max(mmax, mid - i + 1);
    }
    cout << mmax;
    return 0;
}