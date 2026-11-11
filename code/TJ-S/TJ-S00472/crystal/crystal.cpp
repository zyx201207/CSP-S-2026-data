#include<bits/stdc++.h>
using namespace std;

long long n,a[500005],m,ans,s[500005];

int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n);
	for(int i = 1; i <= n; ++i) {
		s[i] = s[i - 1] + (i - 1) * (a[i] - a[i - 1]);
	}
	int i = 1,j = 1;
	while(j <= i && i <= n) {
		if(i != j && s[i] - s[j] - (j - 1) * (a[i] - a[j]) > m) ++j;
		if(ans < i - j + 1) ans = i - j + 1;
		++i;
	}
	cout << ans;
	
}
