//rp++
 
#include <bits/stdc++.h> 
#define LL long long

const int N = 2e6 + 1;

int c, t;
int n, k;
int u[N], v[N];

void solve()
{
	std::cin >> n >> k;
	for(int i = 0; i < n - 1; i++)
	{
		std::cin >> u[i] >> v[i];
	}
	std::cout << n << '\n'; 
}
int main()
{
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	std::cin >> c >> t;
	while(t--)
		solve();
}

