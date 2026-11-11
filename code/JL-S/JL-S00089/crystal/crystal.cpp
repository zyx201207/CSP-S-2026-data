#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500050];
long long sum;
bool cmp(long long a,long long b){
	return a>b;
}
long long ans=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	// for(int i=1;i<=n;i++){
	// 	cout<<a[i]<<' ';
	// }
	// cout<<'\n';
	int r=1;
	for(int i=1;i<=n;i++){
		if(r<=i){
			r=i;
		}
		// cout<<i<<'\n';
		while(1LL*(r-i)*a[i]<=sum+m&&r<=n){
			// cout<<r<<' '<<sum<<'\n';
			r++;
			sum+=a[r];
		}
		ans=max(ans,0LL+r-i);
		sum-=a[i+1];
		// cout<<i<<' '<<r-i<<'\n';
	}
	cout<<ans;
	return 0;
}