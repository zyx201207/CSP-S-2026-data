#include <iostream>
#include <string>

bool chkc(char x1, char x2) {
	if (x1 == 'C' || x1 == 'A' || x1 == 'B')
		return (x2 == 'C' || x2 == 'A' || x2 == 'B');
	else
		return (x2 == 'D' || x1 == 'E');
}

bool chkx(char x1, char x2) {
	int num1 = x1, num2 = x2;
	if (num1 + 1 == num2) {
		if (x1 == 'C')
			return 0;
		else
			return 1;
	} else if (num1 - 1 == num2) {
		if (x1 == 'D')
			return 0;
		else
			return 1;
	} else
		return 0;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	std::string c1, s1, c2, s2, ans = "";
	std::cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2)
		ans.push_back('1');
	else {
		ans = "0000";
		std::cout << ans;
		return 0;
	}
	std::string tmp1, tmp2;
	char ch1 = s1[2], ch2 = s2[2];
	for (int i = 0; i < 2; i++) {
		tmp1.push_back(s1[i]);
		tmp2.push_back(s2[i]);
	}
	if (tmp1 == tmp2)
		ans.push_back('1');
	else {
		ans = "1000";
		std::cout << ans;
		return 0;
	}
	if (chkc(ch1, ch2))
		ans.push_back('1');
	else {
		ans = "1100";
		std::cout << ans;
		return 0;
	}
	if (chkx(ch1, ch2))
		ans.push_back('1');
	else {
		ans = "1110";
		std::cout << ans;
		return 0;
	}
	std::cout << ans;
	return 0;
}
