#include <bits/stdc++.h>
using namespace std;
typedef int re;typedef long long ll;
ll n,m,sw[200005][32],a[200005];
bool cmp(ll a,ll b){
    return a > b;
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (re i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + n + 1,cmp);
    for (re i = 1;i <= n;i++) for (re j = 30;j >= 0;j--) sw[i][j] = (a[i] & (1 << j));
    if (m == 1){
        cout << a[1];
        return 0;
    }
    if (m == n){
        ll res = a[1];
        for (re i = 2;i <= n;i++) res = res & a[i];
        cout << res;
        return 0;
    }
    vector <re> k;
    bool kp = true;
    for (re i = 30;i >= 0;i--){
        ll cnt = 0;
        if (kp){
            for (re j = 1;j <= n;j++){
                if (sw[j][i] != 0){
                    cnt++;
                    k.push_back(j);
                }
            }
        }
        else{
            vector <re> kf;
            for (re j = 0;j < k.size();j++){
                if (sw[k[j]][i] != 0){
                    cnt++;
                    kf.push_back(k[j]);
                }
            }
            if (cnt == m) k = kf;
            else if (cnt > m) k = kf;
        }
        if (cnt == m){
            ll res = a[k[0]];
            for (re l = 1;l < m;l++) res = res & a[k[l]];
            cout << res;
            return 0;
        }
        else if (kp && cnt < m) k.clear();
        else if (cnt > m) kp = false;
    }
    ll ans = a[k[0]];
    for (re i = 1;i < m;i++) ans = (ans & a[k[i]]);
    cout << ans;
    return 0;
}
