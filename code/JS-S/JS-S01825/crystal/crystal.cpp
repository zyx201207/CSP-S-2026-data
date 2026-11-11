#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
ll n,m,ans=1;
vector<ll> a,b;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        ll x; cin>>x;
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    int flag=1;
    ll c=0;
    for(auto j:a){
        if(j!=++c) flag=0;
    }
    int fl=1;
    ll d=a[n-1]-a[n-2];
    for(int i=1;i<n;i++){
        if(a[i]-a[i-1]!=d) fl=0;
    }
    if(n<=5000){
        ll ori=m;
        for(ll i=n-1;i>=0;i--){
            int f=0;
            m=ori,b=a;
            for(ll j=i-1;j>=0;j--){
                if(f) continue;
                if(j==0) ans=max(ans,(i-j+1)*1LL);
                if(m>=b[i]-b[j]){
                    m-=(b[i]-b[j])*1LL;
                    b[j]=b[i];
                }else{
                    ans=max(ans,(i-j)*1LL);
                    f=1;
                }
            }
        }cout<<ans;
        return 0;
    }else if(flag){
        int f=0,i=n-1;
        for(ll j=i-1;j>=0;j--){
            if(f) continue;
            if(j==0) ans=max(ans,(i-j+1)*1LL);
            if(m>=a[i]-a[j]){
                m-=(a[i]-a[j])*1LL;
            }else{
                ans=max(ans,(i-j)*1LL);
                flag=1;
            }
        }cout<<ans;
        return 0;
    }else if(fl){
        ll cnt=1;
        for(int i=0;i<n;i++){
            if(m>=cnt*d){
                cnt++;
                m-=cnt*d;
            }
        }cout<<cnt+1;
        return 0;
    }else cout<<1;
    return 0;
}
