#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll N = 5e5 + 5;
ll n, m;
ll a[N], s[N], ss[N], ans = 1;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        s[i] += s[i - 1] + a[i + 1] - a[i];
        ss[i] += ss[i - 1] + s[i];
        //cout << s[i] << ' ' << ss[i] << '\n';
    }
    for(ll i = 1; i <= n; i++){
        for(ll j = i; j <= n; j++){
            ll sum = 0;
            /*for(int k = i; k <= j; k++){
                sum -= s[k - 1];
            }*/
            //cout << sum << ' ' << ss[j - 1] - ss[i - 1] << '\n';
            sum += s[j - 1] * (j - i + 1) - (ss[j - 1] - ss[i - 1]);
            if(sum <= m){
                ans = max(ans, j - i + 1);
                //cout << j << '-' << i << ' ' << sum << '\n';
            }
        }
    }
    cout << ans;
    return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
