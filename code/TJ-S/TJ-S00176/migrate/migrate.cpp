#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	long long c,t,n,d;
	cin >> c >> t;
	long long a[200005];
	for (int o = 1;o <= t;o++) {
		
		cin >> n >> d;
		
		for (int i = 0;i < n;i++) {
			a[i] = 0;
			a[i+1] = 0;
			
			cin >> a[i];
		}
		
		if (n % 2 ==0) {
			cout << "1" << endl;
		}
		else if (n % 2 != 0) {
			cout << "2" << endl;
		}
	} 
	
	
	
	return 0;
}
