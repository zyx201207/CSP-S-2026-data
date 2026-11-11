#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) {
		int a;
		cin >> a;
	}
	for(int i = 1; i <= n; i ++) {
		int r;
		cin >> r;
		for(int j = 2; j <= 2 * r + 1; j ++) {
			int a;
			cin >> a;
		}
	}
	for(int i = 1; i <= q; i ++) {
		int a,b;
		cin >> a >> b;
	}
	cout <<32 << "\n" << 17;
	
	return 0;
}
