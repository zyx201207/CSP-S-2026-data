#include <bits/stdc++.h>

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int N, m;
	std:: cin >> N >> m;
	std:: vector<int> arr(N + 1);
	
	for (int i = 1; i <= N; ++i) 
	{
		int x;
		std:: cin >> x;
		arr[i] = x;
	}
	
	if (m == 1)
	{
		std:: cout << N << '\n';
		return 0;
	}
	
	if (m == 2)
	{
		std:: vector<int> ct(3);
		for (int i = 1; i <= N; ++i)
		{
			ct[arr[i]]++;
		}
		
		ct[arr[N]] = N;
		std:: cout << ct[1] << ' ' << ct[2] << '\n';
		return 0;
	}
	
	bool f = 1;
	for (int i = 1; i < N; ++i) if (arr[i] > arr[i + 1]) f = 0;
	if (f)
	{
		std:: vector<int> ct(m + 1);
		for (int i = N; i > 0; --i) if (!ct[arr[i]]) ct[arr[i]] = i;
		for (int i = 1; i <= m; ++i) std:: cout << ct[i] << ' ';
		std:: cout << '\n';
		return 0;
	}	
	std:: deque<int> dq;
	std:: vector<int> ct(m + 1);
	for (int i = N; i > 0; --i)
	{
		int x = arr[i];
		bool itq = 0;
		for (auto i : dq) if (x == i) itq = 1;
		
		if (itq)
		{
			auto na = dq;
			for (auto i : na)
			{
				if (i != x) dq.pop_front();
				else break;
			}
		}
		else dq.push_front(x);
		for (auto i : dq) ct[i]++;
	}
	
	for (int i = 1; i <= m; ++i) std:: cout << ct[i] << ' ';
	std:: cout << '\n';
	return 0;
}
