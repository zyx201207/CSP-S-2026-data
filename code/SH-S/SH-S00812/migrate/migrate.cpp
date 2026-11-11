#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e6+9;
ll C,T,n,d,x[N],ans;
int rrc[N],lrc[N],crc[N],clc[N],rrl[N],lrl[N],nrr[N],nlr[N];
ll sv(ll lt,ll rt){
	if(rt-lt<=2)return 0;
	bool ta=1;ll tb=0,rs=0;
	for(ll i=lt+1;i<rt&&ta;i++)
		if(x[lt+1]-x[lt]!=x[i+1]-x[i])ta=0;
	for(ll i=lt;i<rt&&!tb;i++)
		if(x[i]-x[lt]<=d&&x[rt]-x[i]<=d)tb=i;
	if(ta){
		ll dd=d/(x[lt+1]-x[lt]);
		if(dd<2)return 0;
		return max(0ll,rt-2*dd+2-lt);
	}
	for(ll i=lt;i<=rt;i++)clc[i]=crc[i]=0;
	for(ll i=lt,j=lt+1;i<=rt;i++){
		while(j<rt&&x[j+1]-x[i]<=d)j++;
		rrc[i]=j;crc[j]++;nlr[j]=i;
	}
	for(ll i=rt,j=rt-1;i>=lt;i--){
		while(j>lt&&x[i]-x[j-1]<=d)j--;
		lrc[i]=j;clc[j]++;nrr[j]=i;
	}
	if(tb){
		for(ll i=lt;i<tb;i++){
			ll j=rrc[i];
			if(j-1>tb)break;
			if(j==tb)rs+=clc[tb-1];
			else rs+=clc[tb];
		}
		return rs;
	}
	rrl[rt]=lrl[lt]=0;
	for(ll i=rt-1;i>=lt;i--){
		if(lrc[rrc[i]]!=i)rrl[i]=clc[i];
		else rrl[i]=clc[i]+rrl[rrc[i]];
	}
	for(ll i=lt+1;i<=rt;i++){
		if(rrc[lrc[i]]!=i)lrl[i]=crc[i];
		else lrl[i]=crc[i]+lrl[lrc[i]];
	}
	rrl[lt]--,lrl[rt]--;
	for(ll i=lt+1;i<rt-1;i++){
		if(lrc[i+1]>=i||rrc[i]<=i+1||
			rrc[i-1]>=nrr[i]||lrc[i+2]<=nlr[i+1])continue;
		rs+=crc[i+1]*clc[i];//4d
		rs+=rrl[rrc[i]]*crc[i+1]+lrl[lrc[i+1]]*clc[i];
		rs+=rrl[rrc[i]]*lrl[lrc[i+1]];
	}
	return rs;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);cout.tie(0);
	cin>>C>>T;while(T--){
		cin>>n>>d;ans=0;
		for(ll i=1;i<=n;i++)cin>>x[i];
		for(ll lt=1,rt=1;lt<=n&&rt<=n;rt++)
			if(rt==n||x[rt+1]-x[rt]>d)
				ans+=sv(lt,rt),lt=rt+1;
		cout<<ans<<"\n";
	}
	return 0;
}/*:9
0 1
10 3
0 3 6 7 8 9 10 11 14 17
//-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
*/
