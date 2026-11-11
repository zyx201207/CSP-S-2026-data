#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxq=5e5+100;
ll n,sum,x,y,wei,ans,lpo;
ll a[maxq],s[maxq],d[maxq],k[maxq];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;cin>>n>>m;
    for(ll i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
        d[i]=a[i]-a[i-1];
    }
    sum=s[n];
    ll l=sum/m+1;
    for(ll i=1;i<=n;i++){
        x=y;
        y=abs(l-a[i]);
        if(y<x){
            sum=a[i];
            wei=i;
        }
        if(y==0)break;
    }
    for(ll i=wei;i>=1;i--){
        lpo+=d[i];
        if(lpo<=m){
            ans++;
            m-=lpo;
        }
        else{
            break;
        }
    }
    for(ll i=1;i<=n;i++)if(a[i]==sum)ans++;
    cout<<ans;
    return 0;
}
