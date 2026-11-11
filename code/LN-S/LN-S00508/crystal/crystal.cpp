#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;
int a[MAXN];
unsigned long long cnt[MAXN];
int main () {
    freopen("crystal.in" , "r" , stdin);
    freopen("crystal.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    unsigned long long m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];

    }

    sort(a + 1 , a + 1 + n);
    memset(cnt , 0 , sizeof(cnt));
    for (int i = 1; i <= n; i ++) {
        cnt[i] = cnt[i - 1] + a[i];
    }

    int left = 1 , right = n;
    int mid;
    int js = 0;
    while (left < right) {
        mid = (left + right) / 2;
        int sum = a[mid] * mid - cnt[mid];
        if (sum <= m) {
            left = mid;
        } else {
            right = mid - 1;
        }
        js ++;
        if (js > 101) break;
    }

    cout << (left + right) / 2;

    return 0;
}
