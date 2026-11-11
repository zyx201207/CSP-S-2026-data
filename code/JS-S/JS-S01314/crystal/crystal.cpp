#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
#define ll long long
const int N=5e5+10;
ll n,m,a[N],pre[N];
ll ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(ll i=1;i<n;i++){
        pre[i]=pre[i-1]+i*(a[i+1]-a[i]);
    }
    for(ll i=1;i<n;i++){
        ll l=0,r=i;
        while(l<r){
            ll mid=(l+r)/2;
            if(pre[i]-pre[mid]-(mid-1)*(a[i+1]-a[mid])<=m){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        ans=max(ans,i-l+2);
    }
    cout<<ans;
    return 0;
}
//zczxnbnbnb
