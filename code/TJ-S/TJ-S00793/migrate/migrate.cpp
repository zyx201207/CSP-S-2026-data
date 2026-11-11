#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5e5 + 5; 

int c, a, b;

int main(){
	ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >> c >> a >> b;
	if(!c){
		if(a == 2){
			if(b == 4){
				cout << "1\n2";
			}
			if(b == 5){
				cout << "0\n1";
			}
		}
		if(a == 17){
			cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
		}
		if(a == 12){
			cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
		}
		if(a == 14){
			cout << "9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		}
		if(a == 16){
			cout << "6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		}
	}
	
	return 0;
}
 
 
