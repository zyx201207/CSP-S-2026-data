#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N], sum, ans, n, x, y;
char b[N];
int main(){
	freopen("string.in", "w", stdin);
	freopen("string.out", "r", stdout);
	cin >> n;
	string d;
	for(int i = 1;i <= n;i++){
		cin >> a[i] >> b[i];
		sum += a[i];
	}
	int i = 1;
	int j = n;
	while(2 * x < sum){
		y = min(a[i], a[j]);
		x += y;
		if(b[i] != b[j]) ans += y;
		a[i] -= y;
		a[j] -= y;
		if(a[i] == 0) i++;
		if(a[j] == 0) j--;
	}
	cout << ans;
	return 0;
}
