#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
int n;
ll m;
ll a[N],s[N];
bool cmp(ll x,ll y){
    return x>y;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1,cmp);
    ll l=-2000000000000,r=2000000000000;
    ll ans=1;
    while(l<r){
        ll mid=(l+r+1)/2;
        ll record=0,mm=m;
        bool flag=1;
        for(int i=1;i<=n;i++){
            if(a[i]<=mid){
                if(mm>=(ll)(mid-a[i])){
                    mm=mm-(mid-a[i]);
                    record++;
                }
                else{
                    flag=0;
                    break;
                }
            }
        }
        if(flag){
            ans=max(ans,record);
            l=mid;
        }
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
