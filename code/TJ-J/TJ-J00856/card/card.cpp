#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500005];
int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w" , stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for (int i = 0; i < n; i++){
		int l[500005];
		int cnt = 0;
		for (int j = i; j < m; i++){
			l[j] = a[j];
			for (int k = 0; k < j; k++){
				if (l[j] == l[k]){
					for (int x = k + 1; x < j + 1; x++)  l[x] = 0;
				}
			}
			for (int k = 0; k < j; k++){
				if (l[j] == i)  cnt++;
			}
			cout << cnt;
		}
	}
	
	return 0;
}















































































//I'm very very very angry.
//I FUCK CCF. 
