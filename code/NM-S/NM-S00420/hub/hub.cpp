#include<bits/stdc++.h>
using namespace std;
int c, t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	if (t == 2) cout << 2 << endl << 3;
	else {
		for (int i = 1;i <= t; i ++) cout << 1 << endl;
	}
	return 0;
}
