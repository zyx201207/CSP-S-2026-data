#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5; 
int n, m;
int a[N];
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    long long ans = 0;
    for (int i = 2; i <= n; i++) {
        long long sum = 0, res = 1;
        for (int j = i - 1; j >= 1; j--) {
            sum += (a[i] - a[j]);
            if (sum >= m) {
                ans = max (ans, (sum == m ? res + 1 : res));
            }
            else res++;
        }
    }
    cout << ans;
    return 0;
}