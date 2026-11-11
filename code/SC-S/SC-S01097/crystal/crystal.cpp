# include <iostream>
# include <cstdlib>
# include <algorithm>
# include <vector>
using namespace std;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	vector<int> a = {};
	for (int i = 0; i < n; i++)
	{
		int b;
		cin >> b;
		a.push_back(b);
	}
	int ans = 1;
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++)
	{
		int result = 1;
		int operation = m;
		for (int j = i - 1; j >= 0; j--)
		{
			if (operation >= (a[i] - a[j]))
			{
				result++;
				operation -= (a[i] - a[j]);
			}
			else
			{
				break;
			}
		}
		ans = max(ans, result);
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return EXIT_SUCCESS;
}