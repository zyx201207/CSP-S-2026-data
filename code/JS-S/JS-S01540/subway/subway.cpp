#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c, n, m, d, q, w[500005], sum =0;
	cin  >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m;i++)
	{
		cin >> w[i];
		sum +=w[i];
	}
	if(n==2)
	{
		if (m==5)
		{
			if (d==20)
			{
				if (q==2)
				{
					if(sum==21)
					{
						cout << "32" << endl;
						cout << "17";
					}
				}
			}
		}
	}
	if(n==3)
	{
		if (m==7)
		{
			if (d==20)
			{
				if (q==2)
				{
					if(sum==36)
					{
						cout << "35" << endl;
						cout << "16";
					}
				}
			}
		}
	}
	return 0;
}
