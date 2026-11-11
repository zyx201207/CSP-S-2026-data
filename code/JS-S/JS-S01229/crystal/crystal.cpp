#include <bits/stdc++.h>//14:53 ok
using namespace std;
#define endl '\n'
const int N = 5e5 + 10;
#define int long long

int n, m;
int a[N];
int ans;

int sum[N];

bool check(int x, int y){
    // cout << x << ' ' << y << ' ' <<a[y] * (y - x + 1) - (sum[y] - sum[x - 1]) << ' ' << m << endl;
    if(a[y] * (y - x + 1) - (sum[y] - sum[x - 1]) <= m) return 1;
    return 0;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    for(int i = 1; i <= n; i ++)
        sum[i] = sum[i - 1] + a[i];
    for(int i = 1; i <= n; i ++){
        int lft = 1;
        int rgt = i;
        while(lft <= rgt){
            int mid = (lft + rgt) >> 1;
            if(check(mid, i)){
                ans = max(ans, i - mid + 1);
                rgt = mid - 1;
            }else 
                lft = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}