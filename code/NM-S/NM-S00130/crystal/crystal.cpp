#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m,ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    vector<ll> a(n,0);
    vector<ll> res(n,0);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());
    ll minn=m+1;
    for(int i=1;i<n;i++) minn=min(minn,a[i]-a[i-1]);
    if(minn>m){
        cout<<1;
        return 0;
    }
    ll rm=m,pos=n-1;
    for(int i=n-2;i>=0;i--){
        if(rm-(a[pos]-a[i])>=0){
            res[pos]++,rm-=(a[pos]-a[i]);
        }else{
            rm+=(res[pos]*(a[pos]-a[pos-1]));
            rm-=(a[pos-1]-a[i]);
            res[pos-1]=res[pos]-1;
            pos--;
            res[pos]++;
        }
    }
    for(int i=0;i<n;i++) ans=max(ans,res[i]);
    cout<<ans+1;
    return 0;
}
