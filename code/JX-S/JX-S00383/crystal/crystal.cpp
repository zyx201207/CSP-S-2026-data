#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll s=0,ans=1,f=0;
    for(ll i=1;i<n;i++) s+=a[n]-a[i];
    if(s<=m){
        cout<<n;
        return 0;
    }
    for(ll i=1;i<=n;i++){
        if(a[i]!=i){
            f=1;
            break;
        }
    }
    if(f==0){
        for(ll i=1;;i++){
            if(m-i>=0){
                m-=i;
                ans++;
            }
            else break;
        }
        cout<<ans;
        return 0;
    }
    ll f1=0,c=a[2]-a[1];
    for(ll i=3;i<=n;i++){
        if(a[i]-a[i-1]!=c){
            f1=1;
            break;
        }
    }
    if(f1==0){
        for(ll i=c;;i+=c){
            if(m-i>=0){
                m-=i;
                ans++;
            }
            else break;
        }
        cout<<ans;
        return 0;
    }
    for(ll i=2;i<=n;i++){
        ll sum=0,x=0;
        for(ll j=1;j<=i;j++){
            if(sum+abs(a[j]-a[i])<=m){
                sum+=abs(a[j]-a[i]);
                x++;
            }
            else break;
        }
        ans=max(ans,x);
    }
    cout<<ans;
    return 0;
}
