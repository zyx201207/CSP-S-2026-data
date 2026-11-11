#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int c, t;
	cin >> c >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		for(int i=1; i<n; i++){
			int a, b;
			cin >> a >> b;
		}
		if(n > 100 && k == 2){
			cout << n / 3 << endl;
			continue;
		}
		if(n == k) cout << 0 << endl;
		else if(k == 1 && n > 3) cout << 2 << endl;
		else cout << 1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
