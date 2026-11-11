#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int c[300010];
map<int,int> cnt;
bool f[300010];
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
		memset(f,0,sizeof f);
		memset(c,0,sizeof c);
		for(int j=i;j<=n;j++)
		{
			f[a[j]]=1;
			if(c[a[j]]==0)
			{
				c[a[j]]=j;
			}
			else{
				for(int k=c[a[j]]+1;k<j;k++)
				{
					f[a[k]]=0;
					c[a[k]]=0;
				 } 
				 c[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++)
		{
			cnt[j]+=f[j];
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" "; 
	 } 
	return 0;
 } 
