#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],sum[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    ll ans=1;
    for(int i=2;i<=n;i++){
        ll l=1,r=i-1,mid;
        while(l<=r){
            cout<<l<<" "<<r<<"\n";
            mid=(l+r)>>1;
            if((sum[i-1]-sum[mid-1])<=m){
                r=mid-1;
                ans=max(ans,mid);
            }
            else{
                l=mid;
            }
        }
    }
    cout<<ans;
    return 0;
}
