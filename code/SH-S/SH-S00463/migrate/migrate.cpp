#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+5;
int n,m,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int p,q;
	cin >> p >> q;
	while(q--){
		cin >> n >> m;
		for(int i = 1;i<=n;i++){
			cin >> a[i];
		}
		int y =a[2]-a[1];
		if(2*y>m){
			cout << 0 << endl;
			continue;
		}else{
			cout << n/3 << endl;
		}
	}
	return 0;
}
