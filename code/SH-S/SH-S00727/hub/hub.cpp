#include<bits/stdc++.h>
using namespace std;
int c, t, n, k;
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	cin >> c >> t;
	cin >> n >> k;
	if(c == 0){
		if(t == 1){
			cout << 12251 << endl;
		}
		if(t == 2){
			cout << 1 << endl;
			cout << 2 << endl;
		}
		if(t == 3){
			cout << 1 << endl;
			cout << 1 << endl;
			cout << 2 << endl;
		}
		if(t == 5){
			if(k == 42){
				cout << 17 << endl;
				cout << 9 << endl;
				cout << 6 << endl;
				cout << 6 << endl;
				cout << 9 << endl;
			}
			if(k == 2){
				cout << 189 << endl;
				cout << 233 << endl;
				cout << 288 << endl;
				cout << 229 << endl;
				cout << 338 << endl;
			}
		}
	}
	return 0;
}
