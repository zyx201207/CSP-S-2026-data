#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long sum[500005];
bool check(long long x){
	for(int i=1;i<=n-x+1;i++){
		long long cost=x*(a[i+x-1])-(sum[i+x-1]-sum[i-1]);
		if(cost<=m)	return true;
	}
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n;
	while(r-l>=10){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	for(int i=r;i>=l;i--){
		if(check(i)){
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
} 
