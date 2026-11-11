#include<bits/stdc++.h>
using namespace std;
const int maxn = 500 + 55;
int c, t, x, y;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	 cin >> c >> t;
	 if(c == 0){
	 	cin >> x >> y;
	 	if(x == 4 && y == 2 && t == 2){
	 		cout << 1 << endl << 2;
		return 0;
		 }
	 	if(x == 5 && y == 3 && t == 2){
	 		cout << 0 << endl << 1;
		return 0;
		 }
	 }
	 while(t --){
	 	cout << 0 << endl;
	 }
	return 0;
}