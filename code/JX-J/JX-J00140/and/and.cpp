#include <bits/stdc++.h>
#define debug(a) //a
using namespace std;
const int N = 2e5 + 5;
int n, m;
long long a[N];
long long maxn = 0;
long long search(int l, int i = 0, long long la = 0xffffffffff) {
    if (l == 1) {
        maxn = max(maxn, a[i]&la);
        debug(cout << maxn << endl;)
        return maxn;
    }
    for (int j = i + 1 ; j <= n-l ; j++) {
        search(l-1, j, la&a[i]);
    }
    return maxn;
}
int main() {
    ifstream cin("and.in");
    ofstream cout("and.out");
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++) {
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    if (m == 1) {
        cout << maxn;return 0;
    }
    maxn = 0;
    sort(a, a+n-1);
    for (int i = 0 ; i <= n-m ; i++) search(m, i);
    cout << maxn;
    return 0;
}
