#include<bits/stdc++.h>
using namespace std;
#define il inline
#define cst const
#define csti const int
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,l,r) for(int i=(l);i>=(r);--i)
#define rep1(i,l,r) for(int i=(l);i<(r);++i)
#define ll long long
#define mkp make_pair
#define pii pair<int,int>
#define eb emplace_back

#define int long long
#define LOL

#ifdef LOL
csti inf=0x3f3f3f3f3f3f3f3f;
#else
csti inf=0x3f3f3f3f;
#endif // LOL
il int abs_(csti x){
    return x>0?x:-x;
}
csti N=1e6+7,mod=1;

int n,m,a[N];
__int128 sum[N];

signed main(){
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    rep(i,1,n){
        cin>>a[i];
    }sort(a+1,a+n+1);
    rep(i,1,n){
        sum[i]=sum[i-1]+a[i];
    }
    __int128 val=0;
    int ans=1;
    rep(i,1,n){
        //cout<<i<<" "<<l<<" "<<r<<" "<<val<<"\n";
        int l=1,r=i,ansx=0;
        while(l<=r){
            csti mid=l+r>>1;
            cst __int128 v=(__int128)1*(i-mid+1)*a[i]-(sum[i]-sum[mid-1]);
           // cout<<mid<<" "<<(__int128)1*(i-mid+1)*a[i]<<" "<<(sum[i]-sum[mid-1])<<"\n";
            if(v<=m){
                r=mid-1,ansx=mid;
            }else{
                l=mid+1;
            }
        }
        ans=max(ans,i-ansx+1);
     //   cout<<i<<" "<<a[i]<<"  "<<l<<" "<<r<<" "<<ansx<<'\n';
    }
    cout<<ans;
    return 0;
}
