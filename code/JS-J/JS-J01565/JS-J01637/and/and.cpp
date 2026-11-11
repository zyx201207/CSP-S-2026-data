#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[200005];
bool cmp(ll x,ll y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1,cmp);
    ll p;
    for(ll i=1;i<m;i++){
        p=a[i]&a[i+1];
    }
    cout<<p;
    return 0;
}
