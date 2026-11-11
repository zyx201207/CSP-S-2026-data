#include <bits/stdc++.h>
#define intt long long
using namespace std;
intt n,m,a[600001],sum[600001],ans=1;
intt f(int ind){
	int l=0,r=ind;
	while(l+1<r){
		int mid=(l+r)/2;
		intt cnt=sum[ind]-sum[mid]-(mid-1)*(a[ind]-a[mid]);
		if(cnt<=m)
			r=mid;
		else l=mid;
	}
	return ind-r+1;
}
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2; i<=n; i++){
		sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	/*for(int i=2; i<=n; i++){
		for(int j=1;j<i;j++){
			cout<<sum[i]-sum[j]-(j-1)*(a[i]-a[j])<<" ";
		}
		cout<<endl;
}*/
	for(int i=2;i<=n;i++){
		//cout<<f(i)<<" ";
		ans=max(ans,f(i));
	}
	cout<<ans<<endl;
	return 0;
}
/* 
5 5 
1 2 4 8 9

5 8
-3 -1 2 2 7

Oct31==Dec25?
*/
