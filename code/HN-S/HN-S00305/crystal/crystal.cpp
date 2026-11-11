#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,h,maxx=INT_MIN,a[500005],c[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		h+=a[i];
	}
	sort(a+1,a+1+n);
	int b=0;
	for(int i=2;i<n;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i]){
			b++;
		}
	}
	if(m>=maxx*n-h){
		cout<<n;
		return 0;
	}
	if(b==0){
		if(a[2]-a[1]==0){
			cout<<n;
			return 0;
		}
		m/=(a[2]-a[1]);
		int ans=1;
		while(m>=0){
			m-=ans;
			ans++;
		}
		cout<<ans-1;
		return 0;
	}
	int da=LLONG_MIN;
	for(int i=1;i<=n;i++){
		int ans=0,z=m;
		while(z>=0&&i>ans+1){
			ans++;
			z=z-a[i]+a[i-ans];
		}
		if(z>=0){
			da=max(da,ans+1);
		}else{
			da=max(da,ans);
		}
	}
	cout<<da;
	return 0;
}
