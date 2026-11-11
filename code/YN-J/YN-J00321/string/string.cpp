#include <bits/stdc++.h>
using namespace std;
long long x, n, i = 1, h, h1;
char c;
string s;
const long long M = 1e+5;

struct HW {
	long long x;
	char c;
} a[M];

bool f(string s) {
	string s1;
	int n = s.size();
	for (i = 0; i < s.size(); i++)
		s1 += s[n - 1 - i];
	if (s == s1)
		return true;
	else
		return false;
}

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int n1 = n;
	while (n--) {
		cin >> x >> c;
		s += c;
		h1 += x;
		int w = s.find(c);
		a[w + 1].x += x, a[w + 1].c = c;
	}
	i = s.size();
	if (f(s)) {
		cout << "0";
		return 0;
	}
	int i1 = i;
	int j = 1;
	n = i / 2;
	while (n--) {
		h1 -= a[j].x * 2;
		h += a[i].x;
		i--;
		j++;
	}
	if (i1 % 2 != 0) {
		h += h1;
	}
	cout << h;
	fclose(stdin);
	fclose(stdout);
	return 0;
}