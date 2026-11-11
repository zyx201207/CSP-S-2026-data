#include<bits/stdc++.h>
using namespace std;
int n, m, a[200005], maxn, vis[200005];
void dfs(int dep, int ans){
    if(dep == m){
        maxn = max(maxn, ans);
        return;
    }
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            vis[i] = 1;
            cout << ans << " " << a[i] << (ans & a[i]) << endl;
            dfs(dep + 1, ans & a[i]);
            vis[i] = 0;
        }
    }
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(n <= 20){
        for(int i = 1; i <= n; i++){
            vis[i] = 1;
            dfs(1, a[i]);
            vis[i] = 0;
        }
        cout << maxn;
    }
    else{
        if(m == 1){
            for(int i = 1; i <= n; i++){
                maxn = max(maxn, a[i]);
                cout << maxn;
            }
        }
        if(m == n){
           maxn = a[1];
            for(int i = 2; i <= n; i++){
                maxn &= a[i];
            }
            cout << maxn;
        }
        if (m == 2){
            for(int i = 1; i <= n; i++){
                for(int j = i + 1; j <= n; j++){
                    maxn = max(maxn, (a[i] & a[j]));
               }
            }
            cout << maxn;
        }

    }
    return 0;
}
