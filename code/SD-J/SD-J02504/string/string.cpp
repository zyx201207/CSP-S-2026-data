#include<bits/stdc++.h>

using namespace std;
using LL = long long;

const LL N = 1e5 + 5;
LL n, a[N], ans;
char c[N];

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> c[i];
	}
	LL l = 1, r = n;
	while(l < r){
		if(c[l] != c[r]){
			ans += min(a[l], a[r]);
		}
		if(a[l] > a[r]){
			a[l] -= a[r];
			r--;
		}
		else if (a[l] < a[r]){
			a[r] -= a[l];
			l++;
		}
		else{
			r--;
			l++;
		}
	}
	cout << ans;
	
	return 0;
}
