#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;
int n, m, ans;
int arr[N];
bool b[N];
int cnt[35];

void zh(int x) {
    for (int i = 30; i >= 0; -- i) {
        int t = (1 << i);
        if ((t & x)) cnt[i] ++;
    }
    return;
}
void mnt(int x) {
    for (int i = 30; i >= 0; -- i) {
        int t = (1 << i);
        if ((t & x)) cnt[i] --;
    }
    return;
}

signed main () {
    ios :: sync_with_stdio (0); cin.tie(0); cout.tie(0);
    freopen ("and.in", "r", stdin);
    freopen ("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) {
        cin >> arr[i];
        zh(arr[i]);
    }
    for (int i = 1; i <= n; ++ i) {
        b[i] = 1;
    }



    for (int i = 30; i >= 0; -- i) {
        /*
            cerr << i << ':';
        for (int i = 3; i >= 0; -- i) {
            cerr << cnt[i] << ' ';
        }
        cerr << '\n';
        */


        if (cnt[i] >= m) {
            for (int j = 1; j <= n; ++ j) {
                if (b[j] == 0 || (arr[j] & (1 << i))) {
                    continue;
                }
                else {
                    b[j] = 0;
                    mnt(arr[j]);
                }
            }
            ans += (1 << i);
 //           cerr << (1 << i) << ' ';
        }
    }
    cout << ans;
//    cerr << "\n";
//    cerr << ans;
    return 0;
}
