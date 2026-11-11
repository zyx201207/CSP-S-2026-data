#include<bits/stdc++.h>
using namespace std;
int c, t, n, d;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i = 1; i <= n; i++){
			cin >> a[i];
		}
		cout << d-n-1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
