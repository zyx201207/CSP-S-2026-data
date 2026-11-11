#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m,ans=0;
vector<ll> a;
vector<ll> f(500005,0);

ll sum(ll r){
    return (r-1)*(a[r-1]-a[r-2])+f[r-1];
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        ll x;
        cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    for(ll i=2;i<=n;i++){
        f[i]=sum(i);
    }
    int l=1;
    for(ll i=1;i<=n;i++){
        ll x;
        if(l==1){
            x=f[i];
        }
        else{
            x=f[i]-f[l]-(l-1)*(a[i-1]-a[l-1]);
        }
        if(x<=m){
            ans=max(i-l+1,ans);
        }
        else{
            l++;
            i--;
            if(l>n) break;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
