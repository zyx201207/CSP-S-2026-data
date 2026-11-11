#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],s[500005];
ll sum(ll l,ll r){
    return s[r]-s[l-1];
}
bool check(int x){
    for(int i=x;i<=n;i++){
        ll cur=sum(i-x+1,i),rqr=x*a[i];
        if(cur+m>=rqr) return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    ll left=1,right=n,mid,ans;
    while(left<=right){
        mid=(left+right)/2;
        if(check(mid)){
            left=mid+1;
            ans=mid;
        }
        else{
            right=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
