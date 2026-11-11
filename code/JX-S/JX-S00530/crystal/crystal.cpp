#include<bits/stdc++.h>
using namespace std;

const int N = 500005;
long long n, m;
long long a[N], b[N];
int ans;

int main () {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            b[j] = a[i] - a[j] + b[j - 1];
            // b[i][j] = a[i] - a[j] + b[i][j - 1];
        }
        if(b[i] <= m && i >= ans) ans = i;
        // if(b[i][i] <= m && i >= ans) ans = i;
    }
    cout << ans << endl;

    return 0;
}
