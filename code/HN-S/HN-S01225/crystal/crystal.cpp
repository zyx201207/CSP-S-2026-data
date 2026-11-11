#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],b[N],sum[N],l=1,r,ans;
bool f=1;
bool f1(long long x){
	for(int i=2;i<n;i++){
		if(sum[i]-sum[i-x+1]<=m||sum[i+x-1]-sum[i]<=m){
			return 1;
		}
	}
	if(sum[x-1]<=m||sum[n-x+1]<=m){
		return 1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]-a[i-1]!=a[2]-a[1]&&i!=1){
			f=0;
		}
	}
	l=1,r=n;
	sort(a+1,a+n+1);
	if(f){
		cout<<min(n,m/abs(a[2]-a[1])+1);
		return 0;
	}
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	sum[2]=b[2];
	for(int i=3;i<=n;i++){
		sum[i]=sum[i-1]+a[i]-a[1];
	}
	/*for(int i=2;i<=n;i++){
		cout<<b[i]<<" ";
	}
	cout<<'\n';
	for(int i=2;i<=n;i++){
		cout<<sum[i]<<" ";
	}*/
	while(l<=r){
		long long mid=(l+r)>>1;
		if(f1(mid)){
			ans=max(ans,mid);
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
 
