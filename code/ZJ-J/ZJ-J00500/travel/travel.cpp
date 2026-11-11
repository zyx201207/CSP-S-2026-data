#include<bits/stdc++.h>
using namespace std;
int main () {
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	string c1 , s1 , c2 , s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		cout << 1;
	}
	else {
		cout << 0 << 0 << 0 << 0 << "\n";
		return 0;
	}
	int p = 0;
	int len = s1.size();
	int num1 = 0;
	char sum1;
	while (p < len) {
		if (s1[p] >= '0' && s1[p] <= '9') {
			num1 = num1 * 10 + (s1[p] - '0');
		}
		else {
			sum1 = s1[p];
			break;
		}
		p++;
	}
	p = 0;
	len = s2.size();
	int num2 = 0;
	char sum2;
	while (p < len) {
		if (s2[p] >= '0' && s2[p] <= '9') {
			num2 = num2 * 10 + (s2[p] - '0');
		}
		else {
			sum2 = s2[p];
			break;
		}
		p++;
	}
	if (num1 == num2) {
		cout << 1;
	}
	else {
		cout << 0 << 0 << 0 << "\n";
		return 0;
	}
	bool tf = false;
	if (sum1 >= 'A' && sum1 <= 'C' && sum2 >= 'A' && sum2 <= 'C') {
		cout << 1;
		tf = true;
	}
	else if (sum1 >= 'D' && sum1 <= 'F' && sum2 >= 'D' && sum2 <= 'F') {
		cout << 1;
		tf = true;
	}
	else cout << 0;
	int h1 = sum1 - 'A' + 1;
	int h2 = sum2 - 'A' + 1;
	if (h1 == 6) h1 = 5;
	if (h2 == 6) h2 = 5;
	if (tf && (abs(h1 - h2) == 1)) cout << 1;
	else cout << 0;
	cout << "\n";
	return 0;
}