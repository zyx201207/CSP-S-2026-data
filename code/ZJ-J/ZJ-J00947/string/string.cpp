#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 10;
int a[N];
char c[N];
int n, ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> a[i] >> c[i];
	
	int l = 1, r = n;
	while(l < r){
		if(a[l] < a[r]){
			ans += (c[l] != c[r]) * a[l];
			a[r] -= a[l];
			l++;
		}
		else if(a[l] > a[r]){
			ans += (c[l] != c[r]) * a[r];
			a[l] -= a[r];
			r--;
		}
		else{
			ans += (c[l] != c[r]) * a[l];
			r--;
			l++;
		}
	}
	cout << ans;
	return 0;
}