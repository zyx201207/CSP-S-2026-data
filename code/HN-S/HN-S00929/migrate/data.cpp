#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	srand(time(0));
	
	int T = rand() % 5 + 1;
	cout << "0 " << T << "\n";
	while(T--){
		int n = rand() % 8 + 1, m = rand() % 10 + 1;
		cout << n << " " << m << "\n";
		for(int i = 1; i <= n; i++){
			int x = rand() % 15 + 1, f = rand() % 2;
			if(f) x = -x;
			cout << x << " ";
		}
		cout << "\n";	
	}
	
	
	return 0;
}
