#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 5;
long long n, m, ans;
bool f = 1;
int a[N];
void dfs(long long pos, long long cnt, long long last){
    ans = max(ans, cnt);
    if(pos > n){
        return;
    }
    if(last - cnt * (a[pos] - a[pos - 1]) >= 0){
        dfs(pos + 1, cnt + 1, last - cnt * (a[pos] - a[pos - 1]));
    }else{
        dfs(pos, cnt - 1, last + a[pos - 1] - a[pos - cnt]);
    }
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d %d", &n, &m);
    for(int i = 1;i <= n;i ++){
        scanf("%d", &a[i]);
    }
    for(int i = 1;i <= n;i ++){
        if(a[i] != i){
            f = 0;
            break;
        }
    }
    if(f){
        int k = 1;
        while(ans + k <= m){
            ans += k;
            k ++;
        }
        printf("%d", k);
        return 0;
    }
    sort(a + 1, a + n + 1);
    dfs(1, 0, m);
    printf("%d", ans);
    return 0;
}
