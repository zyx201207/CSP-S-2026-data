#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool vis[10005];
long long n, mx, m;
void DFS(int idx, long long ans){
    if(idx == m + 1){
        mx = max(mx, ans);
        return;
    }
    for(int i = 1; i <= n; i++){
        if(vis[i]){
            continue;
        }
        vis[i] = 1;
        DFS(idx + 1, ans & a[i]);
        vis[i] = 0;
    }
}
void DFS2(int idx, long long ans){
    if(idx == m + 1){
        return;
    }
    if(ans == m + 1){
        long long b = (1ll << 32);
        for(int i = 1; i <= n; i++){
            if(vis[i]){
                b &= a[i];
            }
        }
        mx = max(mx, b);
    }
    vis[idx] = 1;
    DFS(idx + 1, ans + 1);
    vis[idx] = 0;
    DFS(idx + 1, ans);
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    long long ans = (1ll << 32) - 1;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ans = ans & a[i];
    }
    if(m == n){
        cout << ans << endl;
        return 0;
    }
    if(m <= 5){
        DFS(1, (1ll << 32) - 1);

    }else{
        DFS2(1, 0);
    }
    cout << mx << endl;
    return 0;
}
