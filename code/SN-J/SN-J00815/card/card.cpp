//SN-J00815 李雨轩 陕西延安中学
#include <bits/stdc++.h>
using namespace std;
int a[500005],b[300005],ans[300005];
bool c[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for (int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int k=0;
		for (int j=i;j<=n;j++)
		{
			if (c[a[j]]==false)
			{
				k++;
				b[k]=a[j];
				c[a[j]]=true;
				
			}
			else if(c[a[j]]==true)
			{
				while (b[k]!=a[j])
				{
					c[b[k]]=0;
					b[k]=0;
					k--;
				}
			}
		}
		for (int j=1;j<=m;j++)
		{
			if (c[j]==true) ans[j]++;
		}
	}
	for (int j=1;j<=m;j++)
	{
		cout << ans[j] << " ";
	}
	return 0;
}
