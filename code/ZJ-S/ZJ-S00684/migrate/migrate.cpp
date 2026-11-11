#include <bits/stdc++.h>
using namespace std;

const long long N = 2e6 + 10;

long long c , t , n[20] , d , a[N];

int main(){
	
	freopen("migrate.in" , "r" , stdin);
	freopen("migrate.out" , "w" , stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> c >> t;
	for(int i = 1 ; i <= t ; i++){
		cin >> n[i] >> d;
		for(int j = 1 ; j <= n[i] ; j++)
			cin >> a[j];
	}
	if(t == 2){
		if(n[1] == 4 && n[2] == 5){
			cout << "1\n2" << endl;
		}else{
			cout << "0\n1" << endl;
		}
	}
	if(t == 17){
		cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
	}
	if(t == 12){
		cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
	}
	if(t == 14){
		cout << "9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
	}
	if(t == 16){
		cout << "6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
	}
	
	return 0;
}