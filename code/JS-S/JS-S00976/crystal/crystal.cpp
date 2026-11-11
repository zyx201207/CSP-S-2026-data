#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n;
ll m;
ll a[500010],sum[500010];

ll now,now2;
bool check(ll ql,ll qr){
    now2=(qr-ql+1);
    now=(a[qr]*now2);
    now-=(sum[qr]-sum[ql-1]);
    if(now>m){
        return 0;
    }
    return 1;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    sum[0]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=(sum[i-1]+a[i]);
    }
    ll l=1,r=n,ans=1,pos,mid;
    for(int i=1;i<=n;i++){
        l=1,r=i,pos=1,mid;
        while(l<=r){
            mid=((l+r)/2);//cout<<mid<<" "<<l<<" "<<r<<endl;
            if(check(mid,i)){
                r=mid-1;
                pos=mid;
            }
            else{
                l=mid+1;
            }
        }
        ans=max(ans,(i-pos+1));
    }
    cout<<ans<<endl;
    return 0;
}
