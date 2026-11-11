#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m;
ll a[500005],sum[500005];
int ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=0,r=i-1,now=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(m-mid*a[i]+sum[i-1]-sum[i-1-mid]>=0ll) l=mid+1,now=mid;
            else r=mid-1;
        }
        ans=max(ans,now+1);
    }
    cout<<ans;
    return 0;
}
//Oct31==Dec25?
/*I want to in the JS qirendashang qwq!!!can dalao put me in the JSqirendashang?
15:57 tiaowan T1. chaochuyuliao
then i go to t2's baoli,but i failed.
then i goto t3's baoli,at 17:10,i finished t3's baoli.(get 40+-rand)
then i goto t2's baoli .at 18:10 ,i still don't finish my t2's baoli.
end

might AFO soon

where should i stay ?i asked myself.


from limoxuan0712 uid1432277*/
