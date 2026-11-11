#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
ll n, m, a[500005], ans[500005], lst[500005], cnt[500005];
void run(ll p){
    ll lp = cnt[p];
    if (lst[a[p]] != p){
        p = lst[a[p]];
    }
    else{
        ans[a[p]] += cnt[p];
        p++;
    }
    cnt[p] += lp;
}
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (ll i = 1; i <= n; i++){
        cin >> a[i];
        lst[a[i]] = i;
    }
    for (ll l = 1; l <= n; l++){
        cnt[l]++;
        run(l);
    }
    for (ll i = 1; i <= m; i++) cout << ans[i] << ' ';
    return 0;
}
