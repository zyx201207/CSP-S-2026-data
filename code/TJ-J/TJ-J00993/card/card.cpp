#include<bits/stdc++.h>
using namespace std;

int n, m, p[500005], a[300005];


int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m;
	
	for(int i = 1; i <= n; i++){
		cin >> p[i];
	}
	
	
	for(int i = 1; i <= n; i++){
		a[p[i]] = i;
	}
	
	for(int i = 1; i <= m; i++){
		cout << a[i] << " ";
	}
	
	return 0;
}
