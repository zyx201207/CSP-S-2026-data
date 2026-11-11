#include <bits/stdc++.h>
using namespace std;
int n,m;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	int a[n],s[n],b[n],c[n];
	for (int i=1;i<=n;i++)
	{
		c[i]=0;
		cin >> a[i];
		b[i]=a[i];
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			s[j]=0;
			a[j]=b[j];
		}
		for (int j=i;j<=n;j++)
		{
			int x=a[j];
			if(s[x]!=0)
			{
				for (int q=s[x];q<j;q++)
				{
					s[a[q]]=0;
					a[q]=0;
				}
				s[x]=j;
			}
			else
			{
				s[x]=j;
			}
		}
		for (int j=1;j<=m;j++)
		{
			if(s[j]!=0)
				c[j]++;
		}
	}
	for (int i=1;i<=m;i++)
	{
		cout << c[i] << " ";
	}
	return 0;
}
