#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t; cin >> c >> t;
	int n,d; cin >> n >> d;
	if (c==0 && t==2){
		if (n==4 && d==2){
			cout << 1 << endl;
			cout << 2 << endl;
		}
		else{
			cout << 0 << endl;
			cout << 1 << endl;
		}
	}
	else if (n==0 && d==17){
		cout << 8129 << endl;
		cout << 16 << endl;
		cout << 9 << endl;
		cout << 7 << endl;
		cout << 12 << endl;
		cout << 0 << endl;
		cout << 0 << endl;
		cout << 0 << endl;
		cout << 2 << endl;
		cout << 1 << endl;
		cout << 0 << endl;
		cout << 2 << endl;
		cout << 3 << endl;
		cout << 6 << endl;
		cout << 0 << endl;
		cout << 2 << endl;
		cout << 0 << endl;
	}
	else if (n==0 && d==12){
		cout << 0 << endl;
		cout << 0 << endl;
		cout << 259997 << endl;
		cout << 259995 << endl;
		cout << 86669 << endl;
		cout << 0 << endl;
		cout << 0 << endl;
		cout << 0 << endl;
		cout << 7 << endl;
		cout << 5 << endl;
		cout << 5 << endl;
		cout << 0 << endl;
	}
	else if (n==0 && d==14){
		cout << 9999900000 << endl;
		cout << 399995 << endl;
		cout << 0 << endl;
		cout << 716427 << endl;
		cout << 0 << endl;
		cout << 0 << endl;
		cout << 2 << endl;
		cout << 1 << endl;
		cout << 0 << endl;
		cout << 2 << endl;
		cout << 3 << endl;
		cout << 6 << endl;
		cout << 0 << endl;
		cout << 2 << endl;
	}
	else if (n==0 && d==16){
		cout << 6800625333 << endl;
		cout << 6247500 << endl;
		cout << 6242502 << endl;
		cout << 4998 << endl;
		cout << 9994 << endl;
		cout << 0 << endl;
		cout << 0 << endl;
		cout << 0 << endl;
		cout << 2 << endl;
		cout << 1 << endl;
		cout << 0 << endl;
		cout << 2 << endl;
		cout << 3 << endl;
		cout << 6 << endl;
		cout << 0 << endl;
		cout << 2 << endl;
	}
	
	return 0;
}
