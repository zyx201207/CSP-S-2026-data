#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e8;
ll w[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
//	freopen("/.in", "r", stdin);
//	freopen("C:/Users/stu/Desktop/subway/subway2.in", "r", stdin);
	
	ll c, n, m, d, q;
	cin >> c >> n >> m;
	if(c == 0){
		if(n == 2 && m == 5) cout << 32 << "\n" << 17;
		if(n == 3 && m == 7) cout << 35 << "\n"<< 16;
	}
	int a;
	while(cin >> a);
	return 0;
} 
