#include <bits/stdc++.h> 
using namespace std;

int main(){
	freopen("hub.in", "r",stdin);
	freopen("hub.out", "w", stdout);
	
	int c;
	int t;
	
	cin >> c >> t;
	
	for(int i = 1; i <= t; i ++){
		int n;
		int k;
		cin >> n >> k;
		
		for(int i = 1; i <= n-1; i++){
			int a;
			int b;
			cin >> a >> b;
		}
		cout << (int)((n-k)/ 4)+1 << endl; 
	}
	return 0;
}
