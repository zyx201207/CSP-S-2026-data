#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
	int n,m;
int a[500005],b[500005];
int check(int k){
	//int kk=2000000000000000000ll;
	for(int i=1;i<=n-k+1;i++){
		if(1ll*(long long)a[i+k-1]*(long long)k-b[i+k-1]+b[i-1]<=m){
			return 1ll*(long long)a[i+k-1]*(long long)k-b[i+k-1]+b[i-1];
		}
	}
	return m+1;
}
signed main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int l=1,r=n;
	int ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)<=m){
			l=mid+1;
			ans=mid; 
		}
		else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
