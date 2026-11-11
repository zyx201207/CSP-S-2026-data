#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn;
long long a[5000050],sum[5000050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long l=1,r=1,ans;
	while(l<=n&&r<=n){
		ans=a[r]*(r-l+1)-(sum[r]-sum[l-1]);
		if(ans<=m){
			maxn=max(r-l+1,maxn);
			r++;
		}
		else{
			l++;
		}
		
	}
	cout<<maxn;
	return 0;
}
