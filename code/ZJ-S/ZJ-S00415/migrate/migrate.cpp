#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool vis[10];
int step[10], a[10], res;
int bfs(int s, int e, int n, int d){
    queue<int> q;
    q.push(s);
    vis[s] = true;
    memset(vis, 0, sizeof vis);
    memset(step, 0, sizeof step);
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(int i = t + 1; i <= n; i++){
            if(a[i] - a[t] <= d && !vis[i])
                q.push(i), vis[i] = true, step[i] = step[t] + 1;
        }
    }
    int ans = step[e];
    memset(vis, 0, sizeof vis);
    memset(step, 0, sizeof step);
    return ans;
}
void dfs(int f, int t, int e, int r, int n, int d){
    if(t == e){
        if(f == r)
            res++;
        return;
    }
    vis[t] = true;
    for(int i = t + 1; i <= n; i++){
        if(a[i] - a[t] <= d && !vis[i]){
            if(!vis[i])
                dfs(f, i, e, r + 1, n, d);
        }
    }
    vis[t] = false;
}
bool check(int s, int e, int n, int d){
    res = 0;
    dfs(bfs(s, e, n, d), s, e, 0, n, d);
    return res == 2;
}
void solve(){
    int n, d, ans = 0;
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (check(i, j, n, d))
                ans++;
    cout << ans << "\n";
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--)
        solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}