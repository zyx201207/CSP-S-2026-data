#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans;
int n;
string c[200005];
int a[200005];
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)	
		cin >> a[i] >> c[i];
	int l = 1, r = n;
	while(l < r)
	{
		int mi = min(a[l], a[r]);
		if(c[l] != c[r])	
			ans += mi;
		a[l] -= mi;
		a[r] -= mi;
		if(a[l] == 0)
			l++;
		if(a[r] == 0)
			r--;
	}	
	printf("%lld\n", ans);
	return 0;
} 
