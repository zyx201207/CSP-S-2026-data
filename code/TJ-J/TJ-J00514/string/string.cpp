#include <bits/stdc++.h>
using namespace std;
int main() {
	
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n, a, num = 0;
	string b, sum;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a >> b;
		for (int j = 0; j < a; j++){
			sum += b;
		}
	}
	for (int i = 0; i < sum.size()/2; i++){
		if (sum[i] != sum[sum.size()-i-1]){
			num++;
		}
	}
	cout << num;
	
	return 0;
} 
