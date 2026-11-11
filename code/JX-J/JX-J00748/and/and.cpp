#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
long long n, m, a[N];
bool vis[N];
long long ans;

void dfs(int x, int y){
    if(y == m){
        long long and_sum = -1;
        for(int i = 1; i <= n; i++){
            if(vis[i]){
                if(and_sum == -1) and_sum = a[i];
                else and_sum &= a[i];
            }
        }
        ans = max(ans, and_sum);
        return ;
    }
    if(n - x + 1 < m - y) return ;
    vis[x] = 1;
    dfs(x + 1, y + 1);
    vis[x] = 0;
    dfs(x + 1, y);
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i = 1; i <= n; i++){
        scanf("%lld",&a[i]);
    }
    if(n <= 20){
        dfs(1,0);
        cout << ans;
    }
    else if(n <= 2000){
        if(m == n){
            long long and_sum = a[1];
            for(int i = 2; i <= n; i++){
                and_sum &= a[i];
            }
            cout << and_sum;
        }
        else if(m == 1){
            for(int i = 1; i <= n; i++){
                ans = max(ans, a[i]);
            }
            cout << ans;
        }
        else{
            for(int i = 1; i <= n; i++){
                for(int j = i + 1; j <= n; j++){
                    ans = max(ans, a[i] & a[j]);
                }
            }
            cout << ans;
        }
    }
    else{
        dfs(1,0);
        cout << ans;
    }
    return 0;
}
