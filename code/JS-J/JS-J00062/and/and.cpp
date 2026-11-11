#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N =2e5;
ll n=0,m=0,nm=0,k=0;
ll a[N+5];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    nm=n;
    ll ans=0;
    for(int z=30;z>=0;z--){
        k=(1ll<<z);
        ll sum=0;
        for(ll i=1;i<=nm;i++){
           if((a[i]&k)){
                sum++;
                swap(a[sum],a[i]);
           }
        }
        if(sum>=m){
            nm=sum;
            ans+=k;
        }
    }
    cout<<ans;
    return 0;
}
