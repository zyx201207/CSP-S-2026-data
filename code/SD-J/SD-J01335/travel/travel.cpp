#include <iostream>
#include <cstdio>
#include <algorithm>

struct seat{
	int num;
	char str;
};

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	
	int c1, c2;
	seat s1, s2;
	
	std::cin >> c1 >> s1.num >> s1.str >>  c2 >> s2.num >> s2.str;
	
	bool s_train = (c1 == c2),
		 s_r = (s1.num == s2.num) && s_train,
		 s_w;
	if (s1.str <= 'C') {
		s_w = (s2.str <= 'C');
	}
	else {
		s_w = (s2.str > 'C');
	}
	s_w &= s_r;
	bool n_t = s_w && ( std::abs(int(s1.str - s2.str) == 1) );
	
	std::cout << s_train << s_r << s_w << n_t;
	
	return 0;
}
