#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e6+10;
ll n,a[N],m,ans;
ll ca;
bool check(ll x){
    ll cnt=0;
    //ca=0;
    for(int i=1;i<=n;i++){
        if(a[i]<=x){
            cnt+=(x-a[i]);
            ca++;
        }
        if(cnt>m){
            return 0;
        }
    }
    //cout<<cnt<<endl;
    return cnt<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    ll l=-1e10,r=1e10;
    while(l<=r){
        //cout<<1<<endl;
        ll mid=(l+r)/2;
        if(check(mid)){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]<=r)
            ans++;
    }
    cout<<ans;
    return 0;
}
