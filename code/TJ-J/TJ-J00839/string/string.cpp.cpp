#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans = 0,l = 1,r = 1;
	cin >> n;
	int lx = 1,rx = n;
	int a[n];
	string c[n];
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	while(lx < rx){
		if(l > a[lx]){
			lx++;
			l -= a[lx];
		}
		if(r > a[rx]){
			rx--;
			r -= a[rx];
		}
		if(c[lx] != c[rx]){
			ans++;
		}
		l++;
		r++;
	}
	cout << ans;
	return 0;
}

