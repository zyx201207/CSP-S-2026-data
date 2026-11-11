#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n, m, ans = -1;
int a[N], s[N];
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(long long i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i - 1] & a[i];
    }
    sort(a + 1, a + 1 + n);
    cout << a[m] << "\n";
    return 0;
}