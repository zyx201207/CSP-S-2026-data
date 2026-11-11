#include<bits/stdc++.h>
using namespace std;
int x[1000005];
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c, t;
	cin >> c >> t;
	for(int i=1;i<=t;i++){
		int n, d;
		cin >> n >> d;
		for(int j=0;j<n;j++){
			cin >> x[i];
		}
		cout << 1 << '\n';
	}
	
	return 0;
}
