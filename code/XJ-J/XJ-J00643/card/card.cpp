#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a,l=1,r=1,w[N],x[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	for(int i=1;i<=n;i++)
	{
		int s[M],t[M];
		for(int j=i;j<=n;j++)
		{
			if(t[w[j]]!=0)
			{
				for(int k=t[w[j]];k<j;k++)
				{
					t[s[k]]=0;
					s[k]=0;
				}
			}
			else
			{
				s[j]=w[j];
				t[w[j]]=j;
			}
		}
		for(int j=1;j<=m;j++)
		{
			if(t[j]!=0)
			{
				x[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(x[i]!=0)
		{
			cout<<x[i]<<" ";
		}
	}
	return 0;
}