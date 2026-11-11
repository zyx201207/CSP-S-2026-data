#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=500000+10;
ll n,m,tmax=-0x3f3f3f3f,temp;
ll a[N],cnt;
bool check(ll mid){
    ll cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]<mid){
            cnt+=mid-a[i];
        }
    }
    if(cnt<=m){
        return true;
    }
    return false;
}
ll binary_answer(ll l,ll r){
    ll ans=0;
    while(l<=r){
        ll mid=l+(r-l)/2;
        if(check(a[mid])){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    return ans;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    temp=binary_answer(1,n);
    ll i=temp;
    while(i!=0&&m!=0){
        if(a[i]<=a[temp]){
            m-=a[temp]-a[i];
            cnt++;
        }
        i--;
    }
    cout<<cnt;
    return 0;
}

