#include<bits/stdc++.h>
using namespace std;
long long int i,j,k,n,m,f[1000005],a[1000005],maxn=-1,ans=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		maxn=max(a[i],maxn);
		if(i==1)
		ans=a[i];
		else
		ans=ans&a[i];
	}
	if(m==1)
	{
		cout<<maxn<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(m==n)
	{
		cout<<ans<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(m==2&&n<=1000)
	{
		ans=0;
		maxn=-1;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i!=j)
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	f[1]=maxn;
	for(i=2;i<=n;i++)
	{
		for(j=m;j>=1;j--)
		{
			f[j]=max(f[j],f[j-1]&a[i]);
		}
	}
	cout<<f[m]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
