#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int t,c,n;
long long d,x[2000005],ans,cnt;
bool b;
void dfs(int stz,int edz,int cntt)
{
	if(b)
	{
		return;
	}
	if(stz==edz)
	{
		if(cntt<ans)
		{
			cnt=1;
			ans=cntt;
		}
		else if(cntt==ans)
		{
			cnt++;
		}
		if(cnt>2)
		{
			b=1;
		}
		return;
	}
	for(int i=stz+1;i<=edz;i++)
	{
		if(b)
		{
			return;
		}
		if(abs(x[i]-x[stz])<=d)
		{
			dfs(i,edz,cntt+1);
		}
		else
		{
			break;
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n;
		cin>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
		}
		long long xyz=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=1e18;
				b=0;
				cnt=0;
				dfs(i,j,0);
				if(cnt==2)
				{
					xyz++;
				}
			}
		}
		cout<<xyz<<endl;
	}
	return 0;
}
