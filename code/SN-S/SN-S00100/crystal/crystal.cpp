#include <algorithm>
#include <iostream>
#include <vector>
#include <stdio.h>
 
std::vector <long long> ds(510000);
int find(const int&, const int&, long long);
bool check(int, long long, int);
int special(int, long long, long long);
int solve(int, long long);

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int n;
	long long m;
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++)
		std::cin >> ds[i];
	std::cout << solve(n, m);
}

int find(const int& start, const int& last, long long m){
	int left = start, right = last;
	while(left < right){
		int mid = (left + right + 1) / 2;
		if(check(mid, m, last))
			left = mid;
		else
			right = mid - 1;
	}
	return left;
}

bool check(int x, long long m, int n){
	if(x == 1)
		return true;
	long long ans = 9000000000000000000;
	for(int l = 1; l + x - 1 <= n; l++){
		int r = l + x - 1;
		long long sum = 0;
		for(int k = l; k <= r; k++)
			sum += (ds[r] - ds[k]);
		ans = std::min(ans, sum);
	}
	return (ans <= m);
}

int special(int n, long long m, long long q){
	for(long long i = 1; i < n; i++){
		long long a = i * (i - 1) * q / 2;
		if(a >= m)
			return i - 1;
	}
	return n;	
}

int solve(int n, long long m){
	if(n == 1)
		return 1;
	int d = ds[2] - ds[1];
	bool flag = true;
	for(int i = 3; i <= n; i++)
		if(ds[i] - ds[i - 1] != d){
			flag = false;
			break;
		}
	if(flag)
		return special(n, m, ds[2] - ds[1]);
	std::sort(&ds[1], &ds[n + 1]);
	return find(1, n, m);
}
