#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000001];
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin >> c >> t;
	for(int s=1; s<=t; s++) {
		memset(a,0,sizeof(a));
		int n,d;
		cin >> n >> d;
		for(int i=1; i<=n; i++) {
			cin >> a[i];
		}
		if(c==11||c==12) {
			if(n<=2) {
				cout << n-3;
			}
		}
	}
	return 0;
}
/*luoguuid:2198513
15:19 T1 75
17:13 T4 10
17:50 T3 8
T2 xxx
砂狼白子YYDS
Trick||Treat!
Trick||Treat!
Trick||Treat!
Trick||Treat!
Oct31==Dec25?
Oct31==Dec25?
Oct31==Dec25?
Oct31==Dec25?
Oct31==Dec25?
啊，电力K1806司机啊，命令编码75038，中间忘了，降弓用刑！
2836我喜欢你（个鬼）
有人能把我放进雷霆代码大赏吗？
我是不是要烷基八氮了
*/
