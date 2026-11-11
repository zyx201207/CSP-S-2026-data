#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
string R_c, R_s, X_c, X_s;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> R_c >> R_s >> X_c >> X_s;
	if (R_c != X_c){
		cout << "0000\n";
		return 0;
	}
	cout << 1;
	if (R_s[0] == X_s[0] && R_s[1] == X_s[1]) 
		cout << 1;
	else{
		cout << "000\n";
		return 0;
	}
	if (R_s[2]>='A'&&R_s[2]<='C'&&X_s[2]>='A'&&X_s[2]<='C')
		cout << 1;
	else if ((R_s[2]=='D'&&X_s[2]=='F')||(R_s[2]=='F'&&X_s[2]=='D')){
		cout << 11;
		return 0;
	}
	else{
		cout << "00\n";
		return 0;
	}
	if ((R_s[2]=='A'&&X_s[2]=='C')||(R_s[2]=='C'&&X_s[2]=='A'))
		cout << "0\n";
	else{
		cout << "1\n";
	}
	return 0;
}
