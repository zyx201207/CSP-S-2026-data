#include <bits/stdc++.h>
using namespace std;
int n, m, a[200010];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int max1 = -1;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1 + i; j <= n; j ++) {
            int b = a[i] & a[j];
            if (max1 < b) max1 = b;
        }
    }
    cout << max1;
    return 0;
}
