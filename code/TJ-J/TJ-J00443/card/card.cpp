#include <bits/stdc++.h>
#define LL long long

const int N = 5e5 + 1;

int n, m;
int a[N];
int res[N];
bool b[N];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	std::cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		std::cin >> a[i];
	}
	for(int i = 0; i < n; i++)
	{
		memset(b, false, sizeof b);
		std::deque<int> dq;
		for(int j = i; j < n; j++)
		{
			if(b[a[j]])
			{
				int top = -1;
				while(top != a[j])
				{
					top = dq.back();
					dq.pop_back();
				}
			}
			dq.push_back(a[j]);
			b[a[j]] = true;
		}
		while(!dq.empty())
		{
			res[dq.front()]++;
			dq.pop_front();
		}
	}
	for(int i = 1; i <= m; i++)
		std::cout << res[i] << ' ';
}


