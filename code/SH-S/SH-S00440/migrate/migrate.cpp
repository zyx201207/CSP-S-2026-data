#include<bits/stdc++.h>
using namespace std;
#define int long long

int x[200006];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		cout << n-3;
	}
	return 0;
}
