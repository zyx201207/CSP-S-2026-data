#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
std::vector <int> ds(210000);

int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	int n, m;
	std::cin >> n >> m;
	for(int i = 1; i <= n; i++)
		std::cin >> ds[i];
	std::sort(&ds[1], &ds[n + 1], [](const int& x, const int& y){
		return x > y;
	});
	std::cout << ds[m] << std::endl;
}
