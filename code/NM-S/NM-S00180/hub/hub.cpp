#include <bits/stdc++.h>

using namespace std;

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	if (t == 2) cout << 1 << endl << 2;
	else {
		for (int i = 1;i <= t;i++){
			cout << (c % 2) << endl;
		}
	}
	return 0;
}
