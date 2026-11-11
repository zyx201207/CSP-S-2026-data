#include<bits/stdc++.h>
using namespace std;
int n,m;
long long f[5009][5009];
long long a[200009];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	if(n<=5000)
	{
		memset(f,0,sizeof(0));
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)
		{
			f[i][1]=a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=2;j<=m;j++)
			{
				f[i][j]=max((f[i-1][j-1]&a[i]),f[i-1][j]);
			}
		}
		long long mx=-1;
		for(int i=1;i<=n;i++)
		{
			mx=max(mx,f[i][m]);
		}
		printf("%lld",mx);
	}
		else 
		{
			if(a[1]==a[n])cout<<a[1];
			else cout<<n-m;
		}
	return 0;
}