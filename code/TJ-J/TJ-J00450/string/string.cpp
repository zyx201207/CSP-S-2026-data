#include <iostream>
#include <string>
#include <cstddef>

int n;
std::size_t neech;
std::string s;
std::string fh, eh;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	std::cin >> n;
	for(int i = 0;i < n;++i){
		int num = 0;
		char charac = '\0';
		std::cin >> num;
		std::cin >> charac;
		s += std::string(num, charac);
	}
	std::size_t len = s.size();
	if(len == 1){
		std::cout << 0;
		return 0;
	}
	if(s.size() % 2 == 1){
		--len;
		for(std::size_t i = s.size() / 2;i < s.size() - 1;++i)
			s[i] = s[i + 1];
	}
	// len == s.size()
	for(std::size_t i = 0;i <= len / 2 - 1;++i)
		if(s[i] != s[len - i - 1])
			++neech;
	std::cout << neech;
	return 0;
}
