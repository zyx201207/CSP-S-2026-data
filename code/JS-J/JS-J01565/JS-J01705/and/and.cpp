#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;

int n, m, ans = 2147483647;
int a[200010];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);

    for(int i = n; i > n - m; i--) {
        ans = ans & a[i];
    }
    cout << ans;
    return 0;
}
