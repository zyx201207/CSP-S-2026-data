#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,t,y = -1; char x; cin >> n;string a;
	while (n--){
		cin >> t >> x;
		for (int i = 0;i < t;i++){
			++y;
			a[y] = x; 
		}
	}
	long long s = (y + 1) / 2,m = y;
	for (int i = 0;i < (y + 1) / 2;i++){
		if (a[i] == a[m]) s--;
		m--;		
	}
	cout << s;
	return 0;
}
