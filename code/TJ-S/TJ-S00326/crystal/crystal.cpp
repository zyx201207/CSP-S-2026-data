//rp++
 
#include <bits/stdc++.h> 
#define LL long long

const int N = 5e5 + 1;

int n;
LL m;
LL c[N];
LL prefix[N];
LL max_res = 1;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		std::cin >> c[i];
	}	
	std::sort(c + 1, c + n + 1);
	for(int i = 1; i <= n; i++)
	{
		prefix[i] = c[i] - c[1];
		//printf("prefix[i] = %lld prefix[i-1] = %lld c[i] = %lld c[i-1] = %lld\n",prefix[i], prefix[i-1], c[i], c[i-1]);
	}
//	for(int i = 0; i <= n; i++)
//	{
//		std::cout << c[i] << ' ';
//	}	
//	std::cout << '\n';
//	for(int i = 0; i <= n; i++)
//	{
//		std::cout << prefix[i] << ' ';
//	}	
//	std::cout << '\n';
	int l = 1;
	LL res = 1;
	for(int i = 2; i <= n; i++)
	{
		LL a = (c[i] - c[i-1]) * res; 
//		printf("S i = %d, c[i] = %lld, c[i-1] = %lld, m = %lld, a = %lld, res = %d, prefix[i-1] = %lld, prefix[l] = %lld, l = %d\n",
//		i, c[i], c[i-1], m, a, res, prefix[i-1], prefix[l], l);
		while(a > m)
		{
//			puts("while"); 
			max_res = std::max(res, max_res);
			res--;
			m += prefix[i-1] - prefix[l];
			l++;
			a -= (c[i] - c[i-1]);
//			printf("MID i = %d, c[i] = %lld, c[i-1] = %lld, m = %lld, a = %lld, res = %d, prefix[i-1] = %lld, prefix[l] = %lld, l = %d\n",
//			i, c[i], c[i-1], m, a, res, prefix[i-1], prefix[l], l);
		}
		m -= a;
		res++;
		max_res = std::max(res, max_res);
//		printf("E i = %d, c[i] = %lld, c[i-1] = %lld, m = %lld, a = %lld, res = %d, prefix[i-1] = %lld, prefix[l] = %lld, l = %d\n",
//		i, c[i], c[i-1], m, a, res, prefix[i-1], prefix[l], l);
	}
	std::cout << max_res;
}
