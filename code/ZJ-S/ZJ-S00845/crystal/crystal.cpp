#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500010],s[500010],M=1ll;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	long long l=1,r=1;
	while(l<=n&&r<=n)
	{
		long long sum=a[r]*(r-l+1)-(s[r]-s[l-1]);
		if(sum>m)
		{
			l++;
			continue;
		}
		M=max(M,r-l+1);
		r++;
	}
	cout<<M<<'\n';
	return 0;
}
