#include <bits/stdc++.h>
using namespace std;
int x[200009];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		for(int i=0; i<n; i++){
			cin >> x[i];
		}
		cout << x[n-1] / d - 1 << endl;
	}
	return 0;
}

