#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],la[300005],cnt[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	bool f=1;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
		if (a[i]<a[i-1]) f=0;
	}
	if (f)
	{
		for (int i=1; i<=n; i++)
		{
			la[a[i]]=i;
		}
		for (int i=1; i<=m; i++)
		{
			cout <<la[i] << ' ';
		}
	}
	else
	{
		int idx[300005];
		bool fl[300005];
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=m; j++)
			{
				idx[i]=-1;
				fl[j]=1;
			}
			for (int j=i; j<=n; j++)
			{
				if (idx[a[j]]==-1)
				{
					idx[a[j]]=j;
				}
				else if (idx[a[j]]!=-1)
				{
					for (int k=idx[a[j]]; k<=j; k++)
					{
						if (idx[a[k]]>k) idx[a[k]]=-1;
					}
				}
			}
			for (int j=i; j<=m; j++)
			{
				if (idx[j]!=-1 && fl[j])
				{
					cnt[j]++;
					fl[j]=0;
				}
			}
		}
		for (int i=1; i<=m; i++)
		{
			cout << cnt[i] << ' ';
		}
	}
	return 0;
}
