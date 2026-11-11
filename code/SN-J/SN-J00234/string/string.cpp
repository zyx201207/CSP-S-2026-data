#include <iostream>
#include <string>
#include <stdio.h>

int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int n;
	std::string str = "";
	std::cin >> n;
	for(int i = 1; i <= n; i++){
		int a;
		char c;
		std::cin >> a >> c;
		std::string now(a, c); 
		str += now;
	}
	int ans = 0, i = 0, j = str.length() - 1;
	while(i < j){
		if(str[i] != str[j])
			ans++;
		i++, j--;
	}
	std::cout << ans << std::endl;
}
