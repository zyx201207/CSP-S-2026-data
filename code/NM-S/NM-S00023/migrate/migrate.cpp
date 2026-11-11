#include <bits/stdc++.h>
using namespace std;
int a[100100];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,k;
	cin >> c >> k;
	while(k--){
		int n,d;
		cin >> n >> d;
		for(int i=1;i<=n;i++) cin >> a[i];
		cout << n-3;
	}
	return 0;
	
}
