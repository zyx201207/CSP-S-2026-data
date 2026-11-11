#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5  + 5;
int n, m, ans;
int a[N];
bool check(int x){
    for(int i = x;i <= n; i++){
        int sum = 0;
        for(int j = i - x + 1;j <= i; j++){
            sum += a[j];
        }
        int p = sum / n, p1 = sum  / n + 1, p2 = sum / n - 1;
        int k1  = 0, k2 = 0, k3 = 0;
        for(int j = i - x + 1;j <= i; j++){
            k1 += abs(a[j] - p);
            k2 += abs(a[j] - p1);
            k3 += abs(a[j] - p2);
        }
        if(min(k1, min(k2,k3)) <= m)
            return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    int l = 1, r = n;
    while(l <= r){
        int mid = (l + r) / 2;
        if(check(mid)){
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans;
    return 0;
}
