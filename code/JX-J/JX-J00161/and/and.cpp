#include<bits/stdc++.h>
using namespace std;
long long n, m, ans = -1;
long long a[200010];
bool vis[200010];
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (m == 1) {
        for (int i = 1; i <= n; i++) {
            ans = max(ans, a[i]);
        }
        cout << ans;
        return 0;
    }
    if (m == n) {
        ans = a[1];
        for (int i = 1; i <= n; i++) {
            ans &= a[i];
        }
        cout << ans;
        return 0;
    }
    if (m == 2) {
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                if (i != k)
                    ans = max(a[k] & a[i], ans);
            }
        }
        cout << ans;
        return 0;
    }
    if (n <= 2000) {
        long long sum = 0;
        for (int k = 1; k <= n; k++) {
            sum = a[k];
            for (int i = 1; i <= n; i++) vis[i] = 0;
            vis[k] = 1;
            for (int i = 2; i <= m; i++) {
                long long Tmp = sum;
                long long tmp = sum;
                sum = 0;
                int pos;
                for (int j = 1; j <= n; j++) {
                    if (vis[j]) continue;
                    tmp &= a[j];
                    if (tmp > sum) pos = j;
                    sum = max(sum, tmp);
                    tmp = Tmp;
                }
                //cout << sum << " ";
                vis[pos] = 1;
            }
            //cout << '\n';
            ans = max(sum, ans);
        }
        cout << ans;
        return 0;
    }
    bool flag1 = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] != i - 1) flag1 = 0;
    }
    if (flag1) {
        int k = log2(n);
        if (m <= k) {
            cout << n - 1;
        } else {
            ans = n - 1;
            m -= k;
            for (int i = n; i >= 1 && m > 0; i--) {
                int Lg = log2(a[i] + 1);
                int pw = pow(2, Lg);
                if (pw == a[i] + 1) continue;
                ans &= a[i];
                m--;
            }
            cout << ans;
        }
        return 0;
    }
    sort(a + 1, a + 1 + n);
    ans = a[n];
    for (int i = n; i > n - m; i--) {
        ans &= a[i];
    }
    cout << ans;
    return 0;
}
// /ll wei shen me wo bu hui xie zhe ti TWT
// zhi hui bu fen fen le
// 20 + 20 + 5 + 10 = 55 -> zhe ti de fen shu
// m = n - 1 de zen me xie /kel -> 10pts
// wo bu hui /ll
// xian xing zuo fa shi sha
// dp chao shi ei
// yellow -> green?
