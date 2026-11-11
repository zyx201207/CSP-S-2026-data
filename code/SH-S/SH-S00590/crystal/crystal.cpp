#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500009],s[500009],ans;
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
	for(int i=n;i>=1;i--){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid)-(s[i-1]-s[mid-1])<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 
