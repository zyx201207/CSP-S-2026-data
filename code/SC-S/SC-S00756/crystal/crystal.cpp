#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],sum[500005];
bool check(int t){
	for(int i=1;i<=n-t+1;i++){
		int j=i+t-1;
		int cnt=sum[j]-sum[i-1];
		if(a[j]*t>=cnt&&a[j]*t<=cnt+m){
			return 1;
		}	
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	sort(a+1,a+n+1); 
	/*
	for(int i=1;i<=n;i++){
		cout<<sum[i]<<" ";
	}
	cout<<endl;
	*/
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<r;
	return 0;
}
/*

5 5
1 2 4 8 9


5 8
-3-1 2 2 7

*/