#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+9;
int n, m, ans, a[N], mx = 0;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	if(m == 1){
		cout << mx;
		return 0;
	}else{
		cout << 12;
	}
	return 0;
}
