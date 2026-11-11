#include<bits/stdc++.h>
using namespace std;
long long n, m, a[200005], ans;
bool vis[200005];
void dfs(long long cnt, long long sum){
    if(cnt == m){
        ans = max(sum, ans);
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i] = 1;
            dfs(cnt+1, sum & a[i]);
            vis[i] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        vis[i] = 1;
        dfs(1, a[i]);
        vis[i] = 0;
    }
    cout << ans;
    return 0;
}
