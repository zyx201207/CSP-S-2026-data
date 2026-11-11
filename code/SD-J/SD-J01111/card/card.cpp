#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[500005],a1[500005],b[30005],p[500005];
	int sum[300005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(b[a[j]]==0)
			{
				b[a[j]]==j;
			} 
			b[a[j]]==j;
		}
	}
}
