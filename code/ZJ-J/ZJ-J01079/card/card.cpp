#include<bits/stdc++.h>
using namespace std;
int a[10000000],b[10000000],sum[10000000],n,m;
bool f[10000000],g[11000000];
void clear()
{
	for(int i=1;i<=m+2;i++)
	{
		f[i]=false;
		g[i]=false;
	}
}
void ctrlc()
{
	for(int i=1;i<=n;i++)
	{
		a[i]=b[i];
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
	}
	for(int i=1;i<=n;i++)
	{
		clear();
		ctrlc();
		for(int j=i;j<=n;j++)
		{
			if(f[a[j]]==true)
			{
				int y=j-1;
				while(a[y]!=a[j])
				{
					a[y]=-1;
					f[a[y]]=false;
					y--;
					//a[(y<0?0:y)]=-1;
					//f[a[(y<0?0:y)]]=false;
				}
			}
			f[a[j]]=true;
		}
		clear();
		for(int j=i;j<=n;j++)
		{
			if(a[j]!=-1&&!g[a[j]])
			{
				sum[a[j]]++;
				cout<<a[j]<<' ';
			}
			g[a[j]]=true;
		}
		cout<<'\n';
	}
	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<' ';
	}
}
/*no!!!!*/