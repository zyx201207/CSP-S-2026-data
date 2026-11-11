#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m;
ll a[N];
int Cnt(int k){
    ll x=a[k];
    int j=k;
    ll cnt=0;
    while(j>=1){
        ll cost=x-a[j];
        if(cnt+cost>m)return k-j;
        cnt+=cost;
        j--;
    }
    return k;
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
    bool f=1;
    for(int i=2;i<=n-1;i++){
        if(a[i]-a[i-1]!=a[i+1]-a[i])f=0;
    }
    if(f){
        ll k=a[2]-a[1];
        ll x=1;
        while(x<=n){
            ll sum=(x+1)*x*k/2;
            if(sum>m)break;
            x++;
        }
        cout<<min(x,n);
        return 0;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,Cnt(i));
    }
    cout<<ans;
    return 0;
}
