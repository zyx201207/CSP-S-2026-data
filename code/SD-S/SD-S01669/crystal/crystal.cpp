#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
LL n,m,a[500005],s[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	LL ans=0;
	int l=1,r=1;
	while(r<=n){
		while(l<r&&(r-l+1)*a[r]-m>s[r]-s[l-1])l++;
		ans=max(ans,(LL)r-l+1);
		r++;
	}
	cout<<ans;
	return 0;
} 
//rp++,biegua
