#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e6;
ll n, rear, cnt, ans = 0x3f3f3f3f, numtot;
int ji, ou;
string s;
char c[N];

bool check(string s) {
	int l = (s.size() - 1) % 2 == 0 ? (s.size() - 1) / 2  : (s.size() - 1) / 2 + 1, r = s.size() - 1;
	string ss;
	int tempR = r;

	for (int i = l; i <= r; i++)

		ss[i] = s[tempR--];

	for (int i = 0; i <= r / 2 - 1; i++) {

		if (s[i] != ss[l])
			return false;
		l++;
	}

	return true;
}


int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;

	for (int i = 1; i <= n; i++) {

		ll aTemp;
		char cTemp;
		cin >> aTemp >> cTemp;
		numtot += aTemp;

		if (aTemp % 2 == 0)
			ou++;
		else
			ji++;

		for (int j = 1; j <= aTemp; j++)

			s += cTemp;
		cnt++, c[++rear] = cTemp;
	}

	if (check(s)) {
		printf("0");
		return 0;
	}

	else {
		if (ji == 0 || ou == 0)
			printf("%lld", numtot / cnt);

		if (numtot % 2 == cnt % 2)
			printf("%lld", numtot / cnt);
		else
			printf("%lld", numtot / cnt + 1);
	}


	return 0;
}
