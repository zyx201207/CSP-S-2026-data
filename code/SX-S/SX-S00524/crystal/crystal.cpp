#include <bits/stdc++.h>
using namespace std;
long long num[500005];
long long num2[500005];
bool de[500005];
int cnt[500005];
int shuzi[500005];
int absnum[500005];
int j = 0;
int j2 = 1;
int cnt2 = 0;
int mmax, index1;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n = 0;
	long long m = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> num[i];
		num2[i] = num[i];
	}
	sort(num + 1, num + n + 1);

	for (int i = 1; i <= n; i++) {
		if (num[i] == num[i + 1]) {
			de[i + 1] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (de[i] == 1) {
			cnt[j] += 1;
		} else {
			j++;
			cnt[j]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (de[i] == 0) {
			shuzi[j2] = num[i];
			j2++;
		}
	}


	mmax = cnt[1];
	index1 = 1;
	for (int i = 1; i <= n; i++) {
		if (cnt[i + 1] > cnt[i]) {
			mmax = cnt[i + 1];
			index1 = i + 1;
		}
	}

	if (mmax == 1) {
		sort(num2 + 1, num2 + n + 1);
		for (int i = 1; i <= n; i++) {
			absnum[i] = abs(num2[n / 2] - num2[i]);
		}
		sort(absnum + 1, absnum + n + 1);
	} else {
		for (int i = 1; i <= n; i++) {
			absnum[i] = abs(shuzi[index1] - num2[i]);
		}
		sort(absnum + 1, absnum + n + 1);
	}




	for (int i = 1; i <= n; i++) {
		m -= absnum[i];
		absnum[i] = 0;
		cnt2++;
		if (m <= 0) {
			break;
		}
	}
	if (m == 0) {
		cout << cnt2;
	} else {
		cout << cnt2 - 1;
	}









	return 0;
	fclose(stdin);
	fclose(stdout);
}


