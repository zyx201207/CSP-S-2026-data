#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define repa(i,a,b) for(int i=(a);i<(b);++i)
#define pr(x) cout<<__LINE__ << #x << x<<endl
#define P 998244353
// #define P 1000000007
#define maxn 500005
LL a[maxn],sum[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;LL m;cin>>n>>m;
    rep(i,1,n)cin>>a[i];
    sort(a+1,a+1+n);
    LL mi=a[1];
    int ans=0;
    rep(i,1,n){
        sum[i]=sum[i-1]+a[i]-mi;
        int l=0,r=i;
        while(l+1<r){
            int mid=l+r>>1;
            if((a[i]-mi)*(i-mid+1)-(sum[i]-sum[mid-1])<=m)r=mid;
            else l=mid;
        }
        ans=max(ans,i-r+1);
    }
    cout<<ans<<endl;
}