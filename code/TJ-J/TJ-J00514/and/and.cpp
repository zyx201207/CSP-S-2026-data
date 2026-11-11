#include <bits/stdc++.h>
using namespace std;
int a[200005]/*, b[200005][2000005]*/;
int main(){
	
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m; 
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int b = 1;
	while(b){
		b = 0;
		for (int i = 0; i < n-1; i++){
			if (a[i] < a[i+1]){
				int k = a[i];
				a[i] = a[i+1];
				a[i+1] = k;
				b = 1;
			}
		}
	}
	cout << a[m-1];
	/*
	int n, m, x = 1;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; a[i] > 0; j++){
			b[i][j] = a[i]%2;
			a[i] /= 2;
			x = j;
		}
		//for (int j = 0; j <= x/2; j++){
		//	int y = b[i][j];
		//	b[i][j] = b[i][x-j];
		//	b[i][x-j] = y;
		//}
		b[i][x+1] = "2";
	}
	for (int i = 0; i < n-1; i++){
		
	}*/
	
	
	return 0;
}
