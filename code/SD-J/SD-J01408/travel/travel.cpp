#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c1, c2;
	string s1, s2;
	int h1, h2, w1, w2;
	cin >> c1 >> s1 >> c2 >> s2;
	h1 = s1[0] * 10 + s1[1], h2 = s2[0] * 10 + s2[1];
	w1 = s1[2] - 'A', w2 = s2[2] - 'A';
	if(w1 == 5) w1 = 4;
	if(w2 == 5) w2 = 4;
	if(c1 != c2) {
		cout << "0000";
		return 0;
	}
	if(h1 != h2) {
		cout << "1000";
		return 0;
	}
	if(min(w1, w2) <= 2 && max(w1, w2) >= 3) {
		cout << "1100";
		return 0;
	}
	if(max(w1, w2) - min(w1, w2) > 1) {
		cout << "1110";
		return 0;
	}
	cout << "1111";
	return 0;
}
