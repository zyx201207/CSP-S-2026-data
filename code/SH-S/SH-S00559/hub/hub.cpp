#include <iostream>
#include <cstring> 
using namespace std;
int c, t;
int n, k, u, v;
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	cin >> c >> t;
	for (int i = 1; i <= t; i++){
		cin >> n >> k;
		for (int i = 1; i <= n - 1; i++){
			cin >> u >> v;
		}
		cout << i << endl;
	}
	return 0;
} 
