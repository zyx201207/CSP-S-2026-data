#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll cost(ll begin,ll end,const vector<ll>& dist){
    ll n = end-begin;
    ll ptr = end-1;
    ll c = 0;
    for(ll i = n;i > 0;i--){
        c+=dist[ptr]*i;
        ptr--;
    }
    return c;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll max_use = 1;
    ll n,m;
    cin >> n >> m;
    if(n <= 1){
        cout << 1;
        return 0;
    }
    vector<ll> energy(n,0);
    for(int i = 0;i < n;i++){
        cin >> energy[i];
    }
    sort(energy.begin(),energy.end());
    vector<ll> dist(n-1,0);
    for(int i = 0; i < (n-1);i++){
        dist[i] = energy[i+1] - energy[i];
    }
    bool ok = false;
    ll i = 0;
    int jump = sqrt(n-1);
    for(i = 0;i < n-1;i+=jump){ //i is begin
        ll tp  = 0;
        for(ll j = i+1;j <n;j+=jump){
            if(cost(i,j,dist) > m){
                tp = j;
                break;
            }
            tp = j;
            max_use = max(max_use,j-i+1);
        }
        for(ll j = max(i+1,tp-jump);j < min(n,tp);j++){
            if(cost(i,j,dist) > m){
                break;
            }
            ok = true;
            max_use = max(max_use,j-i+1);
        }
        if(ok){
            break;
        }
    }
    ok = false;
    for(ll x = max((ll)0,i-jump);x<min(i,n);x++){
        for(ll j = x+1;j <n;j++){
            if(cost(x,j,dist) > m){
                break;
            }
            ok = true;
            max_use = max(max_use,x-i+1);
        }
        if(ok){
            break;
        }
    }
    cout << max_use;
    return 0;
}