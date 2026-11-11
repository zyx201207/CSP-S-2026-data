#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005;
ll n,m;
ll a[MAXN];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        ll ans=0;
        for(ll i=1;i<(1<<n);i++){
            ll sum=(1<<n)-1,cnt=0;
            for(ll j=0;j<n;j++){
                if(i&(1<<j)){
                    cnt++;
                    sum&=a[j+1];
                    if(cnt==m) break;
                }
            }
            if(cnt==m){
                ans=max(ans,sum);
            }
        }
        cout<<ans;
    }else{
        if(n<=2000){
            if(m==1){
                ll maxv=0;
                for(int i=1;i<=n;i++){
                    maxv=max(maxv,a[i]);
                }cout<<maxv;
            }
            if(m==2){
                ll ans=0;
                for(int i=1;i<n;i++){
                    ll sum=a[i];
                    for(int j=i+1;j<=n;j++){
                        ans=max(ans,sum&a[j]);
                    }
                }cout<<ans;
            }
            if(m==n){
                ll ans=a[1];
                for(int i=2;i<=n;i++)
                    ans&=a[i];
                cout<<ans;
            }
        }
    }
    
    return 0;
}
//g++ and.cpp -o and -std=c++14 -O2