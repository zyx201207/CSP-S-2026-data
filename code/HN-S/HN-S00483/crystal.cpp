#include <bits/stdc++.h>;
using namespace std;

int n, m;
int a[500000] = 0;
void dfs(n, m, ){
	for (int i = 0; i <= n, i++){
		cin >> a[i];
	}
	int Cwei = a[(n + 1)/2-1];
	for (int i = 0; i <= n /2; i++){
		a[i] = n / 2;
		cout << (n + 1) / 2 + 1;
		
	}
	return 0;
}
int main(){
	
	freopen("crystal.in", "r",stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	dfs(n, m);
} 
