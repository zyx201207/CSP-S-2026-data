#include <iostream>
#include <algorithm>
using namespace std;

long long a[500005];

long long s[500005];

int n;
long long m;

bool check(int M)
{
	for(int i = M;i <= n;i++)
	{
		if((s[i] - s[i - M]) + m >= M * a[i]) return 1;
	}
	return 0;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++)
	{
		s[i] = s[i - 1] + a[i];
	}
	int l = 1,r = n;
	int ans = 0;
	while(l <= r)
	{
		int mid = l + (r - l) / 2;
		if(check(mid))
		{
			l = mid + 1;
			ans = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
} 
