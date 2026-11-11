#include<bits/stdc++.h>
#define pb push_back
#define zxh(x, y, z, qwq) for(int qwq = x; qwq <= y; qwq += z)
#define dxh(x, y, z, qwq) for(int qwq = x; qwq >= y; qwq -= z)
#define dgd(x) priority_queue<x, vector<x>, less<x>>
#define endl '\n'
#define int long long 
using namespace std;

const int MAXN = 2e5 + 10;
int n, m, a[MAXN], ans = 0;

bool cmp(int x, int y){
	return x > y;
}

signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	zxh(1, n, 1, i){
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, cmp);
	ans = a[1];
	int pos = 2;
	zxh(1, m - 1, 1, i){
		ans &= a[pos];
		pos++;
	}
//	zxh(1, n, 1, i) cout << a[i] << " ";
	cout << ans;
	return 0;
}

/*
这说啥了兄弟，给了 ，CCFnmsl 
*/
