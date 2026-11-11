#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1001000],b[1001000]/*前缀能量需求*/,c[1001000],d[1001000],ans=-1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	cin>>n>>m;
	 
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		c[i]=c[i-1]+a[i];
		b[i]=a[i]*(i-1)-c[i-1];
		//区间和：[l,r]=b[r]-b[l]-(l-1)*(a[r]-a[l]) 
	}
//	for(long long i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}

//	int ans1,ans2;
	for(long long i=1;i<=n;i++){
//		cout<<b[i]<<" ";
		if(b[i]>m){
			ans=max(ans,i-1);
//			ans1=i-1;
			break;
		}
		
	}
//	long long l=1,r=n,mid=(l+r)/2;
//	while(){
//		long long x=b[r]-b[mid]-(n-r+mid-1)*(a[r]-a[mid]);
//		if(x<=m){
//			cnt=r-mid+1;
//			ans=max(ans,cnt);
//			int l=(l+mid)/2;
//		}
//	}
	for(long long i=1;i<=n;i++){
		d[i]=b[n]-b[i]-(i-1)*(a[n]-a[i]);
		//区间和：[l,r]=b[r]-b[l]-(l-1)*(a[r]-a[l]) 
	}
	cout<<endl;
	for(long long i=1;i<=n;i++){
//	cout<<d[i]<<" ";
		if(d[i]<=m){
			ans=max(ans,n-i+1);
//			ans2=n-i+1;
			break;   
		}
		
	}
	cout<<ans;
	return 0;
} 
