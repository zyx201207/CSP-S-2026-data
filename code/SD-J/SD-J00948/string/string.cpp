#include <bits/stdc++.h>
using namespace std;
int n;
long long arr[200005];
char ch[200005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	long long s = 0;
	for(int i = 0; i < n; i++) {
		cin >> arr[i] >> ch[i];
	}
	long long sum = 0;
	long long l = 0, r = n - 1;
	while(l < r) {
		if(ch[l] == ch[r]) {
			if(arr[l] > arr[r]) {
				arr[l] -= arr[r];
				r--;
			} else if(arr[l] < arr[r]){
				arr[r] -= arr[l];
				l++;
			} else {
				l++, r--;
			}
		} else {
			sum += min(arr[l], arr[r]);
			if(arr[l] > arr[r]) {
				arr[l] -= arr[r];
				r--;
			} else if(arr[l] < arr[r]){
				arr[r] -= arr[l];
				l++;
			} else {
				l++, r--;
			}
		}
	}
	
	cout << sum;
	return 0;
}
