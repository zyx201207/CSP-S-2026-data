#include <bits/stdc++.h>
using namespace std;
long long A[1000100] , B[1000100] , C[1000100];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n , m , i , j , cnt = 0 , mx = 0 , x , flag = 1;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++) {
		cin >> A[i];
		if (i == 2) {
			x = A[i] - A[i - 1];
		}
		if (i > 2 && flag == 1) {
			if (A[i] - A[i - 1] != x) {
				flag = 0;
			}
		}
	}
	if (flag == 1) {
		long long l = 1 , r = n , mid;
		while (l <= r) {
			mid = (l + r) / 2;
			if ((1 + mid) * mid / 2 * x <= m) {
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		} 
		cout << mid;
		return 0;
	}
	sort(A + 1 , A + 1 + n);
	for (i = 1 ; i < n ; i++) {
		B[i] = A[i + 1] - A[i];
		A[i] = B[i];
	}
	for (i = 2 ; i < n ; i++) {
		cnt = 0;
		if (i % 2 == 0) {
			for (j = i ; j < n ; j++) {
				C[j] = A[j - 1] + B[j] * i;
				if (C[j] > m) {
					cnt++;
				}
				else {
					mx = max(mx , i);
				}
			}
		}
		else {
			for (j = i ; j < n ; j++) {
				A[j] = C[j - 1] + B[j] * i;
				if (A[j] > m) {
					cnt++;
				}
				else {
					mx = max(mx , i);
				}
			}
		}
		if (cnt == (n - i)) {
			break;
		}
	}
	cout << mx + 1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
