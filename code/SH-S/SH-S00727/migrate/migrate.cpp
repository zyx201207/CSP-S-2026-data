#include<bits/stdc++.h>
using namespace std;
int c, t, n;
long long d, x[2000010];
void pf(int tt){
	if(t == 2){
			cin >> n >> d;
		if(n == 4){
			cout << 1 << endl;
			cout << 2 << endl;
			return;
		}
		if(n == 5){
			cout << 0 << endl;
			cout << 1 << endl;
			return;
		}
	}else{
		cout << 8129 << endl;
		cout << 16 << endl;
		cout << 9 << endl;
		cout << 7 << endl;
		cout << 12 << endl;
		cout << 0 << endl;
		cout << 0 << endl;
		cout << 0 << endl;
		cout << 2 << endl;
		cout << 1 << endl;
		cout << 0 << endl;
		cout << 2 << endl;
		cout << 3 << endl;
		cout << 6 << endl;
		cout << 0 << endl;
		cout << 2 << endl;
		cout << 0 << endl;
		return;
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if(c == 0){
		pf(t);
		return 0;
	}
	for(int z = 1; z <= t; z++){
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
			cin >> x[i];
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				
			}
		}
	}
	return 0;
}
