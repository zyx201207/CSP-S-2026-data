#include <bits/stdc++.h>
using namespace std;

int erjinzhi(int a, int b) {
	int s1[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	int s2[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	int num[8] = {0, 0, 0, 0, 0, 0, 0, 0};
	int rt = 0;
	int pf;
	for (int i = 0; i < a; i ++) {
		s1[0] = s1[0] + 1;
		for (int j = 0; j < 8; j ++) {
			if (s1[j] == 2) {
				s1[j + 1] += 1;
				s1[j] = 0;
			}
		}
	}
	for (int i = 0; i < b; i ++) {
		s2[0] = s2[0] + 1;
		for (int j = 0; j < 8; j ++) {
			if (s2[j] == 2) {
				s2[j + 1] += 1;
				s2[j] = 0;
			}
		}
	}
	for (int i = 0; i < 8; i ++) {
		if (s1[i] == 1 && s1[i] == s2[i]) {
			num[i] = 1;
		}
	}
	for (int i = 0; i < 8; i ++) {
		pf = 1;
		for (int j = 0; j < i; j ++) {
			pf *= 2;
		}
		rt = num[i] * pf + rt;
	}
	return rt;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	int num = 0;
	int l[n];
	int save, s1, s2, s3, s4;
	for (int i = 0; i < n; i++) {
		cin >> l[i];
	}
	for (int i = 0; i < m - 1; i ++) {
		for (int a = 0; a < n; a ++) {
			for (int b = 0; b < n; b++) {
				if (i == 0) {
					save = l[a];
				}
				if (a != b && num <= erjinzhi(save, l[b]) && s2 != a && s4 != b) {
					num = erjinzhi(save, l[b]);
					save = num;
					s1 = a;
					s3 = b;
				}
			}
		}
	}
	cout << num;
	return 0;
}