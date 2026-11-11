#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N = 5e5 + 10;
ll n, m, a[N];
int cnt[N], p[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i){
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++ i){
        // i th game
        vector<ll> v;
        ll start = i;
        for (int j = start; j <= n; ++ j){
            for (int k = 0; k < v.size(); ++ k){
                if (v[k] == a[j]){
                    v.erase(v.begin() + k, v.end());
                }
            }
            v.push_back(a[j]);
        }
        memset(p, 0, sizeof(p));
        for (int j = 0; j < v.size(); ++ j){
            p[v[j]] = 1;
        }
        for (int j = 0; j < v.size(); ++ j){
            if (p[v[j]]) cnt[v[j]] ++;
        }
    }
    for (int i = 1; i <= m; ++ i)
        cout << cnt[i] << " ";
    return 0;
}
//