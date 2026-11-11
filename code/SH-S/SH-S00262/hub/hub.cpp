#include<bits/stdc++.h>
using namespace std;

#define ll long long

const ll maxn = 1e6 + 10;
ll c, t, n, k, d[maxn];
bool vst[maxn];
vector<ll> a[maxn];

void doo(ll p, ll k){
    if(vst[k]) return;
    vst[k] = 1;
    d[k] = d[p] + 1;
    for(vector<ll>::iterator it = a[k].begin(); it < a[k].end(); it++){
        doo(k, *it);
    }
}

int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    for(ll abcdefg = 1; abcdefg <= t; abcdefg++){
        cin >> n >> k;
        for(ll i = 1; i <= n; i++){
            a[i].push_back(0);
        }
        for(ll i = 1; i <= n - 1; i++){
            ll u, v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        for(ll i = 1; i <= n; i++){
            for(ll j = 1; j <= n; j++){
                d[j] = -1;
                vst[j] = 0;
            }
            doo(0, i);
            for(ll j = 1; j <= n; j++){
            	if(i == j) d[j] = -1;
            	else if(i == 1) d[j] -= 1;
            	else d[j] -= 3;
                cout << d[j] << ' ';
            }
            cout << endl;   
        }
    }
    return 0;
}
