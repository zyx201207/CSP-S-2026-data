#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll a[500007],sum[500007];
inline bool check(int l){
    ll tmp=1e18;
    for(int i=1;i<=n-l+1;i++){
        int j=i+l-1;
        ll t=a[j]*(j-i+1)-(sum[j]-sum[i-1]);
        tmp=min(tmp,t);
    }
    return tmp<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i];
    int l=1,r=n,mid,res=0;
    while(l<=r){
        mid=(l+r)/2;
        //cout<<l<<" "<<r<<"\n";
        if(check(mid))l=mid+1,res=mid;
        else r=mid-1;
    }
    cout<<res;
    return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
