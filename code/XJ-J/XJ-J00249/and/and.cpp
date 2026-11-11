#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int N = 2e5 + 5;
int n, m, l;
struct node{
	int a, s;
	int f[35];
}q[N];
bool cmp(node x, node y){
	return x.a < y.a;
}
signed main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	freopen ("and.in", "r", stdin);
	freopen ("and.out", "w", stdout);
	cin >> n>> m;
	for (int i = 1; i <= n; i ++){
		cin >> q[i].a;
		int tot = q[i].a, x = 0;
		while (tot != 0){
			q[i].f[++ x] = tot % 2;
			tot /= 2;
		}
		q[i].s = x;
	}
		
	sort (q + 1, q + 1 + n, cmp);
	for (int i = n; i > 1; i --){
		if (q[i].s == q[i - 1].s){
			l = i;
			break;
		}
	}
	if (l == 0 || l - m + 1 <= 0) cout << 0;
	else cout << q[l - m + 1].a;
return 0;
}
