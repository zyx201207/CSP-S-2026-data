#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],f[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	for(long long i=n;i>=1;i--)
	{
		f[i]=a[i];
		for(long long j=m;j>=1;j--)
		{
			if(i==j)continue;
			f[j]=max(f[j],f[j-1]&a[i]);
		}
	}
	cout<<f[n];
 	return 0;
}
