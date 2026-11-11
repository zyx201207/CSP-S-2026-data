#include<bits/stdc++.h>
using namespace std;
long long a[200005] , anss = -1e18 , n;
void dfs(long long ans , long long m , long long idx){
    if (m > n - idx + 1) return ;
    if (idx > n){
        if (m == 0) anss = max(anss , ans);
        return ;
    }
    if (m > 0) dfs((ans & a[idx]) , m - 1 , idx + 1);
    dfs(ans , m , idx + 1);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("and.in" , "r" , stdin);
    freopen("and.out" , "w" , stdout);
    long long m; cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    if (m == 1){
        long long mx = -1;
        for (int i = 1;i <= n;i++) mx = max(mx , a[i]);
        cout << mx;
        return 0;
    }
    if (m == n){
        long long cnt = 1LL * 1073741823;
        for (int i = 1;i <= n;i++) cnt &= a[i];
        cout << cnt;
        return 0;
    }
    if (n > 2000){
        long long num;
        bool flag = 1;
        for (int i = 1;i <= n;i++){
            num = a[i] + 1;
            while(a[i] % 2 == 0) a[i] >>= 1;
            if (a[i] != 1) flag = 0;
        }
        if (flag){
            sort(a + 1 , a + 1 + n);
            cout << a[m];
            return 0;
        }
    }
    dfs(1LL * 1073741823 , m , 1);
    cout << anss;
    return 0;
}
