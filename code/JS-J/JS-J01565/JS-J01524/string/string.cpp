#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5;

int a[N + 5];
char c[N + 5];

int n;
int ans;
string s1;

signed main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
		for (int j = 1; j <= a[i]; j++){
			s1 += c[i];
		}
	}
	
	int p = s1.size();
	for (int i = 0; i <= p / 2; i++){
		int x = 0 + i;
		int y = p - 1 - i;
		if(s1[x] != s1[y])
			ans++;
	}
	cout << ans;
	return 0;
}
