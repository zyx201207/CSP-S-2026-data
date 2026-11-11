#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

int num[N];
char letter[N];
long long ans = 0;
int n;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> num[i] >> letter[i];
	}
	int l = 1, r = n;
	while(l < r) {
		int bowl = abs(num[l] - num[r]);
		int sizel = num[l], sizer = num[r];
		if(num[l] > num[r]) {
			num[l] = bowl;
			r--;
			if(letter[l] == letter[r+1]) continue;
			ans += sizer;

		}
		else if(num[l] == num[r]) {
			l++, r--;
			if(letter[l-1] == letter[r+1]) continue;
			ans += sizel;
		}
		else {
			num[r] = bowl;
			l++;
			if(letter[l-1] == letter[r]) continue;
			ans += sizel;
		}
	}
	cout << ans;
	return 0;
}