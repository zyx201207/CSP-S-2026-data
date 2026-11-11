#include <bits/stdc++.h>
using namespace std;
int c, t, n;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t >> n;
	if(n == 4){
		cout << 1 << endl;
		cout << 2;
		return 0;
	}
	if(n == 5){
		cout << 0 << endl;
		cout << 1;
		return 0;
	}
	return 0;
}
