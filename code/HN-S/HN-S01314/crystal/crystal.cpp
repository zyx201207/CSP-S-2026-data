#include<bits/stdc++.h>
using namespace std;
int n,l,r,ans;
long long m,a[500005],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	a[n]=1e18;
	a[n]++;
	sort(a,a+n);
	while(l<n){
		while(sum<=m){
			r++;
			sum+=(r-l)*(a[r]-a[r-1]);
		}
		sum-=(r-l)*(a[r]-a[r-1]); 
		r--;
		ans=max(ans,r-l);
		sum-=a[r]-a[l];
		l++;
	}
	cout<<ans+1;
} 
