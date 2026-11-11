#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500005];
ll f[500005];
ll sum;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    bool special_a=1;
    bool special_b=1;
    ll cz=-1,x;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
        x=a[i]-a[i-1];
        if(cz==-1){
            cz=x;
        }else if(cz!=x){
            special_b=0;
        }
        if(a[i]!=i){
            special_a=0;
        }
    }
    sort(a+1,a+1+n);
    for(ll i=1;i<=n;i++){
        f[i]=f[i-1]+a[i];
    }
    ll ans=0;
    if(special_a){
        for(ll i=n;i>=1;i--){
            sum=1LL*a[i]*(i-1)-f[i-1];
            if(sum<=m){
                ans=i;
                break;
            }
        }
    }else if(special_b){
        for(ll i=n;i>=1;i--){
            sum=1LL*a[i]*(i-1)-f[i-1];
            if(sum<=m){
                ans=i;
                break;
            }
        }
    }else if(n<=5000){
        for(ll i=n;i>=1;i--){
            for(ll j=1;j<i;j++){
                sum=1LL*a[i]*(i-j+1)-(f[i]-f[j-1]);
                if(sum<=m){
                    ans=max(ans,i-j+1);
                }
            }
        }
    }else{
        for(ll i=n;i>=1;i--){
            sum=1LL*a[i]*(i-1)-f[i-1];
            if(sum<=m){
                ans=i;
                break;
            }
        }
    }

    cout<<ans;
    return 0;
}
//orz rp++ csp-s 2= made by cici
//hope 75pts orz
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7


*/
