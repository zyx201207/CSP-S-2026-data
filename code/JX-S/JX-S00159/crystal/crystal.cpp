#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 500010,INF = 5000000000000000000;
int n,m;
int a[N],d[N],pre[N],suf[N];
void build(){
	for(int i = 1 ; i <= n ; i ++)
		d[i] = a[i] - a[i - 1];
	pre[1] = 0;
	for(int i = 2 ; i <= n ; i ++)
		pre[i] = pre[i - 1] + d[i] * (i - 1);
}
bool check(int x){
	if(x < 1 || x > n) return 0;
	if(x == 1) return 1;
	//cout << "check " << x << '\n';
	int op_mi = INF;
	for(int L = 1 ; (L + x - 1) <= n ; L ++){
		int R = L + x - 1;
		//cout << "L=" << L << "  R=" << R << '\n';
		int dis;
		dis = pre[R] - pre[L] - (L - 1) * (a[R] - a[L]);
		//cout << "dis=" << dis << "\n\n";
		op_mi = min(op_mi,dis);
	}
	return (op_mi <= m);
}
void t(){
	//cout << "n=" << n << "; Here is the array 'a' after sorting:\n";
	//for(int i = 1 ; i <= n ; i ++) cout << a[i] << ' ';
	//cout << "\n\nHere is the array 'd':\n";
	//for(int i = 1 ; i <= n ; i ++) cout << d[i] << ' ';
	//cout << "\n\nHere is the array 'pre':\n";
	//for(int i = 1 ; i <= n ; i ++) cout << pre[i] << ' ';
	//cout << "\n\nThen solve ans.\n";
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1 ; i <= n ; i ++)
		cin >> a[i];
	sort(a + 1,a + n + 1);
	build();
	//t();
	int l = 0,r = n + 1;
	while(l + 1 != r){
		int mid = (l + r) / 2;
		if(check(mid)) l = mid;
		else r = mid;
	}
	cout << l;
	return 0;
}
//RP ++
//Luogu @zzhengxi
