#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010],b[500010],sum=0;
bool q=1,r=1;
ll maxc(ll x){
    ll w=m,ans=1;
    for(ll i=x-1;i>=1;i--){
        if(a[i]+w>=a[x]){
            ans++;
            w-=a[x]-a[i];
        }else break;
    }
    return ans;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]!=i) q=0;
    }
    for(ll i=1;i<n;i++){
        b[i]=a[i+1]-a[i];
    }
    for(ll i=2;i<n;i++){
        if(b[i]!=b[i-1]){
            r=0;
            break;
        }
    }
    if(q){
        for(ll i=1;i<=n;i++){
            m-=i;
            if(m<0){
                sum=i;
                break;
            }
        }
        cout<<sum;
        return 0;
    }
    sort(a+1,a+1+n);
/*    for(ll i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }*/
    if(r){
        ll y=a[2]-a[1];
        for(ll i=1;i<=n;i++){
            m-=y*i;
            if(m<0){
                sum=i;
                break;
            }
        }
        cout<<sum;
        return 0;
    }
    for(ll i=n;i>=1;i--){
        sum=max(sum,maxc(i));
    }
    cout<<sum;
    return 0;
}
