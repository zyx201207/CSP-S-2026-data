#include<iostream>
#include<string>
#include<cmath>
#define ll long long
using namespace std;

string x, y ,u ,v;

bool check1(char a, char b) {
	if( ( a<='C' && b<='C' ) || (a>'C' && b>'C') ) return true;
	return false;
}

int main(){
	freopen("travel.in", "r" ,stdin);
	freopen("travel.out" ,"w" ,stdout);
	cin >> x >> y >> u >> v;
	if( x==u ) {
		cout << "1";
		if( y[0]==v[0] && y[1]==v[1] ) {
			cout << "1";
			if( check1(y[2] ,v[2]) && ( y[0]==v[0] && y[1]==v[1] ) ) {
				cout << "1";
				if( (int)abs(y[2]-v[2])==1 && ( ( y[2]!='C' && v[2]!='D' ) && ( y[2]!='D' && v[2]!='C' ) ) ) cout << "1";
				else cout << "0";
			}
			cout << "00";
		}
		cout << "000";
	}else cout << "0000";
	return 0;
}
