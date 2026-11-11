# include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;

int n, tot, mx;
long long m, a[N], sum[N];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%d", & n, & m);
    for (int i = 1; i <= n; i ++) scanf("%lld", & a[i]);
    sort(a + 1, a + 1 + n);
    for (int i = n; i >= 1; i --) sum[i] = sum[i + 1] + (a[n] - a[i]);
    for (int i = 1; i <= n; i ++){
        int l = 1, r = i - 1, ans = 0;
        while (l <= r){
            int mid = l + r >> 1;
            if (sum[mid] - sum[i] - (i - mid) * (a[n] - a[i]) <= m){
                ans = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        mx = max(mx, i - ans + 1);
    }
    printf("%d\n", mx);
    return 0;
}
