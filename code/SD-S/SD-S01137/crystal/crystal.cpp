#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll ans=0;
	for(ll i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		ll l=1,r=i;
		while(l<r){
			ll mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m){
				r=mid;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}





/*




csp csp csp	 csp qwqwqwqwq

qwq qwq  


djr ak ioi
djr ak ioi
djr ak ioi
djr ak ioi
djr ak ioi
djr ak ioi
djr ak ioi
djr ak ioi
djr ak ioi
djr ak ioi
djr ak ioi
djr ak ioi
djr ak ioi
djr ak ioi
djr ak ioi
djr ak ioi
djr ak ioi
djr ak ioi




jnzs

14:45 t1

froepen

feorpen

kkksc03

chen_zhe


qqqqwqwq ak ioi
ysy ak ioi
ljz ak ioi
gjh ak ioi
slf ak ioi
xuchuhan0122 ak ioi  (luogu name)qqqqwqwq ak ioi
ysy ak ioi
ljz ak ioi
gjh ak ioi
slf ak ioi
xuchuhan0122 ak ioi  (luogu name)qqqqwqwq ak ioi
ysy ak ioi
ljz ak ioi
gjh ak ioi
slf ak ioi
xuchuhan0122 ak ioi  (luogu name)qqqqwqwq ak ioi
ysy ak ioi
ljz ak ioi
gjh ak ioi
slf ak ioi
xuchuhan0122 ak ioi  (luogu name)qqqqwqwq ak ioi
ysy ak ioi
ljz ak ioi
gjh ak ioi
slf ak ioi
xuchuhan0122 ak ioi  (luogu name)qqqqwqwq ak ioi
ysy ak ioi
ljz ak ioi
gjh ak ioi
slf ak ioi
xuchuhan0122 ak ioi  (luogu name)qqqqwqwq ak ioi
ysy ak ioi
ljz ak ioi
gjh ak ioi
slf ak ioi
xuchuhan0122 ak ioi  (luogu name)qqqqwqwq ak ioi
ysy ak ioi
ljz ak ioi
gjh ak ioi
slf ak ioi
xuchuhan0122 ak ioi  (luogu name)qqqqwqwq ak ioi
ysy ak ioi
ljz ak ioi
gjh ak ioi
slf ak ioi
xuchuhan0122 ak ioi  (luogu name)qqqqwqwq ak ioi
ysy ak ioi
ljz ak ioi
gjh ak ioi
slf ak ioi
xuchuhan0122 ak ioi  (luogu name)qqqqwqwq ak ioi
ysy ak ioi
ljz ak ioi
gjh ak ioi
slf ak ioi
xuchuhan0122 ak ioi  (luogu name)qqqqwqwq ak ioi
ysy ak ioi
ljz ak ioi
gjh ak ioi
slf ak ioi
xuchuhan0122 ak ioi  (luogu name)qqqqwqwq ak ioi
ysy ak ioi
ljz ak ioi
gjh ak ioi
slf ak ioi
xuchuhan0122 ak ioi  (luogu name)qqqqwqwq ak ioi
ysy ak ioi
ljz ak ioi
gjh ak ioi
slf ak ioi
xuchuhan0122 ak ioi  (luogu name)qqqqwqwq ak ioi
ysy ak ioi
ljz ak ioi
gjh ak ioi
slf ak ioi
xuchuhan0122 ak ioi  (luogu name)
qqqqwqwq ak ioi
ysy ak ioi
ljz ak ioi
gjh ak ioi
slf ak ioi
xuchuhan0122 ak ioi  (luogu name)
qqqqwqwq ak ioi
ysy ak ioi
ljz ak ioi
gjh ak ioi
slf ak ioi
xuchuhan0122 ak ioi  (luogu name)qqqqwqwq ak ioi
ysy ak ioi
ljz ak ioi
gjh ak ioi
slf ak ioi
xuchuhan0122 ak ioi  (luogu name)qqqqwqwq ak ioi
ysy ak ioi
ljz ak ioi
gjh ak ioi
slf ak ioi
xuchuhan0122 ak ioi  (luogu name)

#include<bits\stdc++.h>

mian



rp++



AFO

*/

