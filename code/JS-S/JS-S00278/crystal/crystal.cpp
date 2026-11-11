#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll a[N],n,m;
bool check(ll x){
    ll res=2e18,us=0;
    for(int i=1;i<=x;++i){
        us+=a[x]-a[i];
    }
    res=min(res,us);
    for(int i=2;i+x-1<=n;++i){
        us-=a[i+x-2]-a[i-1];
        us+=(a[i+x-1]-a[i+x-2])*(x-1);
        res=min(us,res);
    }
    return res<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    ll l=1,r=n;
    while(l<r){
        ll mid=(r+l+1)/2;
        //cout<<l<<" "<<r<<endl;
        if(check(mid)){
            l=mid;
        }else{
            r=mid-1;
        }
        //cout<<" "<<mid<<endl;
        //if(check(5))cout<<10;
        //++l;
    }
    //if(check(315275))cout<<"11111";
    cout<<l;
    return 0;
}
