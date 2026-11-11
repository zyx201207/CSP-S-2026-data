# include <bits/stdc++.h>
# define ll long long
using namespace std;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	int c1, c2;
	string s1, s2;
	
	cin >> c1 >> s1 >> c2 >> s2;
	
	int t1 = (s1[0] - '0' * 10 + s1[1] - '0');
	int t2 = (s2[0] - '0' * 10 + s2[1] - '0');
	
	char ch1 = s1[2], ch2 = s2[2];
	
	if (c1 != c2) {
		cout << "0000";
		return 0;
	}
	
	if (t1 != t2) {
		cout << "1000";
		return 0;
	}
	
	if (!((ch1 <= 'C' && ch2 <= 'C') || (ch1 >= 'D' && ch2 >= 'D'))) {
		cout << "1100";
		return 0;
	}
	
	if (abs(ch1 - ch2) != 1) {
		cout << "1110";
		return 0;
	}
	
	cout << "1111";
	return 0;
}
