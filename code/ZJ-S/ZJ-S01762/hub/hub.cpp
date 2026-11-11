#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N = 1e6 + 10;
int n, m, ans, dis[N], vis[N], fa[N];
set<int> s;
vector<int> v[N], a;
int find(int x){
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}
void merge(int x, int y){
    x = find(x), y = find(y);
    fa[x] = y;
}
int calc(){
    int mx = 0;
    for(int i = 1; i <= n; i++) dis[i] = vis[i] = 0, fa[i] = i;
    queue<int> q;
    for(int i : a) q.push(i), vis[i] = 1;
    for(int i = 1; i <= n; i++){
        for(int j : v[i]){
            if(vis[i] && vis[j]) merge(i, j);
        }
    }
    int sum = 0;
    for(int i = 1; i <= n; i++) if(vis[i] && find(i) == i) sum++;
    if(sum > 2) return 0x3f3f3f3f;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int y : v[x]){
            if(vis[y]) continue;
            dis[y] = dis[x] + 1, vis[y] = 1, q.push(y), mx = max(mx, dis[y]);
        }
    }
    return mx;
}
void selec(int cnt){
    if(cnt > m){
        // for(int i : a) cout << i << " ";
        // cout << ans << endl;
        ans = min(calc(), ans);
        return;
    }
    int str;
    if(cnt == 1) str = 1;
    else str = a.back() + 1;
    for(int i = str; i <= n; i++){
        if(cnt + n - i < m) return;
        a.push_back(i);
        selec(cnt + 1);
        a.pop_back();
    }
    // cout << "ok" << endl;
}
void solve(){
    cin >> n >> m, ans = 0x3f3f3f3f;
    for(int i = 1, x, y; i < n; i++){
        cin >> x >> y;
        v[x].push_back(y), v[y].push_back(x);
    }
    selec(1);
    cout << ans << endl;
    for(int i = 1; i <= n; i++) v[i].clear();
}
int main(){
    // freopen("ex_hub/hub2.in", "r", stdin);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int c, T;
    cin >> c >> T;
    while(T--) solve();
    return 0;
}