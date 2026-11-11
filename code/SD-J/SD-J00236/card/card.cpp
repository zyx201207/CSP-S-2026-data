#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int t[500005];
int c[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool fl=false;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ma=a[1];
	if(m==1)
	{
		cout<<n;
		return 0;
	}
	for(int i=2;i<=n;i++)
	{
		if(a[i]<ma)
		{
			fl=true;
			break; 
		}
		ma=max(ma,a[i]);
	}
	if(!fl)
	{
		for(int i=1;i<n;i++)
		{
			if(a[i]!=a[i+1])
			{
				cout<<i<<" ";
			}
		}
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=i;j<=n;j++)
		{
			bool f=false;
			int ncnt=0;
			for(int k=1;k<=cnt;k++)
			{
				if(a[j]==c[k])
				{
					f=true;
					ncnt=k;
					break;
				}
			}
			if(!f)
			{
				c[++cnt]=a[j];
			}
			else
			{
				cnt=ncnt;
			}
		}
		for(int j=1;j<=cnt;j++)
		{
			t[c[j]]++;
			c[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t[i]<<" ";
	}
	return 0;
}
