#include<bits/stdc++.h>
using namespace std;
map<int,int> vis,b,p,minn;
int a[1000000];
int main ()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	b.clear();
	for(int i=1;i<=n;i++)
	{
		int l=1;
		vis.clear();
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==0)
			{
				vis[a[j]]=1;
				b[l]=a[j];
				minn[a[j]]=j;
				l++;
			}
			else
			{
				l=1;
				b[l]=a[j];
				minn[a[j]]=1;
				l++;
				for(int k=minn[a[j]]-1;k>=0;k--)
				{
					b[l]=a[k];
					minn[a[k]]=l;
					l++;
				}
			}
		}
		for(int j=1;j<=l;j++)
		{
			p[b[j]]++;
		}
	}
	p[a[n]]=n;
	vis.clear();
	for(int i=1;i<=m;i++)
	{
		if(vis[i]!=1)
		{
			cout<<p[i]<<" ";
			vis[i]=1; 
		}
	}
	return 0;
}
