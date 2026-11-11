#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll m;
    cin>>n>>m;
    vector<ll> a(n);
    for(ll& i:a) cin>>i;
    sort(a.begin(),a.end());

    int res=1;
    int l=0;
    for(int r=1;r<n;++r) {
        m-=(a[r]-a[r-1])*(r-l);
        while(m<0) m+=a[r]-a[l++];
        res=max(res,r-l+1);
    }
    cout<<res<<'\n';
}