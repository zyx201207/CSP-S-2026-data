#include<bits/stdc++.h>
using namespace std;
long long n,maxx=-1;
long long m,a[5000005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1ll);
	for(int i=n;i>=(n-1)/2;i--)
	{
		long long k=0,j=i-1,v=1;
		while(k<=m&&j>0)
		{
			k+=a[i]-a[j];
			j--;
			v++;
		}
		maxx=max(maxx,v);
	}
	cout<<maxx<<endl;
	return 0;
}
