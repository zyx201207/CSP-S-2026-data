#include<bits/stdc++.h>

using namespace std;
using ll=long long;

const ll MAXN=5*1e5+5;
vector<ll> a,pre_a;
ll n,m;

ll solve(ll id){
    ll ans=0;
    ll tar=a[id-1];
    ans=tar*(id)-pre_a[id-1];
    if(m>=ans) return id;
    return 0;
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(size_t i=0;i<n;i++){
        ll in;
        cin>>in;
        a.push_back(in);
    }
    sort(a.begin(),a.end());
    pre_a.push_back(a[0]);
    for(size_t i=1;i<n;i++){
        pre_a.push_back(pre_a[i-1]+a[i]);
    }
    for(size_t i=n;i>0;i--){
        if(solve(i)){
            cout<<solve(i)<<'\n';
            break;
            }
    }
    return 0;
}