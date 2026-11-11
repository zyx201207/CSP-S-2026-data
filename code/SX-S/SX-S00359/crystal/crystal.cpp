#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m;
ll a[N];
ll ans=1;
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	bool isA=true,isB=true;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i) isA=false;
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) isB=false;
	}
	sort(a+1,a+n+1);
	if(isA){
		ll i;
		for(i=n-1;i>=1;i--){
			if(m>=a[n]-a[i]){
				m-=(a[n]-a[i]);
			}else{
				break;
			}
		}
		printf("%lld",n-i);
		return 0;
	}
	if(isB){
		ll i;
		for(i=n-1;i>=1;i--){
			if(m>=a[n]-a[i]){
				m-=(a[n]-a[i]);
			}else{
				break;
			}
		}
		printf("%lld",n-i);
		return 0;
	}
	ll j=1,mm;
	for(int i=2;i<=n;i++){
		if(i!=1&&a[i]==a[i-1]){
			ans=max(ans,i-j+1);
			continue;
		}
		mm=m;
		j=i;
		while(j-1>0&&mm>=a[i]-a[j-1]){
			j--;
			mm-=a[i]-a[j];
		}
		ans=max(ans,i-j+1);
	}
	printf("%lld",ans);
	return 0;
}
