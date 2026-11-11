#include <bits/stdc++.h>
using namespace std;
long long n, len = 0, ans;
string b;
long long a[100000001];

int main() {
	cin >> n;
	char c;
	
	for (int i = 0; i < n; i++) {
		
		cin >> a[i] >> c;
		
		b = b + c;
	}
	
	for (long long i = 0, j = n - 1; i < j;) {
		
//		cout << a[i] << b[i] << " " << a[j] << b[j] << "\n";
		
		if (b[i] != b[j]) {
			if (a[i] > a[j]) {
				ans = ans + a[j];
				a[i] = a[i] - a[j];
				j--;
				
//				cout << ">";
			} else if (a[i] < a[j]) {
				ans += a[i];
				a[j] = a[j] - a[i];
				i++;
				
//				cout << "<";
			} else {
				ans += a[j];
				i++;
				j--;
//				cout << "=";
			}
		} else {
			if (a[i] > a[j]) {
				a[i] = a[i] - a[j];
				j--;
				
			} else if (a[i] < a[j]) {
				a[j] = a[j] - a[i];
				i++;
				
				
			} else {
				i++;
				j--;
				
			}
		}
	}
	
	cout << ans;
	return 0;
}
