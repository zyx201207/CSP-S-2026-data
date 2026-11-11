#include<bits/stdc++.h>
using namespace std;
int n, m, f, l;
int a[1145140];
int b[1145140];
bool v[1145140];
int jmc = -114514;
void dfs(int x, int q){
	if(q > m){
		int tyz = b[1];
	//	cout << b[1] << " ";
		for(int i = 2; i <= m; i++){
			 tyz &= b[i];
		//	 cout << b[i] << " ";
		}
		jmc = max(jmc, tyz);
	//	cout << endl;
	//	memset(b, 0x00, sizeof(b));
		return;
	}
	b[q] = a[x];
	for(int i = 1; i <= n; i++){
		if(v[i] == 0){
			v[i] = 1;
//			cout << i << " ";
			dfs(i, q + 1);	
			v[i] = 0;
		//	cout << v[i];
		//	cout << q << endl;
		}
	}
//	cout << 1;
	return;
}
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		
	}
	l = a[1];
	for(int i = 2; i <= n; i++){
		l &= a[i];
		
	}
	if(n == m){
		cout << l;
		return 0;
	}
	for(int i = 1; i <= n - m + 1; i++){
		v[i] = 1;
		dfs(i, 1);
		f = 0;
		memset(v, 0x00, sizeof(v));
	}
	cout << jmc;
	return 0;
} 

