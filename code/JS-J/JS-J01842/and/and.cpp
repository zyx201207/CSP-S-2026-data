#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a[200005], ans = -1e18, mx, s;
void dfs(int p, ll cnt, ll sum){
    if(cnt > m) return ;
    if(p == n + 1){
        if(cnt == m){
            ans = max(ans, sum);
        }
        return ;
    }
    if(cnt == 0){
        dfs(p + 1, cnt + 1, a[p]);
    }else{
        dfs(p + 1, cnt + 1, (sum & a[p]));
    }
    dfs(p + 1, cnt, sum);
}
bool check(ll x){
    while(x > 1){
        if(x % 2) return false;
        x /= 2;
    }
    return true;
}
bool f;
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(!check(a[i] + 1)) f = 1;
        mx = max(mx, a[i]);
        if(s == 0) s = a[i];
        else s = (s & a[i]);
    }
    if(n <= 20){
        dfs(1, 0, 0);
        cout << ans;
    }else{
        if(m == 1){
            cout << mx;
        }else if(m == n){
            cout << s;
        }else if(m == 2){
            ll MX = -1e18;
            for(int i = 1; i <= n; i++){
                for(int j = i + 1; j <= n; j++){
                    MX = max(MX, (a[i] & a[j]));
                }
            }
            cout << MX;
        }else if(m == n - 1){
            ll ans1, ans2;
            ans1 = ans2 = 0;
            for(int i = 1; i <= n - 1; i++){
                if(ans1 == 0) ans1 = a[i];
                else ans1 = (ans1 & a[i]);
            }
            for(int i = 2; i <= n; i++){
                if(ans2 == 0) ans2 = a[i];
                else ans2 = (ans2 & a[i]);
            }
            cout << max(ans1, ans2);
        }else if(!f){
            sort(a + 1, a + n + 1, greater<ll>());
            ll S = 0;
            for(int i = 1; i <= m; i++){
                if(S == 0) S = a[i];
                else S = (S & a[i]);
            }
            cout << S;
        }else{
            dfs(1, 0, 0);
            cout << ans;
        }
    }
    return 0;
}
