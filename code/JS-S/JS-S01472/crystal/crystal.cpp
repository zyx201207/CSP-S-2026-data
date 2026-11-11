#include <bits/stdc++.h> //100pts
#define int long long
#define L(i, a, b) for(int i = a;i <= b;i ++ ) 
using namespace std;
const int N = 5e5 + 15;
int a[N], sum[N];
int ans = 1;
int n, m;
bool check(int x, int y){
    int res = sum[y] - sum[x - 1], num = y - x + 1;
    return (num * a[y + 1] - res <= m);
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    L(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    L(i, 1, n) sum[i] = sum[i - 1] + a[i];
    L(i, 2, n){
        int l = 1, r = i - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(check(mid, i - 1)) {
                ans = max(ans, i - mid + 1);
                r = mid - 1;
            }
            else l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}