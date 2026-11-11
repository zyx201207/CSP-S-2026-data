#include <bits/stdc++.h>
using namespace std;
int n,m,sum,maxn,ans;
int a[500005];
int b[5005][5005],c[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	if(n <= 5000)
	{
		for(int i=2;i<=n;i++)
			for(int j=1;j<=i;j++)
				b[i][j] = a[i]-a[j];
		/*for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cout << b[i][j] << " ";
			cout << endl;
		}*/
		for(int i=1;i<=n;i++)
		{
			sum = 0;
			maxn = 0;
			for(int j=i;j>=1;j--)
			{
				sum += b[i][j];
				maxn++;
				if(sum > m)
				{
					maxn--;
					break;
				}
			}
			ans = max(maxn,ans);
		}
		cout << ans;
	}
	else if(n > 5000)
	{
		for(int i=1;i<n;i++)
			c[i] = a[n] - a[i];
		for(int i=n;i>=1;i--)
		{
			sum += c[i];
			ans++;
			cout << sum << " " << ans << "\n";
			if(sum > m)
			{
				ans--;
				break;
			}
		}
		cout << ans;
	}
	return 0;
}
//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7
//6 5 1 3 5 7 9 11
