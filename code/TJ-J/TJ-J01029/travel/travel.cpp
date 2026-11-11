#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
string x1,x2,z1,z2; 
bool b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.in","w",stdout);
	cin.tie(0);
	cin >> x1 >> z1 >> x2 >> z2;
	if(x1==x2) {
		cout << 1;
	}
	else {
		cout << "0000";
		return 0;
	}
	if(z1[0]==z2[0] && z1[1]==z2[1]) {
		cout << 1;
	}
	else {
		cout << "000";
		return 0;
	}
	if(z1[2]=='A' or z1[2]=='B' or z1[2]=='C') b1=false;
	else b1=true;
	if(z2[2]=='A' or z2[2]=='B' or z2[2]=='C') b2=false;
	else b2=true;
	if(b1==b2) {
		cout << 1;
	}
	else {
		cout << "00";
		return 0;
	}
	if((z1[2]=='A'&&z2[2]=='C') || (z1[2]=='C'&&z2[2]=='A')) cout << 0;
	else cout << 1;
	return 0;
	
} 
