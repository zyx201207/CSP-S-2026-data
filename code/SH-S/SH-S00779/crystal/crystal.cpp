#include <bits/stdc++.h>
using namespace std;
int n;
long long a[500010];
long long sum[500010];
long long m;
long long ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	long long r=1;
	for(long long l=1;l<=n;l++){
		while(r<=n and (r-l)*a[r]-sum[r-1]+sum[l-1]<=m)r++;
		ans=max(ans,r-l);
	}
	cout<<ans<<endl;
	return 0;
} 
