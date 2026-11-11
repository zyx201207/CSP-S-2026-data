#include<bits/stdc++.h>
using namespace std;
string xa , xb , ya , yb;
int main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> xa >> xb >> ya >> yb;
	if(xa == ya){
		cout << '1';
		if(xb[0] == yb[0] && xb[1] == yb[1]){
			cout << '1';
			if((xb[2] <= 'C' && yb[2] <= 'C') || (xb[2] > 'C' && xb[2] <= 'F' && yb[2] > 'C' && yb[2] < 'F')){
				cout << '1';
				if(xb[2] - yb[2] == 1 || xb[2] - yb[2] == -1) cout << '1';
				else cout << '0';
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
