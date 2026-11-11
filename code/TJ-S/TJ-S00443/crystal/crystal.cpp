#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	} 
	long long ans=0;
	for(long long i=1;i<=n;i++){
		long long w=i*a[i];
		if(w-s[i]<=m){
			ans=i;
		}
	}
	cout<<ans;
	return 0; 
 }
