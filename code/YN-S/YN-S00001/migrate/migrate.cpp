// [8,16]
#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N = 2e6 + 5;
int n,d,x[N],cnt;
void dfs(int now,int jump,int ed){
    if(jump == 0){
        if(now == ed) cnt++;
        return;
    }
    for(int i = now + 1;i <= ed;i++){
        if(x[i] - x[now] <= d) dfs(i,jump - 1,ed);
        else break;
    }
}
bool check(int l,int r){
    int t = (x[r] - x[l] + d - 1) / d;
    cnt = 0;
    dfs(l,t,r);
    return cnt == 2;
}
int tid;
void solve(){
    cin >> n >> d;
    for(int i = 1;i <= n;i++) cin >> x[i];
    if(tid == 11 || tid == 12){
        int dis = x[2] - x[1];
        // cout << n << " " << d << " " << dis << " ";
        if(dis >= d) cout << 0 << "\n";
        else{
            int t = d / dis;
            cout << max(0LL,n - t * 2 + 1) << "\n";
        }
        return;
    }
    int ans = 0;
    for(int i = 1;i < n;i++){
        for(int j = i + 1;j <= n;j++){
            if(check(i,j)) ans++;
        }
    }
    cout << ans << "\n";
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1; cin >> tid >> T;
    while(T--) solve();
    return 0;
}