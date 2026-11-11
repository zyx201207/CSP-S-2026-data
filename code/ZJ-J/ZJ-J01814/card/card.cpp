#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N],k[M],g[M],s[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)g[j]=0;
		for(int j=1;j<=n;j++)s[j]=0;
		int t=1;
		for(int j=i;j<=n;j++)
		{
			s[t]=a[j];
			if(!g[a[j]])
			{
				g[a[j]]=t;
				t++;
			}
			else
			{
			    for(int l=g[a[j]]+1;l<t;l++)
			    {
			    	g[s[l]]=0;
				}
				t=g[a[j]]+1;	
			}
		}
		for(int j=1;j<t;j++)
		{
			k[s[j]]++;
		}
	}
	for(int i=1;i<m;i++)
	{
		cout<<k[i]<<" ";
	}
	cout<<k[m];
	return 0;
}
