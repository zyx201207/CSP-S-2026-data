#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 1; i <= n; i++)
using namespace std;
const int N = 5e5 + 10;
int n, m;
int a[N];
int now[N];
int ans[N], last[N];
int pos;
signed main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, n){
        cin >> a[i];
    }
    if(n >= 100000){
        int cf[N] = {0};
        rep(i, n){
            cf[a[i]]++;
        }
        rep(i, m){
            cf[i] = cf[i - 1] + cf[i];
            cout << cf[i] << ' ';
        }
        return 0;
    }
    rep(i, n){
        pos = 0;
        memset(last, 0, sizeof last);
        for(int j = i; j <= n; j++){
            if(last[a[j]]){
                pos = a[j];
            }
            else{
                pos++;
                now[pos] = a[j];
                last[a[j]] = j;
            }
        }
        rep(j, pos){
            ans[now[j]]++;
        }
    }
    rep(i, m) cout << ans[i] << ' ';
    return 0;
}
