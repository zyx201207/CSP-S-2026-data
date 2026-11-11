#include <bits/stdc++.h>
using namespace std;

struct name {
	long long cnt;
	char a;

};
string s;
name k[300000];
char ak[1000000000];

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> k[i].cnt >> k[i].a ;
		for (int j = 1; j <= k[i].cnt; j++) {
			ak[sum] = k[i].a;
			sum++;
		}
	}
//	cout << sum << " ";
//	for (int i = 0; i <= sum; i++)
//		cout << ak[i];
	long long flag = 0;
	for (int i = 0; i < sum; i++) {
		if (ak[i] != ak[sum - 1 - i])
			//	cout << ak[i] << " " << ak[sum - i] << " " << i;
			flag++;
	}
	if (flag == 0) {
		cout << 0;
		return 0;
	} else {
		cout << flag / 2;
		return 0;
	}








	return 0;
}