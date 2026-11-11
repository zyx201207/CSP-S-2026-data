#include<bits/stdc++.h>
using namespace std;

int n;
long long m,ans,c,jg;
long long a[500100],b[500100],s[5010][5010]; 

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	
	stable_sort(a+1,a+n+1);
	
	
	if (n<=5000)
	{
		for (int i=1;i<n;i++) b[i]=a[i+1]-a[i];
		for (int i=1;i<=n;i++)
		{
			for (int j=i;j<=n;j++)
			{
				s[i][j]=s[i][j-1]+b[j-1]*(j-i);
				if (s[i][j]<=m&&ans<j-i+1) ans=j-i+1;
			}
		}
	}
	else
	{
		c=a[2]-a[1];
		for (int i=1;i<=n-1;i++)
		{
			jg=jg+c*(i-1);
			if (jg>m)
			{
				ans=i;
				break;
			}
		}
		ans--;
	}
	
	
	cout<<ans;
	
	return 0;
}
