//six seven six seven , six seven six seven , six seven six seven , six seven six seven , six seven six seven , sun xiao chuan , jian gun mu .
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[500005],m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	bool flaga=1,flagb=1;
	ll ansa=0,ansb=0;
	cin>>n>>m;
	ll am=m,bm=m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flaga=0;
		else{
			if(am>i-1){
				ansa+=i-1;
				am-=i-1;
			} 
		}
		if(i!=1&&i!=2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) flagb=0;
		else{
			if(bm>(i-1)*(a[i]-a[i-1])){
				ansb+=(i-1)*(a[i]-a[i-1]);
				bm-=(i-1)*(a[i]-a[i-1]);
			}	
		}
	}
	if(flaga){
		cout<<ansa;
		return 0;
	}else if(flagb){
		cout<<ansb;
		return 0;
	}
	sort(a+1,a+1+n);
	ll ans=0ll;
	for(int i=n;i>=1;i--){
		ll lim=m;
		ll lians=1ll;
		ll lix=a[i];
		for(int j=i-1;j>=1;j--){
			lim-=(lix-a[j]);
			if(lim>=0) lians++;
			else break;
		}
		ans=max(ans,lians);
	}
	cout<<ans;
	return 0;
}
