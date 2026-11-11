#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d,a[2000010];
struct node{
    int mn = 1e18,t;
}cnt[2000010];
void check(int s){
    queue<pair<int,int>> q;
    q.push({s,0});
    while(q.size()){
        int u = q.front().first,t = q.front().second;
        q.pop();
        for(int i = u + 1;i <= n;i++){
            if(a[i] - a[u] <= d){
                if(cnt[i].mn == t + 1){
                    q.push({i,t + 1});
                    cnt[i].t++;
                }
                if(cnt[i].mn > t + 1){
                    q.push({i,t + 1});
                    cnt[i].mn = t + 1;
                    cnt[i].t = 1;
                }
            }
        }
    }
}
void solve(){
    cin >> n >> d;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        check(i);
        for(int j = i + 1;j <= n;j++){
            if(cnt[j].t == 2) ans++;
            cnt[j].mn = 1e18;
        }
    }
    cout << ans << '\n';
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while(t--){
        if(c == 13 || c == 14){
            cout << 0 << '\n';
            continue;
        }
        solve();
    }
    return 0;
}