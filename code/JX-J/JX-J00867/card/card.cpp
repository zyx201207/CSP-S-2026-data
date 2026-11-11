#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
deque<int> q;
int n, m, num, a[N], ans[N];
bool vis[N];
void solve(){
    cin >> n >> m;
    for(int i = 1;i <= n;++i) cin >> a[i];
    for(int i = 1;i <= n;++i){
        memset(vis, 0, sizeof(vis));
        while(!q.empty()) q.pop_front();
        for(int j = i;j <= n;++j){
            bool ok = 1;
            for(auto it = q.begin();it != q.end();++it){
                if(*it == a[j]){
                    q.erase(it, q.end());
                    break;
                }
            }
            q.push_back(a[j]);
        }
        for(auto it = q.begin();it != q.end();++it){
            if(!vis[*it]) ++ans[*it], vis[*it] = 1;
        }
    }
    for(int i = 1;i <= m;++i) printf("%d ", ans[i]);
}

signed main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    solve();
    return 0;
}
