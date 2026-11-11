#include<bits/stdc++.h>
using namespace std;
int n,m,c = 20,a[500001],q[500001],r,lst[500001],ans[500001],lk[500001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		if (a[i] < a[i-1])
		{
			c = 0;
		}
	}
	if (m == 1)
	{
		cout << n;
		return 0;
	}
	else if (m == 2)
	{
		int cnt = 0,res = 0;
		for (int i=1;i<=n;i++)
		{
			if (a[i] == 1 && a[n] == 1)
			{
				cnt++;
			}
			else if (a[i] == 2 && a[n] == 2)
			{
				res++;
			}
			else
			{
				cnt++;
				res++;
			}
		}
		cout << cnt << " " << res;
		return 0;
	}
	if (c == 20)
	{
		for (int i=1;i<=n;i++)
		{
			if (a[i] > a[i-1] && i != 1)
			{
				cout << i-1 << " ";
			}
		}
		cout << n;
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		memset(q,0,sizeof(q));
		memset(lst,0,sizeof(lst));
		r = 0;
		for (int j=i;j<=n;j++)
		{
			if (lst[a[j]] != 0 && j-lk[a[j]] == r+1-lst[a[j]])
			{
				r = lst[a[j]]-1;
				lst[a[j]] = 0;
			}
			r++;
			lst[a[j]] = r;
			lk[a[j]] = j;
			q[r] = a[j];
		}
		for (int j=1;j<=r;j++)
		{
			ans[q[j]]++;
		}
	}
	for (int i=1;i<=m;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}