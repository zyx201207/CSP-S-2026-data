#include<bits/stdc++.h>
using namespace std;
long long a[500010],f[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long ans=0,l=1,r=1;
	while(l<=r&&r<=n){
		long long sum=f[r-1]+(r-l)*(a[r]-a[r-1]);
		while(l<=r&&sum>m){
			sum-=(a[r]-a[l]);
			l++;			
		}
		f[r]=sum;
		ans=max(ans,(r-l+1));
		r++;
	}
	cout<<ans;
	return 0;
}
