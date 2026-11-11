#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll num[5000005];
ll pre[5000005];
ll n,m;
bool cmp(int x,int y){
    return x<y;
}
bool check(ll x){
    for(ll i=x;i<=n;i++){
        if(num[i]*x-pre[i]+pre[i-x]<=m){
            return true;
        }
    }
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++){
        cin>>num[i];
    }
    sort(num+1,num+n+1,cmp);
    for(ll i=1;i<=n;i++){
        pre[i]=pre[i-1]+num[i];
    }
    ll l=1,r=n;
    while(l<r){
        ll mid=(l+r+1)/2;
        //cout<<l<<' '<<mid<<' '<<r<<endl;
        if(check(mid)){
            l=mid;
        }
        else{
            r=mid-1;
        }
    }
    cout<<r;
    return 0;
}
