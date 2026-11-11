#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n;
bool flag = true,flag2 = true;
long long a[N],lenth = 0,mid,ans;
char c,c1[N];
string s;

int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n; i++) {
		cin >> a[i] >> c;
		c1[i] = c;
		lenth += a[i];
		for(int j = 1; j <= a[i]; j++) s += c;
	}
	for(int i = 2; i <= n; i++) {
		if(c1[i] != c1[i - 1]) flag = false;
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] != 1) flag2 = false;
	}
	if(flag == true) {
		cout << "0";
		return 0;
	}
	if(n == 1) {
		cout << "0";
		return 0;
	}
	if(n == 2) {
		cout << "1";
	}
	if(lenth % 2 == 1) {
		mid = (lenth + 1) / 2;
		ans = mid - 1;
		for(int i = 0; i < mid; i++) {
			for(int j = lenth - 1; j > mid; j--) {
				if(s[i] == s[j]) ans --;
			}
		}
	}
	else {
		mid = lenth / 2;
		long long q = mid - 1;
		ans = mid - 2;
		if(s[mid - 1] != s[mid - 2]) ans ++;
		for(int i = 0; i < mid - 1; i++) {
			for(int j = lenth - 1; j > mid; j--) {
				if(s[i] == s[j]) ans --;
			}
		}
	}
	cout << ans;
	return 0;
}
