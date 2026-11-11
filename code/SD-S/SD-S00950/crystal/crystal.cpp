#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,a[500009],ans=1,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=1,s=0;
	while(r<n){
		while(s+(r-l+1)*(a[r+1]-a[r])>m) s-=a[r]-a[l],l++;
		r++;
		ans=max(ans,r-l+1);
		s+=(r-l)*(a[r]-a[r-1]);
	}
	cout<<ans;
	return 0;
} 
