#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
long long a[N],t[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i]; 
	}
	sort(a+1,a+n+1);
	long long maxn = 0;
	for(int i = 1;i < n;i++){
		t[i] = a[i+1] - a[i];
		maxn += (a[n] - a[i]);
	}
	int ans = n;
	for(int i = n - 1;i >= 1;i--){
		if(maxn <= m){
			break;
		} 
		maxn = maxn - t[i] * i;
		cout << maxn << endl;
		ans--;
	}
	cout << ans;
	return 0;
}
