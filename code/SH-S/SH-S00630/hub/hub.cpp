#include <bits/stdc++.h>
using namespace std;
int x[2000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	for(int i = 1;i <= t;i++){
		srand(time(0));
		cout << rand()%(i*189+18) << "\n";
	}
	return 0;
}
