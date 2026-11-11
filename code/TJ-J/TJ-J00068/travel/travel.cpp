#include <bits/stdc++.h>
using namespace std;
string a,b,a1,b1;
int q,p;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> a1 >> b1;
	char q1 = b[2];
	char p1 = b1[2];
	q = (b[0]-'0')+(b[1]-'0');
	p = (b1[0]-'0')+(b1[1]-'0');
	if (a == a1) cout << "1";
	else {
		cout << "0000";
		return 0;
	}
	if (q == p) cout << "1";
	else {
		cout << "000";
		return 0;
	}
	if ((q1 <= 'C' && p1 <= 'C') || (q1 >= 'D' && p1 >= 'D')){
		cout << "1";
			if (abs(q1-p1) == 1) cout << "1";
		else{
			cout << "0";
			return 0;
		}
	}
	else {
		cout << "00";
		return 0;
	}

}

