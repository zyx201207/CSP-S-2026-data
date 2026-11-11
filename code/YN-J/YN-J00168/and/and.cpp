#include <bits/stdc++.h>
using namespace std;

int n, m;

struct node1 {
	string a;
} s[200005];

struct node2 {
	string b;
} dp[200005];

char yu(string y) {
	return y[sizeof y] - '0' % 2;
}

string chu(string y) {
	int yu = 0;
	string x;
	for (int i = 0; i < sizeof x; i++) {
		if ((y[i] + yu - '0') % 2 == 1)
			yu = 1;
		else
			yu = 0;
		x += (char)(y[i] + yu - '0') / 2;
	}
	return x;
}

string fl(string x) {
	string s;
	while (sizeof x != 0) {
		s += yu(x);
		x = chu(x);
	}
	return s;
}

string cheng(string x) {
	string s;
	int jy = 0;
	for (int i = 0; i < sizeof x; i++) {
		s += (char)((x[i]  + jy - '0' ) * 2) % 10;
		jy = ((x[i]  + jy - '0' ) * 2) / 10;
	}
	return s;
}

string And(string a, string b) {
	a = fl(a);
	b = fl(b);
	string s;
	int ss = min(sizeof a, sizeof b);
	for (int i = 0; i <= ss; i++) {
		if (a[i] == b[i])
			s[i] += '1';
		else
			s[i] += '0';
	}
	s = cheng(s);
	for (int i = 0; i < ceil(ss / 2); i++) {
		if (s[i] != s[ss - i - 1])
			swap(s[i], s[ss - i - 1]);
	}
	return s;
}

string Max(string a, string b) {
	if (sizeof a < sizeof b)
		return b;
	if (sizeof a > sizeof b)
		return a;
	else {
		int s = sizeof a;
		for (int i = 0; i < s; i++) {
			if (a[i] < b[i])
				return b;
			if (a[i] > b[i])
				return a;
		}
	}
	return a;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> s[i].a;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++)
			dp[i].b = Max(dp[i].b, And(dp[j - 1].b, s[i].a));
	}
	cout << dp[m].b << endl;
	return 0;
}