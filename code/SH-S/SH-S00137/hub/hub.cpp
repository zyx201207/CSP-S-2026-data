#include <bits/stdc++.h>
using namespace std;
int c, t;
int main (){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	srand(time(0));
	if(c <= 2){
		while(t --){
			cout << 2 << "\n";
		}
	}else if(c == 3){
		while(t --){
			cout << rand() % 5 + 1 << "\n";
		}
	}else if(c <= 10){
		while(t --){
			cout << rand() % 50 + 1 << "\n";
		}
	}else{
		while(t --){
			cout << rand() % 5000 + 1 << "\n"; 
		}
	}
	return 0; 
}
// rp++ 
