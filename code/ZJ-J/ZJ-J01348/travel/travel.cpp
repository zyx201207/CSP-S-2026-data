#include<bits/stdc++.h>
using namespace std;

string a,b,c,d;
bool flag = 0;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> a >> b >> c >> d;
	if(a == c){
		cout << '1';
		flag = 1;
	}
	else{
		cout << "0000";
		return 0;
	}
	if(flag){
		if(b[0] == d[0]){
			if(b[1] == d[1]){
				cout << '1';
			}
			else{
				cout << "000";
				return 0;
			}
		}
		else{
			cout << "000";
			return 0;
		}
		if(b[2] == 'A' && d[2] == 'B') cout << "11";
		if(b[2] == 'A' && d[2] == 'C') cout << "10";
		if(b[2] == 'A' && d[2] == 'D') cout << "00";
		if(b[2] == 'A' && d[2] == 'F') cout << "00";
		if(b[2] == 'B' && d[2] == 'C') cout << "11";
		if(b[2] == 'B' && d[2] == 'A') cout << "11";
		if(b[2] == 'B' && d[2] == 'D') cout << "00";
		if(b[2] == 'B' && d[2] == 'F') cout << "00";
		if(b[2] == 'C' && d[2] == 'A') cout << "10";
		if(b[2] == 'C' && d[2] == 'B') cout << "11";
		if(b[2] == 'C' && d[2] == 'D') cout << "00";
		if(b[2] == 'C' && d[2] == 'F') cout << "00";
		if(b[2] == 'D' && d[2] == 'F') cout << "11";
		if(b[2] == 'D' && d[2] == 'A') cout << "00";
		if(b[2] == 'D' && d[2] == 'B') cout << "00";
		if(b[2] == 'D' && d[2] == 'C') cout << "00";
		if(b[2] == 'F' && d[2] == 'D') cout << "11";
		if(b[2] == 'F' && d[2] == 'A') cout << "00";
		if(b[2] == 'F' && d[2] == 'B') cout << "00";
		if(b[2] == 'F' && d[2] == 'C') cout << "00";
	}	
	return 0;
}
