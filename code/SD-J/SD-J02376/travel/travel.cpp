#include<bits/stdc++.h>

using namespace std;

string a, b, c, d;

int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a >> b >> c >> d;
	if(a == c){
		cout << 1;
		if((b[0] - '0') * 10 + b[1] - '0' == (d[0] - '0') * 10 + d[1] - '0'){
			cout << 1;
			if((b[2] == 'A' && d[2] == 'B') || (b[2] == 'B' && d[2] == 'A') || (b[2] == 'A' && d[2] == 'C') || (b[2] == 'C' && d[2] == 'A') || (b[2] == 'B' && d[2] == 'C') || (b[2] == 'C' && d[2] == 'B')|| (b[2] == 'D' && d[2] == 'E')|| (b[2] == 'E' && d[2] == 'D')){
				cout << 1;
				if(abs(b[2] - d[2]) == 1){
					cout << 1;
				}
				else{
					cout << 0;
				}
			}
			else{
				cout << "00";
			}
		}
		else{
			cout << "000";
		}
	}
	else{
		cout << "0000";
	}
	return 0;
} 
