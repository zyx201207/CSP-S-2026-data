#include<bits/stdc++.h>
using namespace std;
long long a[514114];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n;cin>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	long long l=1,r=1,ans=0,sum=0;
	while(l<=n && r<=n){
		while(sum<=m && r<=n){
			r+=1;
			sum+=(r-l)*(a[r]-a[r-1]);
		}
		ans=max(ans,r-l);
		while(sum>m && l<=r){
			sum-=a[r]-a[l];
			l+=1;
		}
	}
	cout<<ans;
	return 0;
}