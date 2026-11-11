#include <iostream>
using namespace std;
int n,m;
int a[500010];
int cnt[300010];
int existed[300010];
void wash()
{
	for(int i=1;i<=m;i++) existed[i] = 0;
}
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	bool flag = true;
	bool flagM = (m <= 2);
	a[0] = 0;
    for(int i=1;i<=n;i++)
    {
    	cin >> a[i];
    	flag = flag && (a[i] >= a[i-1]);
	}
	if(flag)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i+1] != a[i])
			{
				cnt[a[i]] = i;
			}
		}
		for(int i=1;i<=m;i++)
		{
			cout << cnt[i] << ' ';
		}
		return 0;
	}
	if(flagM)
	{
		cnt[a[n]] = n;
		for(int i=1;i<=n;i++)
		{
			if(a[i] != a[n])
			cnt[a[i]]++;
		}
		for(int i=1;i<=m;i++)
		{
			cout << cnt[i] << ' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		wash();
		for(int j=i;j<=n;j++)
		{
			if(existed[a[j]])
			{
				for(int k = existed[a[j]];k <= j;k++)
				{
					existed[a[k]] = 0;
				}
			}
			existed[a[j]] = j;
		}
		for(int j=1;j<=m;j++)
		{
			if(existed[j])
			{
				cnt[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << cnt[i] << ' ';
	}
	return 0;
}
