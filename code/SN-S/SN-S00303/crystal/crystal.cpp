#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+1;
long long n,m,a[N],sum[N],ans;
bool check(int x){
	for(int i=1;i+x-1<=n;i++){
		int j=i+x-1;
		if(x*a[j]-sum[j]+sum[i-1]<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}
