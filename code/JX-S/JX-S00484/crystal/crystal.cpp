#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> j;
int n;ll m;ll res;ll ans=0;
bool check(ll h){
     ll cnt = 0;
     res = 0;
     for(int i=0;i<h;i++){
        int ks = j[h] - j[i];
        cnt += ks;if(cnt<=m)res += 1;
        if(cnt>m)return false;
     }
     if(cnt == m)return true;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        ll k;cin >> k;j.push_back(k);
    }
    sort(j.begin(),j.end());
    int h = j.size()-1;
    while(h--){
        ll stard = j[h];
        if(check(h)){
           ans = max(res,ans);
        }
        if(h==1)break;
    }
    cout << ans+1;
    return 0;
}
