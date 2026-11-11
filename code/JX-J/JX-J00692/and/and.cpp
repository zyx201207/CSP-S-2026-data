#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n;
int m;
int a[N];
bool vis[N];
int ans;
void dfs(int k, int sum, int cnt){//now,last
    if(sum == m - 1){
        ans = max(cnt, ans);
        //cout << '\n';
        return;
    }
    for(int i = 1;i <= n;i ++){
        if(!vis[i]){
            int kkk = cnt;
            cnt &= a[i];
            vis[i] = 1;
            //cout << i << "    ";
            dfs(i, sum + 1, cnt);
            vis[i] = 0;
            cnt = kkk;
        }
    }
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i ++){
        vis[i] = 1;
        dfs(0, 0, a[i]);
        vis[i] = 0;
    }
    cout << ans << '\n';
    return 0;
}