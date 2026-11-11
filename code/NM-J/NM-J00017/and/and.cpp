#include <bits/stdc++.h>
using namespace std;
int n, m, ans = -1;
int a[200010];
int he(int x, int y){
    return x&y;
}
void dfs(int x, int y, int z){
    if(z < ans and z != 0){
        return;
    }
    if(y == m){
        ans = max(z, ans);
        return;
    }
    if(x > n){
        return;
    }
    if(y != 0){
        dfs(x+1, y+1, he(a[x], z));
    }else{
        dfs(x+1, y+1, a[x]);
    }
    dfs(x+1, y, z);
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    dfs(1, 0, 0);
    cout << ans;
    return 0;
}
