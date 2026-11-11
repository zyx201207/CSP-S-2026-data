#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ans=0;
long long a[500005];
long long help[300005];
long long b[500005];
long long v[500005];
long long enermy[500005];
long long k[500005];
long long num[500005];
bool flag=true;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i-1]>a[i])flag=false;
		v[a[i]]=i;
		k[a[i]]++;
	}
	for(int i=n;i>=1;i--)
	{
		b[i]=help[a[i]];
		help[a[i]]=i;
	}
	if(flag)
	{
		for(int i=1;i<=m;i++)
		{
			cout<<v[i]<<" ";
		}
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			num[0]=0;
			for(int j=1;j<=n;j++)
			{
				num[j]=num[j-1];
				if(a[j]==i)num[j]++;
			}
			ans=0;
			for(int j=1;j<=n;j++)
			{
				long long p=num[n]-num[j-1];
				for(int x=j;x<=n;x++)
				{
					if(b[x]!=0)
					{
						p-=(num[b[x]]-num[x]);
						if(p==0)break;
						x=b[x]-1;
					}
				}
				if(p!=0)ans++;
			}
			cout<<ans<<" ";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
