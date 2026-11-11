#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[5000005];
vector<int> v;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m >> a[1];
	int fb = 0;
	for (int i = 2;i <= n;i++)
	{
		cin >> a[i];
	}
	int ans = 0;
	sort(a + 1,a + n + 1);
	int temp = a[2] - a[1];
	for (int i = 1;i <= n - 1;i++)
	{
		if (a[i+1] - a[i] != temp)
		{
			fb = 1;
			break;
		}
	}
	int l = a[1],r = a[n];
	if (fb == 0)
	{
		//cout << "B" << ' ';
		int ans = sqrt(m * 2 / temp);
		cout << ans << "\n";
		return 0;
	}
	while (l < r)
	{
		//mid->校准值，t->操作数，sum->参与合成crystal数 
		int mid = (l + r + 1) / 2,t = m,sum = 0;
		//cout << l << ' ' << mid << ' ' << r << ' ';
		for (int i = n;i >= 1;i--)
		{
			if (a[i] < mid)
			{
				t -= mid - a[i];
				if (t >= 0) sum++;
			}
			else if (a[i] == mid) sum++;
		}
		
		if (t >= 0) l = mid;
		else r = mid - 1;
		ans = max(ans,sum);
		//cout << sum << "\n";
	}
	cout << ans << "\n";
}
