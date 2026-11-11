#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,x[2000005],ans,sum;
ll f;
void dfs(int k,int v,int ci)
{
	if(k>v) return;
	if(k==v)
	{
		if(ans>ci)
		{
			ans=ci;
			f=1;
			return;
		}
		else if(ans==ci)
		{
			f++;
			return;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(abs(x[k]-x[k+i])<=d)dfs(k+i,v,ci+1);
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				f=0;
				ans=0x7fffff;
				dfs(i,j,0);
				if(f==2) sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}