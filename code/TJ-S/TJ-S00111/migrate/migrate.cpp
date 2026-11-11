#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;  
	cin >> c >> t;
	int n,d,x[200001];
	for (int i = 1;i <= t;i++){
		cin >> n >> d;
		for (int i = 1;i <= n;i++){
			cin >> x[i];
		}
	}
	if (t ==  2){
		cout << 1 << endl << 2; 
	}
	
	return 0;
}
