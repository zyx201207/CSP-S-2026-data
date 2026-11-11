#include<iostream>
#include<iomanip>
#define ll long long
using namespace std;

ll c ,n , m ,d, q ,x;
/*
这题面有点神秘，好在没看出来OvO
年度CSP代码大赏
*/

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1; i<=m ; i++) cin >> x;
	for(int i=1;i<=n; i++) {
		cin >> x;
		ll f = x;
		for(int i=1; i<=2*f ; i++) cin >> x;
	}
	while( q-- ) {
		cin >> x >> x;
	}
	cout << "我写了个滚木"; 
	return 0;
}
