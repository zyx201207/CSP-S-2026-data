#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+10;
int n,m;
ll a[maxn],ans;
ll s[maxn],suml[maxn],sum[maxn];
void solve1(){
    for(int i=1;i<=n;i++){
        s[i]=a[i]-a[i-1];
    }
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+s[i];
        suml[i]=suml[i-1]+s[i]*i;
    }
    ll val=0;
    for(int i=2;i<=n;i++){
        for(int j=i;j<=n;j++){
            val=suml[j]-suml[i-1]-(i-1)*(sum[j]-sum[i-1]);
            if(val<=m){
                ans=max(ans,(ll)(j-i+1+1));
            }
        }
    }
    cout<<ans;
}
void solve2(){
    for(ll i=1;i<=n;i++){
        if((1+i-1)*(i-1)/2<=m)ans=i;
    }
    cout<<ans;
}
void solve3(){
    ll x=a[2]-a[1];
    for(ll i=1;i<=n;i++){
        if((1+i-1)*(i-1)/2*x<=m)ans=i;
    }
    cout<<ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int flag=1,flagl=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i)flag=0;
        if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2])flagl=0;
    }
    sort(a+1,a+n+1);
    if(n==1){
        cout<<1;
        return 0;
    }
    if(n<=1e4){
        solve1();
        return 0;
    }
    if(flag){
        solve2();
        return 0;
    }
    if(flagl){
        solve3();
        return 0;
    }
    return 0;
}
