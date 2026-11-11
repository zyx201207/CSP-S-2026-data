#include<bits/stdc++.h>
using namespace std;
long long arr[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n,greater<long long>());
	if(m==1) cout<<arr[0]<<'\n';
	else if(m==2){
		long long mx=-1;
		for(long long i=0;i<n-1;i++) for(long long j=i+1;j<n;j++) mx=max(mx,arr[i]&arr[j]);
		cout<<mx<<'\n';
	}else if(m==n || m==n-1){
		long long sum=arr[0];
		for(long long i=1;i<n;i++) sum&=arr[i];
		cout<<sum<<'\n';
	}else{
		long long ans=arr[0];
		for(long long i=1;i<m;i++) ans&=arr[i];
		cout<<ans<<'\n';
	}
	return 0;
}
