#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
struct h{
    ll su,ca;
}a[N];
bool cmp(h x,h y){
    if(x.ca>y.ca){
        return 1;
    }
}
bool cmp1(h x,h y){
    return x.su<y.su;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].su;
    }
    sort(a+1,a+n+1,cmp1);
    for(int i=1;i<=n;i++){
        a[i].ca=abs(a[i].su-a[i-1].su);
    }
    sort(a+1,a+n+1,cmp);
    ll ans=a[1].su;
    for(int i=2;i<=m;i++){
        ans&=a[i].su;
    }
    cout<<ans;
    return 0;
}
