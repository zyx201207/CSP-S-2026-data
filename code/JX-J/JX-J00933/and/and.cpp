#include <bits/stdc++.h>
using namespace std;
long long n , m , a[100005] , sum , b[100005] , cnt , ans;
bool flag = true;
bool vis[100005];
void dfs(int j){
    if(j > m){
        cnt = b[1];
        for(long long i = 1;i < m;i++){
            cnt = (cnt & b[i + 1]);
        }
        ans = max(ans , cnt);
        return;
    }
    for(long long i = 1;i <= n;i++){
        if(vis[a[i]] == false){
            b[j] = a[i];
            vis[a[i]] = true;
            dfs(j + 1);
            vis[a[i]] = false;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    if(m == 1){
        for(long long i = 1;i <= n;i++){
            cin >> a[i];
            ans = max(ans , a[i]);
        }
        cout << ans;
    }
    else if(m == n){
        ans = a[1];
        for(long long i = 1;i < m;i++){
            ans = (ans & b[i + 1]);
        }
        cout << ans;
    }
    else if(n >= 200005){
        for(long long i = 1;i <= n;i++){
            cin >> a[i];
        }
        sort(a + 1,a + n + 1);
        cout << a[n - m + 1];
    }
    else{
        for(long long i = 1;i <= n;i++){
            cin >> a[i];
        }
        dfs(1);
        cout << ans;
    }
    return 0;
}
