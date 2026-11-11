#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int n, m, a[N];
int ans_dfs;
void dfs(int pos, int sum,int num){
    if(num > m) return ;
    if(num == m){
        ans_dfs = max(ans_dfs, sum);
        return ;
    }
    if(pos > n) return ;
    dfs(pos + 1, sum, num);
    if(num == 0){
        dfs(pos + 1, a[pos], num + 1);
    }
    else{
        dfs(pos + 1, sum & a[pos], num + 1);
    }
}
bool cmp(int a, int b){
    return a > b;
}
signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n; i ++){
        scanf("%lld", &a[i]);
    }
    if(m == 1){
        int maxa = 0;
        for(int i = 1; i <= n; i ++){
            maxa = max(maxa, a[i]);
        }
        printf("%lld\n", maxa);
        return 0;
    }
    if(m == n){
        int mx = a[1];
        for(int i = 2; i <= n; i ++){
            mx = (mx & a[i]);
        }
        printf("%lld\n", mx);
        return 0;
    }
    if(n <= 20){
        dfs(1, 0, 0);
        printf("%lld\n", ans_dfs);
        return 0;
    }
    if(n <= 2000 && m == 2){
        int mx = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = i + 1; j <= n; j ++){
                mx = max(mx, 1LL * (a[i] & a[j]));
            }
        }
        printf("%lld\n", mx);
        return 0;
    }
    sort(a + 1, a + n + 1, cmp);
    printf("%lld\n", a[m]);
    return 0;
}