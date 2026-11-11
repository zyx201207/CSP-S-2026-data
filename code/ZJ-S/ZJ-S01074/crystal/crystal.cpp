#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,sum[500005];
bool check(long long x){
	long long sum=0;
	for(long long i=1;i<=n;i++){
		if(x>=a[i]) sum+=(x-a[i]);
	}
	if(sum<=m) return true;
	else return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) flag=false;
	}
	if(flag){
		for(long long i=1;i<=n;i++){
			sum[i]=sum[i-1]+a[i-1];
		}
		for(long long i=n;i>=1;i--){
			if(sum[i]<=m){
				cout<<i;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	int l=1,r=a[n],ans=0;
	while(l<r){
		int mid=(r-l)/2+l;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=ans) cnt++;
	}
	cout<<cnt;
	return 0;
}
