#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct h{
    ll sum;
    ll lon;
}a[200010];

ll f(ll n){
    ll ans=0;
    while(n>0){
        if(n%2) ans++;
        n/=2;
    }
    return ans;
}

bool cmp(h x,h y){
    if(x.lon==y.lon) return x.sum>y.sum;
    return x.lon>y.lon;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int z;
        cin>>z;
        a[i].sum=z;
        a[i].lon=f(z);
    }
    sort(a,a+n,cmp);
    ll ans=a[0].sum;
    for(int i=1;i<m;i++){
        ans=ans&a[i].sum;
    }
    cout<<ans;
    return 0;
}
