#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int w[300005];//daan
int c[300005];//cishu
int s[300005];//weizhi
void f(int c[300005],int s[300005],int i)
{
	if(!c[a[i]]){
		c[a[i]]++;
		for(int j=i;j<=n;j++)
		{
			if(c[a[j]>1])
			{
				c[a[j]]--;
				int k=j;
				for(j;a[k]!=a[j];j++)
				{
					c[a[j]]--;
				}
			}
		}
		for(int j=i;j<=n;j++)
		{
			w[j]+=c[j];
		}
	}
	else
	{
		for(int j=i;j<=s[a[i]];j++)
		{
			c[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			w[j]+=c[j];
		}
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		f(c,s,i);
		s[a[i]]=i;
		c[a[i]]++;
	}
	for(int i=1;i<=m;i++) cout<<w[i]<<" ";
	return 0;
}
