#include <bits/stdc++.h>
using namespace std;
// #pragma GCC optimize(2)
#define fast() tie(0) -> ios::sync_with_stdio(false)
typedef unsigned long long ull;
const int maxn = 500086; // A
int a[maxn];
int num[maxn];
int n;
ull m;
int ans = INT_MIN;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin.fast();
    cout.fast();
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        num[i] = INT_MAX;
    }
    sort(a, a + n);
    for(int i = n - 1; i > 0; i--) {
        int j = i, s = 0;
        for(int k = 0; k < (i + 1); k++) {
            s += a[i] - a[j];
            num[k] = min(num[k], s);
            j--;
        }
    }
    cout << (lower_bound(num, num + n, m) - num) << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}