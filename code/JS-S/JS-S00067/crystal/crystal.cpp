#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],sum[N];

ll erfen(ll rr){
    ll l=1,r=rr;
    ll res;
    int cnt=0;
    while(l<=r){
        if(cnt==2) break;
        if(l==r) cnt++;
        ll mid=(r+l)/2;
        if(sum[rr]-sum[mid-1]-(mid-1)*(a[rr]-a[mid-1])<=m){
            res=mid;
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    bool flag=1;
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+(a[i]-a[i-1])*(i-1);
        if(sum[i]>m) flag=0;
    }
    if(flag){
        cout<<n;
        return 0;
    }
    ll ans=1;
    for(int i=1;i<=n;i++){
        ll r=i;
        ll l=erfen(i);
        ll temp=r-l+1;
        ans=max(ans,temp);
    }

    cout<<ans;
    return 0;
}
