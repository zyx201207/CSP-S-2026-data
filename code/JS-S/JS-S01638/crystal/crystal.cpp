#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 5e5 + 7;
int n, m, ans, cnt, diff, a[N], sum[N];
bool flag = true, flag1 = true;
bool check(int x){
    int sum = 0, l = 1;
    for(int i = 1; i <= x; i++){
        sum += a[i];
    }
    if(x * x - sum == 0) return false;
    for(int i = 1; i <= x; i++){
        if(sum > x) sum -= x;
        if(sum == a[x]) return false;
    }
    return true;
}
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(a[i] != i) flag = false;
        if(i > 2){
            if(a[i] - a[i - 1] != diff) flag1 = false;
        }else if(i == 2){
            diff = a[i] - a[i - 1];
        }
    }
    if(flag){
        for(int i = n; i >= 1; i--){
            if(i * (i - 1) == 2 * m){
                cout << i << '\n';
                return 0;
            }
        }
    }
    if(flag1){
        int i = 1;
        while(ans + i * diff <= m){
            ans += i * diff;
            i++;
        }
        cout << i << '\n';
        return 0;
    }
    sort(a + 1, a + n + 1);
    if(n <= 5000){
        for(int i = 1; i <= n; i++){
            sum[i] = sum[i - 1] + a[i];
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                if((i - j + 1) * a[i] - sum[i] + sum[j - 1] <= m){
                    ans = max(ans, i - j + 1);
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
    int lft = 1, rgt = n;
    while(lft <= rgt){
        int mid = (lft + rgt) >> 1;
        if(check(mid)){
            lft = mid + 1;
        }else{
            rgt = mid;
        }
    }
    cout << lft / 2 << '\n';
    return 0;
}