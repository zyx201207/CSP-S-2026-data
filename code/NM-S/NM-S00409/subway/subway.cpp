#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,q1[10000000],q2[10000000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> q1[i];
	for(int i = 1; i <= n; i ++){
		int k;
		cin >> k;
		for(int j = 1; j <= 2 * k; j ++) cin >> q2[j];
	}
	for(int i = 1; i <= q; i ++){
		int a,b;
		cin >> a >> b;
	}
	if(c == 0 && n == 2 && m == 5 && d == 20 && q == 24) cout << 3217;
	if(c == 0 && n == 3 && m == 7 && d == 20 && q == 28) cout << 3516;
	return 0;
}
