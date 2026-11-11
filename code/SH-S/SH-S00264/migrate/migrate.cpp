#include<bits/stdc++.h>
using namespace std;
#define maxn 5234
typedef long long lint;
lint c, n, d, x[maxn], ind[maxn], dis[maxn], cnt[maxn], ans;
bool vst[maxn];
vector<lint> a[maxn];
void solve(){
    cin >> n >> d;
    if(n > 5000){
        cout << 0 << '\n';
        return;
    }
    ans = 0;
    for(lint i = 1; i <= n; i++){
        cin >> x[i];
        a[i].clear();
        // ind[i] = 0;
    }
    for(lint i = 1; i <= n; i++){
        for(lint j = i+1; j <= n && x[j] - x[i] <= d; j++){
            a[i].push_back(j);
            // ind[j]++;
            // cout << '{' << i << ' ' << j << '}';
        }
    }
    for(lint cur = 1; cur <= n; cur++){
        for(lint i = 1; i <= n; i++){
            dis[i] = 0x3f3f3f3f3f3f3f3f;
            cnt[i] = 0;
            vst[i] = 0;
        }
        queue<lint> q;
        // for(lint i = 1; i <= n; i++){
        //     if(ind[i] == 0){
        //         q.push_back(i);
        //         dis[i] = 0;
        //     }
        // }
        q.push(cur);
        dis[cur] = 0;
        cnt[cur] = 1;
        while(!q.empty()){
            lint ths = q.front();
            q.pop();
            // if(vst[ths]) continue;
            vst[ths] = 1;
            lint len = a[ths].size();
            // cout << ths << ' ' << len << endl;
            for(lint i = 0; i < len; i++){
                lint nxt = a[ths][i];
                // cout << ths << ' ' << nxt << "aaaaaaa" << endl;
                if(dis[ths] + 1 < dis[nxt]){
                    dis[nxt] = dis[ths] + 1;
                    cnt[nxt] = 0;
                }else if(dis[ths] + 1 == dis[nxt]){
                    cnt[nxt]++;
                    // cout << '<' << cur << ' ' << ths << ' ' << nxt << ' ' << dis[nxt] << ' ' << cnt[nxt] << '>';
                }
                if(vst[nxt]) continue;
                q.push(nxt);
            }
        }
        for(lint i = 1; i <= n; i++){
            if(cnt[i] == 2){
                ans++;
                // cout << '[' << cur << ' ' << i << ' ' << dis[i] << ']';
            }
        }
    }
    cout << ans << '\n';
}
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    lint t; cin >> c >> t; while(t--){
        solve();
    }
    return 0;
}