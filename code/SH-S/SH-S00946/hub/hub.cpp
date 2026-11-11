#include <bits/stdc++.h>
using namespace std;
long long c, t, n, m;
struct node{
	long long x, y;
}a[200005];
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	while(t --){
		cin >> n >> m;
		for(int i = 1; i <= n; i ++){
			cin >> a[i].x >> a[i].y;	
		}
		if(m == 2) {
			cout << 1 << endl;
		} else {
			long long u = m / 2;
			long long v = m - u;
			cout << max(u, v) << endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
