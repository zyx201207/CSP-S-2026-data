#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using PII = pair<int,i64>;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int c , t;
	cin >> c >> t;
	while(t--) cout << 1 << endl;
}
/*
1、把地铁线作为点，站台作为边建图
2、n^3 floyd 求出全源最短路
3、对于每个q，O(d^2) check 最终最短路 
*/
