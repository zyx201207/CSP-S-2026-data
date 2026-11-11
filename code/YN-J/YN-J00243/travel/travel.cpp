#include<bits/stdc++.h>
using namespace std;
string rx,rw,xx,xw;
bool tc(char r,char x){
	if((r == 'A' && (x == 'B' || x == 'C')) || (r == 'B' && (x == 'A' || x == 'C')) || (r == 'C' && (x == 'B' || x == 'A'))){
		return true;
	}
	if((r == 'D' && x == 'F') || (r == 'F' && x == 'D')){
		return true;
	}
	return false;
}
bool xl(char r,char x){
	if((x == 'B' && (r == 'A' || r == 'B')) || (r == 'B' && (x == 'A' || x == 'C'))){
		return true;
	}
	if((r == 'D' && x == 'F') || (r == 'F' && x == 'D')){
		return true;
	}
	return false;
}
bool pdtc(string sr,string sx){
	if(tc(sr[2],sx[2])){
		return true;
	}
	return false;
}
bool pdxl(string sr,string sx){
	if(xl(sr[2],sx[2])){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> rx >> rw >> xx >> xw;
	if(rx == xx) cout << '1';
	else cout << '0';
	char a[3],b[3];
	a[0] = rw[0];
	a[1] = rw[1];
	b[0] = xw[0];
	b[1] = xw[1];
 	if(rx == xx && a[0] == b[0] && a[1] == b[1]){
		cout << '1';
	}
	else cout << '0';
	if(rx == xx && a[0] == b[0] && a[1] == b[1] && pdtc(rw,xw)){
		cout << '1';
	}
	else cout << '0';
	if(rx == xx && a[0] == b[0] && a[1] == b[1] && pdxl(rw,xw)){
		cout << '1';
	}
	else cout << '0';
	return 0;
}
