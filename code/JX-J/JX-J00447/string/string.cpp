#include <bits/stdc++.h>

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	int N;
	std:: cin >> N;
	// std:: cout << "N: " << N << '\n';
	std:: vector<int> arr(N + 1);
	std:: vector<long long> pre(N + 1);
	std:: vector<char> c(N + 1);
	
	for (int i = 1; i <= N; ++i)
	{
		int x;
		char cc;
		std:: cin >> x >> cc;
		arr[i] = x; c[i] = cc;
		pre[i] = pre[i - 1] + arr[i];
	}
	
	long long res = 0;
	long long il = 1, jl = pre[N];
	while (il < jl)
	{
		int i = std:: lower_bound(pre.begin(), pre.end(), il) - pre.begin();
		int j = std:: lower_bound(pre.begin(), pre.end(), jl) - pre.begin();

		// std:: cout << i << ' ' << j << ' ' << il << ' ' << jl << ' ';
		if (c[i] == c[j])
		{
			long long mn = std:: min(pre[i] + 1 - il, jl - pre[j - 1]);
			il += mn; jl -= mn;
		}
		else
		{
			long long mn = std:: min(pre[i] + 1 - il, jl - pre[j - 1]);
			// std:: cout << mn << ' ';
			res += mn;
			il += mn; jl -= mn;
		}
	}
	
	std:: cout << res << '\n';
	return 0;
}
