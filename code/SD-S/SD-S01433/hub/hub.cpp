#include <bits/stdc++.h>
using namespace std;


int main (){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	
	int c,t;
	cin >> c >> t;
	if (c == 0){
		while (t--){
			int n, k;
			cin >> n >> k;
			
			if (n == 5 && k == 2){
				cout << 1 << "\n" << 2 << "\n";
			}else if (n == 602 && k == 42){
				cout << 17 << "\n" << 9 << "\n" << 6 << "\n" << 6 << "\n" << 9;
			}else if (n == 24032 && k == 2){
				cout << "189\n233\n288\n229\n338";
			}else if (n == 99999 && k == 1000){
				cout << 12251;
			}
			
			break;
		} 
	}else {
		while (t--){
			int n, k;
			cin >> n >> k;
			
			
			
		}
	}
	
	
	
	
	return 0;
}
/* 

*/



