#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 5e5 + 10;
int n, l, r, ans;
ll a[N], sum, m;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    l = 1, r = 1, sum = a[1], ans = 1;
    for(int i = 2;i <= n;i ++) {
        r ++;
        sum += a[i];
        while(m < a[r] * (r - l + 1) - sum) {
            sum -= a[l], l ++;
            if(l == r) {
                break;
            }
        }
        ans = max(ans, r - l + 1);
    }
    printf("%d", ans);
    return 0;
}
