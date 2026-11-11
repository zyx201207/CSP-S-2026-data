#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,lnow=1,rnow=1,c=0,ansn=1,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a[0]=0;
	sort(a+1,a+n+1);
	while(rnow<n){
		rnow++;
		
		c+=ansn*(a[rnow]-a[rnow-1]);
		ansn++;
		while(c>m){
			lnow++;
			ansn--;
			c-=(a[rnow]-a[lnow-1]);
		}
		ans=max(ansn,ans);
	}
	cout<<ans;
	return 0;
} 
