#include <bits/stdc++.h>
using namespace std;
int a[200005], n, m;
int ans = 0;
void dfs(int depth, int cnt, int s){
    if(depth > n){
        if(cnt == m) ans = max(ans, s);
        return;
    }
    if(cnt < m) dfs(depth+1, cnt+1, (s&a[depth+1]));
    dfs(depth+1, cnt, s);
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    int ma = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        ma = max(ma, a[i]);
    }
    if(m == 1 || n > 2000){
        cout << ma;
        return 0;
    }
    else if(m == 2){
        for(int i =1; i <= n; i++){
            for(int j =i+1; j <= n; j++){
                ans = max(a[i]&a[j], ans);
            }
        }
        cout << ans;
        return 0;
    }
    dfs(0, 0, -1);
    cout << ans;
    return 0;
}
