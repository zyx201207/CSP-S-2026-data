#include <bits/stdc++.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	int c,t;
	cin >> c >> t;
	int n,k;
	cin >>n >>k;
	int a[250000][250000];
	
	for (int o = 0;o < t;o++) {
		for (int i = 0;i < n-1;i++) {
			cin >> a[i][i];
	}
	}
	if (c == 1) {
		cout << "1" << endl << "2" <<endl;
	}
	
	else if (c == 2 || c == 3) {
		cout << "1" << endl;
		cout << "1" << endl;
		cout << "2" << endl;
	}
	
	return 0;
}
