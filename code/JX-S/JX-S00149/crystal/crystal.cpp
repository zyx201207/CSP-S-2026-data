#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500005]={0};
ll a1[500005]={0};
bool cheak(ll i,ll x){
    ll num1=a1[x]-((a[x]-a[i])*(i-1)+a1[i]);
    if(num1<=m){
        return 1;
    }else{
        return 0;
    }
}
ll find1(ll x){
    ll left=0;
    ll right=x;
    ll ans=0;
    while(left<=right){
        ll mid=left+(right-left)/2;
        if(cheak(mid,x)){
            ans=mid;
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return x-ans+1;

}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;

    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    a1[1]=0;
    for(ll i=2;i<=n;i++){
        a1[i]=a1[i-1]+(a[i]-a[i-1])*(i-1);
    }
    ll cnt=0;
    for(int i=0;i<n;i++){
            ll z=find1(i);
        if(cnt<z){
            cnt=z;
        }
    }
    cout<<cnt;
    fclose(stdout);
    fclose(stdin);
    return 0;
}
