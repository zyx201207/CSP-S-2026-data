#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[501010];
int s[501010];
int f[301010];
int sum[301010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(s,-1,sizeof(s));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]==a[j])
			{
				s[i]=j;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++)
		{
			while(s[j]!=-1)
			{
				j=s[j];
			}
			f[a[j]]=1;
		}
		for(int j=1;j<=m;j++)
		{
			sum[j]+=f[j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
}