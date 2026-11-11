#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
#define ll long long
int nsid, t, mn, cnt;
ll n, d, x[N], ans;
void dfs(int now, int e, int step){
    if(now == e){
        if(step < mn)mn = step, cnt = 1;
        else if(step == mn)cnt++;
    }
    for(int i = now + 1; i <= e; i++){
        if(x[now] < x[i] - d)return;
        dfs(i, e, step + 1);
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> nsid >> t;
    if(nsid <= 6){
        while(t--){
            cin >> n >> d;
            ans = 0;
            for(int i = 1; i <= n; i++)cin >> x[i];
            for(int i = 1; i <= n; i++){
                for(int j = i + 1; j <= n; j++){
                    if(x[i] >= x[j] - d)continue;
                    cnt = 1, mn = N, dfs(i, j, 0);
                    if(cnt == 2)ans++;
                }
            }
            cout << ans << "\n";
        }
        return 0;
    }
    while(t--){
        cin >> n >> d;
        for(int i = 1; i <= n; i++)cin >> x[i];
        ll dis = x[2] - x[1], k = d / dis;
        if(k != 2){
            cout << 0 << "\n";
            continue;
        }
        if(n % 2 == 0){
            cout << (n - 4) * ((n - 4) / 2 + 1) / 2 + (n - 4) / 2 + 1 << "\n";
        }else{
            cout << ((n - 4) / 2 + 1) * ((n - 4) / 2 + 2) << "\n";
        }
    }
}
