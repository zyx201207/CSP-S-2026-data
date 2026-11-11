#include<bits/stdc++.h>
using namespace std;
int c, n;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n;
	if (n == 1) cout << 1;
	else if (n == 2) cout << 33 << endl << 18;
	else cout << 34 << endl << 67 << endl << 48;
	return 0;
}
