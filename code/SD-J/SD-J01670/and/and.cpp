#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m; cin >> n >> m;long long s,m2 = 0,a[200010],x = -1,y = 0; 
	while (n--){
		cin >> s;
		for (int i = 30;i >= 0;i--){
			m2 = m2 * 10 + ((s << i) & 1);
		}
		++x;
		a[x] = m2;
		m2 = 0;
	}
	sort (a,a + x + 1);
	for (int i = x;i > x - 2;i--){
		y += a[i];
	}  
	cout << y;
	return 0;
}

