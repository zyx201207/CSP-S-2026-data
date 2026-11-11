#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500009],np,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(np=n-1;np>0;np--){
		if(m<a[n]-a[np]) break;
		m-=a[n]-a[np];
	}
	ans=n-np;
	//cout<<np<<"!\n";
	for(int i=n-1;i>0;i--){
		m+=(i-np)*(a[i+1]-a[i]);
		for(;np>0;np--){
			if(m<a[i]-a[np]) break;
			m-=a[i]-a[np];
		}
		//cout<<i<<'-'<<np<<'\n';
		ans=max(ans,i-np);
	}
	cout<<ans<<'\n';
	return 0;
}
