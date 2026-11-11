#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
int n,m;
int a[MAXN];
int b[MAXN];
int c[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int o=1;
		for(int j=1+i-1;j<=n;j++)
		{
			bool flag=true;
			int q;
			for(int k=1;k<=o-1;k++)
			{
				if(a[j]==b[k])
				{
					flag=false;
					q=k;
				}
			}
			if(!flag)
			{
				for(int k=q;k>=o-1;k++)
				{
					b[k]=0;
				}
				o=q;
			}
			b[o]=a[j];
			o++;
		}
//		for(int j=1;j<=o-1;j++)
//		{
//			cout << b[j] << endl;
//		}
		for(int j=1;j<=o-1;j++)
		{
			c[b[j]]++;
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << c[i] << " ";
	}
	return 0;
}
