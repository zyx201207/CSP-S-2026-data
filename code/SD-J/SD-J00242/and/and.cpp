#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, asn, a[200005];
void dfs(int nd, int cd, int v){
	if(nd == n){
		if(cd == m) asn = max(asn, v);
		return;
	}
	dfs(nd + 1, cd + 1, v & a[nd + 1]);
	dfs(nd + 1, cd, v);
}
void me1(){
	for(int i = 1; i <= n; i++) asn = max(asn, a[i]);
	cout << asn;
}
void me2(){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i != j) asn = max(asn, a[i] & a[j]);
	cout << asn;
}
void men(){
	asn = a[1];
	for(int i = 1; i <= n; i++) asn &= a[i];
	cout << asn;
}
void wh(){
	sort(a + 1, a + n + 1, greater<int>());
	asn = a[1];
	for(int i = 1; i <= m; i++) asn &= a[i];
	cout << asn;
}
signed main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m; bool flag1 = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i] >= 4) flag1 = 0;
	}
	if(m == 1) me1();
	else if(m == 2) me2();
	else if(m == n) men();
	else if(flag1) wh();
	else if(n <= 20){
		dfs(1, 0, 0);
		dfs(1, 1, a[1]);
		cout << asn;
	}
	return 0;
}
/*
我是打烷 luogu 1638033(uid) or AlkaneCompiiler_(用户名，将来会更换为______) 

天苍苍！野茫茫！风吹草低见牛羊！
争渡！争渡！惊起一滩鸥鹭！
日！月！之！行！若！出！其！中！
星！汉！灿！烂！若！出！其！里！
*/
