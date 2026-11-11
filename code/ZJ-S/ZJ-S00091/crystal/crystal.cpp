#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 5e5+5;
LL n, m, a[N], p[N], ans;
LL T[N];

LL q(int x, int y) {
    return p[y] - p[x-1]; 
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        p[i] = p[i-1] + a[i];
    }
    // int start = clock();
    for(int i = 1; i <= n; i++) {
        int l = 1, r = i;
        while(l < r) {
            int mid = (l + r) >> 1;
            LL len = i - mid + 1;
            if(a[i] * len - q(mid, i) <= m) {
                r = mid - 1;
            }
            else l = mid + 1;
            // cout << l << " " << r << endl;
        }
        // int end = clock();
        // if(end - start > ) return 0;
        ans = max(LL(i - l + 1), ans);
        // cout << ans << endl;
        // for(int j = 1; j <= i; j++) {
        //     LL len = i - j + 1;
        //     if(a[i] * len - q(j, i) <= m)
        //         ans = max(ans, len);
        // }
    } // 二分
    cout << ans;
}