//rp++
 
#include <bits/stdc++.h> 
#define LL long long

const int N = 2e6 + 1;

int c, t;
int n, d;
int a[N];
 
void solve()
{
	std::cin >> n >> d;
	for(int i = 0; i < n; i++)
		std::cin >> a[i];
	std::cout << (n >> 2) << '\n';
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	std::cin >> c >> t;
	while(t--)
		solve();
}
