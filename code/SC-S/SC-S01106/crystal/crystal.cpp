#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[500006];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long x,y,z;
	cin>>n>>m;
	for(long long i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	x=0;
	for(long long i=1,j=1;j<=n;j++){
		ans=max(ans,j-i+1);
		if(j==n) break;
		x+=(a[j+1]-a[j])*(j-i+1);
		if(x>m){
			while(x>m) x-=(a[j+1]-a[i]),i++;
		}
	}
	cout<<ans;
	return 0;
 } 