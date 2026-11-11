#include  <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+10;
ll a[N],d[N],sum[N],xy[N];
ll n,m,ans;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++)  {
            d[i]=a[i]-a[i-1];
            xy[i]=xy[i-1]+d[i];
            sum[i]=sum[i-1]+d[i]*(i-1);
    }
    for(int i=2;i<=n;i++){
        ll l=1,r=i,len=0;
        while(l<=r){

            ll mid=(l+r)>>1;
            if(sum[i]-sum[mid]-((mid-1)*(xy[i]-xy[mid]))<=m){
                r=mid-1;
                len=(i-mid+1);
            }else{
                l=mid+1;
            }
        }

        ans=max(ans,len);
    }

    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
