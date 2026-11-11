#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long _sum[500005];
long long n,k;
int sumf(int h,int t){
	int l=h,r=h+t-1;
	long long sss=_sum[r]-_sum[l-1];
	return a[r]*t-sss;
}
bool check(int g){
	for(int i=1;i<=n-g+1;i++){
		if(sumf(i,g)<=k){
			
			return true;
		}
	}
	return false;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++){
		_sum[i]=a[i]+_sum[i-1];
	}
	
	int l=0,r=n;
	//for(int i=0;i<=n;i++){
	//	if(!check(i)){
	//		cout<<i-1;
	//		return 0;
	//	}
	//}
	int ans=0;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(check(mid)){
			ans=l;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	while(check(ans++)){
	}
	cout<<ans-2;
	return 0;
} 