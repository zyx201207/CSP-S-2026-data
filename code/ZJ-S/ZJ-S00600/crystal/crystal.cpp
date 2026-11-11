#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010],sum[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)	sum[i]=sum[i-1]+a[i];
	long long mx=1;
	int l=1,r=n;
	while(l<=r){
		int i=(l+r)/2;
		long long q=(i-1)*a[i]-sum[i-1];
		if(q>m)	r=i-1;
		else if(q<=m)	l=i+1;
	}
	cout<<r;
	return 0;
} 
