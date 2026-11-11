#include <iostream>
#include <vector>
#include <cstring>

int ans[300001];
int tong[300001], a[500001];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	std::cin >> n >> m;
	for(int i = 1;i <= n;i ++)
	{
		std::cin >> a[i];
	}
	for(int i = 1;i <= n;i ++)
	{
		std::vector<int> st;
		for(int j = i;j <= n;j ++)
		{
			if(tong[a[j]])
			{
				while(!st.empty() && st.back() != a[j])
				{
					tong[st.back()] --;
					st.pop_back();
				}
			} else
			{
				st.push_back(a[j]);
				tong[a[j]] ++;
			}
		}
		for(int j = 0;j < st.size();j ++)
		{
			ans[st[j]] ++;
		}
		std::memset(tong, 0, sizeof(tong));
	}
	for(int i = 1;i <= m;i ++)
	{
		std::cout << ans[i] << ' ';
	}
	return 0;
}
