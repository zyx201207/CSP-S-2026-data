#include <bits/stdc++.h>
using namespace std;
const int N=5e5+100;
int n,m,a[N],b[N],c[N],cnt;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for (int i=1;i<=n;i++)
	{
		int h=i;
		while(h<=n)
		{
			b[a[h]]++;
			for (int j=1;j<=m;j++)
			{
				if (b[a[h]]==2)
				{
					for (int k=1;i<=m;k++) b[k]=0;
					b[a[h]]++;
				}
			}
			h++;
		}
		for (int j=1;j<=m;j++)
		{
			if (b[j]==1) c[j]++;
		}
	}
	for (int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
}
