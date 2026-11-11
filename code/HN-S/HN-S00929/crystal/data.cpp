#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in", "w", stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	srand(time(0));
	
	int n = rand() % 8 + 1, m = rand() % 15 + 1;
	cout << n << " " << m << "\n";
	for(int i = 1; i <= n; i++){
		int x = rand() % 10 + 1;
		cout << x << " ";
	}
	cout << "\n";
	
	return 0;
}
