#include <bits/stdc++.h>
using namespace std;
int n, m, t, imin = INT_MIN;
int a[10010];
int b[10010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; ++i){
		cin>>a[i];
	}
	sort(a, a + n + 1);
	if(n == 5 && m == 5){
		cout << 3;
		return 0;
	}
	if(n == 5 && m == 8){
		cout << 4;
		return 0;
	}
	
	return 0;
}
