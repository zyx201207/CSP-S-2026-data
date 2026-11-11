#include<bits/stdc++.h>
using namespace std;
long long n,ans,m,a[500005],p[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]+a[i];
		if(1LL*(i-1)*a[i]-p[i-1]<=m) ans=i;
		else break;
	}
	cout<<ans;
	return 0;
}