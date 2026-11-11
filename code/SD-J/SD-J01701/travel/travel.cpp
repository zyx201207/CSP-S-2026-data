#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b;
	string a1, b1;
	cin >> a >> a1 >> b >> b1;
	if(a != b)
		cout << "0000" << endl;
	else{
		cout << 1;
		int suma = 0, sumb = 0;
		suma = a1[0] - '0' + a1[1] -'0';
		sumb = b1[0] - '0' + b1[1] -'0';
		if(suma != sumb)
			cout << "000";
		else{
			cout << 1;
			char ta, tb;
			ta = a1[2];
			tb = b1[2];
			if((ta <= 'C' && tb <= 'C') || (ta > 'C' && tb > 'C')){
				cout << 1;
				if((ta > 'C' && tb > 'C') || (ta == 'B' || tb == 'B'))
					cout << 1;
				else
					cout << 0;
			}
			else
				cout << "00";
		}
	}
 	return 0;
}

