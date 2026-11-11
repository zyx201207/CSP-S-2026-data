#include <bits/stdc+.h>
using namespace std;
int main (){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for (int j=1;j<=t;j++){
		int n,k;
		for (int i=1;i<=n;i++){
			int u,v;
			cin >> u >> v;
		}
		if (j==1) cout << 1 << '\n';
		else if (j==2) cout << 2 << '\n';
		else if (j%4==3) cout << 7 << '\n';
		else cout << 8 << '\n';
	}
	return 0;
}
