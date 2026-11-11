#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,j,k) for(ll i=j;i<=k;i++)
ll n,m;
ll a[200005][35];
ll b[200005];
ll add(ll j,ll i){
    ll p=0;
    while(j){
        if(j%2) a[i][p]=1;
        p++;
        j/=2;
    }
    return 0;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    f(i,1,n){
        ll j;
        cin>>j;
        add(j,i);
    }
    ll op=0;
    for(ll i=32;i>=0;i--){
            ll ans=0;
        f(j,1,n){
            if(b[j]==0) ans+=a[j][i];
        }
        if(ans<m) continue;
        op+=(1<<i);
        f(j,1,n) if(a[j][i]==0) b[j]=1;
    }
    cout<<op;
    return 0;
}

