#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL n,m,ans;
LL a[100000000];
void s(){
	if(m==0){
		LL mxx=-1e18;
		for(LL i=1;i<=n;i++){
			LL x;
			cin>>x;
			a[x]++;
			if(x>mxx) mxx=x;
		}
		LL ans=-1e18;
		for(LL i=1;i<=mxx;i++){
			if(a[i]>ans) ans=a[i];
		}
		cout<<ans; 
		return;
	}
	for(LL i=1;i<=n;i++){
		cin>>a[i]; 
	}
	sort(a+1,a+n+1);
	LL ans=0;
	for(LL i=n/2+1;i>0;i--){
		if(m>=a[n/2+1]-a[i]){
			m-=a[n/2+1]-a[i];
			ans++;
		}
		else{
			break; 
		}
	}
	for(LL i=n/2+2;i<=n;i++){
		if(a[i]==a[n/2+1]) ans++;
	}
	cout<<ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	s();		
	return 0;
}