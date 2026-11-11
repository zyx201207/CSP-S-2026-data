#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b;cin >> a >> b;
	for (int i=0;i<b;i++){
		int n,d,h[n];
		cin >> n >> d;
		for (int j=0;j<n;j++) cin >> h[j];
		if (h[d]-h[0]<=d) cout << n-d << endl;
		else cout << 0;
	}
	return 0;
} 
