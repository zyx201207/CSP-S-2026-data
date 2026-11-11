#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N];
ll need[N];
ll cha[N];
ll n,m;
ll check(ll temp,ll ans1){
    ll id=temp;
    for(ll i=1;i<=id;i++){
        temp--;
        if(temp<=ans1){
            return ans1;
        }
        ll cnt=need[temp]-need[i]-need[i+1];
        if(cnt<=m){
            return temp;
        }
    }
    return ans1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    cha[1]=0;
    for(int i=2;i<=n;i++){
        cha[i]=a[i]-a[i-1];
    }
    need[1]=0;
    for(int i=2;i<=n;i++){
        need[i]=need[i-1]+((i-1)*cha[i]);
    }
    need[n+1]=0x3f3f3f3f;
    ll f=0;
    for(int i=1;i<=n+1;i++){
        if(m==need[i] && need[i+1]>need[i]){
            cout<<i;
            f=1;
            return 0;
        }
    }
    ll temp;
    ll ans1;
    for(int i=1;i<=n;i++){
        if(need[i]>m){
            ans1=i-1;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        if(need[i]>m && need[i+1]>need[i]){
            temp=i;
            break;
        }
    }
    ll ans=max(check(temp,ans1),ans1);
    cout<<ans;
    return 0;
}
