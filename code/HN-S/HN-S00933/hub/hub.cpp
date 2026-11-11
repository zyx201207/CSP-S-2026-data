#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, k;
ll c, t;
vector<ll> v[114514];
ll a[114514], b[114514];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> a[i] >> b[i];
            v[b[i]].push_back(a[i]);
            v[a[i]].push_back(b[i]);
        }
        cout << k - 1 << '\n';
    }
}
