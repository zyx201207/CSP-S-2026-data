#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],ab[N],ans[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++) cin >> a[i];
	for (int i=1;i<=n;i++) b[i]=i;
	for (int i=1;i<=n;i++)//bi sai chang ci
	{
		sort(b+1,b+n+1);
		int num=0;
		bool flag=1;
		for (int j=i;j<=n;j++)//da chu
		{
			for (int x=1;x<=num;x++)//bian li
			{
				if (ab[x]==a[j])
				{
					flag=0;
					continue;
				}
			}
			if (flag==1) ab[++num]=a[j];
			else
			{
				for (int x=1;x<=num;x++)
					if (ab[x]==a[j])
					{
						num=x-1;
						continue;
					}
				ab[++num]=a[j];
			}
		}
		for (int j=1;j<=num;j++) ans[ab[j]]++;
	}
	for (int i=1;i<=m;i++) cout << ans[i] << " ";
	return 0;
}
