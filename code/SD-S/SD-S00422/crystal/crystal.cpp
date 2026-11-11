#include <bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
long long a[N];
long long b[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	unsigned long long m;
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
		b[i] = a[i] - a[i-1];
	}
	sort(a+1,a+n+1);
	int ans = -1;
	unsigned long long au = 0;
	for (int i = 2;i<=n;i++)
	{
		int now = 1;
		for (int j=i-1;j>=1;j--)
		{
			au += a[i] - a[j];
			if (au > m)
			{
				ans = max(ans,now);
				break; 
			}	
			now++;
		}
	}
	cout << ans;
	return 0;
}
