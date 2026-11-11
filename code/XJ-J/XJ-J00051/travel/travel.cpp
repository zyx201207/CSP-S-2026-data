#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	char r = b[2];
	char x = d[2];
	char e = b[1];
	char f = d[1];
	if(a == c){
		cout << "1";
		if(e == f){
			cout << "1";
			if(r == 'D'&& x=='C' || r == 'C'&&x=='D') cout << "00";
			else{
				cout << "1";
				if(abs(r-x) == 1){
					cout << "1";
				}
				else cout << "0";
			}
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
