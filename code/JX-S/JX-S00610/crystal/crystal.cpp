//I am lxy_qwq(my luogu name), Maybe is my last CSP
//I think that I will die when I get the pts
//I can`t use string, tarjan and math
//I maybe will AFO. Bye.
//Thanks for my classmate of JK(Debug618, Groyhj, zenghaoran, cyrel, Snoozing, oceanfish
//Oldstreet and hyh) and my teacher of JK(dgl, shi jie di yi ke ai ying ying ying, Hevix and hzw).
//Bye.

//In addition:
//Debug618(his luogu name) love Groyhj(his luogu name)
//I think that Debug618 is zero because of his lazy;

//....
//I think we can add1 or del1
//so I waste 30min
//please input the text.......
#include <bits/stdc++.h>
using namespace std;
#define int long long
constexpr int MAXN = 1e6 + 5;
int a[MAXN];
int n, m;
int qzh[MAXN];
bool check(int i, int mid) {
    int r = i, l = mid;
    int suma = qzh[r] - qzh[l - 1];
    int sumb = a[i] * (i - mid + 1);
    return (sumb - suma) <= m;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i++) {
        qzh[i] = qzh[i - 1] + a[i];
    }
    int result = 0;
    for(int i = 1; i <= n; i++) {
        int left = 1, right = i - 1;
        int ans = 1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(check(i, mid)) {
                right = mid - 1;
                //i-mid
                ans = i - mid + 1;
            } else {
                left = mid + 1;
            }
        }
        result = max(result, ans);
    } cout << result << endl;
    return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
