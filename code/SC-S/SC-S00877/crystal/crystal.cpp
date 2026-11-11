#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	long long ans=0,l=1,r=1,s=0;
	while(r<=n&&l<=n){
		while(l+1<=r&&s>m)l++,s=s-(a[r]-a[l-1]);
		while(r+1<=n&&s+(a[r+1]-a[r])*(r-l+1)<=m)s=s+(a[r+1]-a[r])*(r-l+1),r++;
		ans=max(ans,r-l+1);
		s=s+(a[r+1]-a[r])*(r-l+1);
		r++;
	}
	cout<<ans;
	return 0;
}
