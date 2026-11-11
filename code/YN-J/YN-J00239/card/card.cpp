#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N], s[N], lst[M], lst1[M];

int qs() {
	int k = 0;
	for (int i = 1; i; i++) {
		if (s[i] == 0)
			break;
		else
			k++;
	}
	return k;
}

bool find1(int num) {
	int k = qs();
	for (int i = 1; i <= k; i++) {
		if (s[i] == num) {
			return 1;
		}
	}
	return 0;
}

void find2() {
	int sum = 0;
	int k = qs();
	for (int i = 1; i <= k; i++) {
		lst1[s[i]] = 1;
	}
	return ;
}



int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int j = 1; j <= n; j++) {
		for (int i = j; i <= n; i++) {
			if (!find1(a[i])) { /*Ã»ÕÒµ½*/
				s[qs() + 1] = a[i];
			} else {
				for (int k = 1; k <= qs(); k++) {
					s[i] = 0;
				}
				s[1] = i;
			}
		}
		find2();
		for (int i = 1; i <= m; i++) {
			lst[i] += lst1[i];
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << lst[i] << " ";
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
