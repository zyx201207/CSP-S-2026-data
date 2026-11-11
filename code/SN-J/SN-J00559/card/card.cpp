#include<bits/stdc++.h>
using namespace std;
int d[300000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,maxn=-1,t=1;
	int b[n][n],c[n];
	cin>>n>>m;
	int a[n+5],s[n];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		d[a[i]]++;
		if(a[i]>maxn)
		{
			maxn=a[i];
		}
	}
	for(int i=1;i<=maxn;i++)
	{
		d[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
		int f[300000];
		int p[n];
		for(int i=1;i<=n;i++)
		{
			p[i]=a[i];
		}
		for(int j=i;j<=n;j++)
		{
		f[p[j]]++;
		b[p[j]][f[p[j]]]=j;
		if(f[p[j]]==2)
		{
			for(int k=b[p[j]][1];k<=b[p[j]][2];k++)
			{
				p[k]=-1;
			}
			f[p[j]]=0;
			b[p[j]][1]=0;
			b[p[j]][2]=0;
		}
		}
	
	for(int i=1;i<=n;i++)
	{
		if(f[p[i]]!=-1 )
		{
			d[p[i]]++;
		}
	}
    }
	for(int i=1;i<=maxn;i++)
	{
		if(d[i]>0)
		{
			cout<<d[i]<<' ';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
