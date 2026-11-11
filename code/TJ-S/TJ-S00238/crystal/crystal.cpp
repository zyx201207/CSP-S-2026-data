#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int n;
long long m;
long long a[500010];
long long s[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	s[0] = 0;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		s[i] = s[i-1] + a[i];
	}
	bool flag = true;
	int d = a[2] - a[1];
	for(int i=3;i<=n;i++)
	{
		flag = flag & (a[i] - a[i-1] == d);
	}
	if(flag)
	{
		double t = m * 1.0 / d;;
		int k = (int)((-1 + sqrt(1 + 8 * t)) / 2);
		cout << min(k+1 , n);
	}
	else
	{
		int ans = 0;
		for(int i=n;i>=1;i--)
		{
			if(i <= ans) break;
			int ans0 = ans;
			int ops = ans * a[i] - (s[i-1] - s[i-ans-1]);
			//cout << "now i = " << i << ", ans = " << ans << ", ops = " << ops << endl << "- - - - - - - - -" << endl;
			while(ops <= m)
			{
				ans0++;
				if(i <= ans0)
				{
					break;
				}
				ops += a[i] - a[i-ans0];
				//cout << "i = " << i << ", ans0 = " << ans0 << ", ops = " << ops << endl;
			}
			ans = max(ans0 - 1,ans);
			//cout << "ans = " << ans << endl << "-----------------" << endl;
		}
		cout << ans + 1;
	}
	return 0;
}
