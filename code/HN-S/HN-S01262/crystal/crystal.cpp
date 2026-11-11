#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+10]={0};
	for(long long i=1;i<=n;i++)
		cin>>a[i];
	sort(a,a+n+1);
	for(long long i=n;i>=1;i--){
		long long x=0;
		for(long long j=i-1;j>=1;j--)
			x+=(a[i]-a[j]);
		if(x<=m){
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
} 
