#include <iostream>
#include <string>
using namespace std;

pair<int, char> parse(string s) {
	int num = stoi(s.substr(0, s.size() - 1));
	char ch = s.back();
	return {num, ch};
}

bool left(char c) {
	return c == 'A' || c == 'B' || c == 'C';
}

bool near(char a, char b) {
	if (left(a) && left(b)) {
		if ((a == 'A' && b == 'B') || (a == 'B' && b == 'A'))
			return true;
		if ((a == 'B' && b == 'C') || (a == 'C' && b == 'B'))
			return true;
	}
	return false;
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string c1, s1, c2, s2;
	cin >> c1 >> s1 >> c2 >> s2;
	auto p1 = parse(s1);
	auto p2 = parse(s2);
	int r1 = p1.first;
	char ch1 = p1.second;
	int r2 = p2.first;
	char ch2 = p2.second;
	bool ans1 = (c1 == c2);
	bool ans2 = ans1 && (r1 == r2);
	bool ans3 = ans2 && (left(ch1) == left(ch2));
	bool ans4 = ans3 && near(ch1, ch2);
	cout << ans1 << endl;
	cout << ans2 << endl;
	cout << ans3 << endl;
	cout << ans4 << endl;

	return 0;
}