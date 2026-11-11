#include<bits/stdc++.h> 
using namespace std;
int n;
long long m,ans,s;
long long a[500010],b[500010],c[500010];
bool cmp(int x,int y)
{
	return x>=y;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]); 
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i-1]-a[i]; 
	}
	b[1]=0;
	for(int i=1;i<=n;i++)
	{
		c[i]=c[i-1]+b[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			s=0;
			for(int k=i;k<=j;k++)
			{
				s+=abs(c[i]-c[k]);
			}
			if(s<=m)
			{
				if(j-i+1>ans)
				{
					ans=j-i+1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}