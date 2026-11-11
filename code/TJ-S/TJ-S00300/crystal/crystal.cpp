#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
long long n,m;
long long sum[500005];
bool check(int mid,vector<long long>&a){
	for(int i=mid;i<=n;i++){
		long long s=sum[n]+mid*a[i]-(sum[i]-sum[i-mid]);
		if(s-sum[n]<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<long long> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=0,r=n,ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid,a)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
