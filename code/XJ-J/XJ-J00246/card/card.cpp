#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, m, a[500010], posi[300010], answers[300010];
bool bottle[300010];
vector<int> vec;

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	for (int ju = 1; ju <= n; ++ju)
	{
		vec.clear();
		vec.push_back(-2);
		memset(posi, -1, sizeof posi);
		memset(bottle, false,sizeof bottle);
		for (int i = ju; i <= n; ++i)
		{
			if (!bottle[a[i]])
			{
				bottle[a[i]] = true;
				vec.push_back(a[i]);
				posi[a[i]] = vec.size() - 1;
			}
			else
			{
				for (int j = vec.size() - 1; j > posi[a[i]]; --j)
				{
					bottle[vec[j]] = false;
					posi[vec[j]] = -1;
					vec.pop_back();
				}
			}
		}
		for (int i = 1; i <= m; ++i)
		{
			if (bottle[i])
				++answers[i];
		}
	}
	for (int  i = 1; i<= m; ++i)
	{
		cout << answers[i] << ' ';
	}
	return 0;
}

