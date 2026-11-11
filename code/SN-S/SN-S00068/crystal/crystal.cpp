#include <bits/stdc++.h>
using namespace std; 

const long long MAXN = 5e5 + 5;
int n, l, r;
long long m, mm, ans = -LONG_LONG_MAX, l_ans, cha;
bool B = 1;
struct node {
	long long cost, val;
}a[MAXN];

bool cmp(node x, node y){return x.cost < y.cost;}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i].cost;
	sort (a + 1, a + n + 1, cmp);
	//B
	cha = a[2].cost - a[1].cost;
	for (int i = 2; i <= n - 1; i++){
		if (a[i + 1].cost - a[i].cost != cha){
			B = 0;
			break;
		}
	}
	if (B){
		ans = 0;
		for (int j = 1; j <= n; j++){
			a[j].val = a[n].cost - a[j].cost;
		}
		for (int j = n; j >= 1; j--){
			if (m >= a[j].val) m -= a[j].val, ans++;
			else break;
		}
		cout << ans;
		return 0;
	}
	//
	
	for (int i = 1; i <= n; i++){
		mm = m; l_ans = 0;
		for (int j = 1; j <= i; j++){
			a[j].val = a[i].cost - a[j].cost;
		}
		for (int j = i; j >= 1; j--){
			if (mm >= a[j].val) mm -= a[j].val, l_ans++;
			else break;
		}
		ans = max(ans, l_ans);
	}
	cout << ans;
	return 0; 
}// 5 8 -3 -1 2 2 7
