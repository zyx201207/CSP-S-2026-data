#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int divide(string p){
	int o=0;
	if (p[0]=='1') o+=10;
	o+=(p[1]-'0');
	return o;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	int x=divide(b);
	int y=divide(d);
	char e=b[2];
	char f=d[2];
	if (a==c){
		cout << 1;
		if (x==y){
			cout << 1;
			bool flag=0;
			if ((e=='A' || e=='B' || e=='C') && (f=='A' || f=='B' || f=='C')){
				flag=1;
				cout << 1;
				if (abs(f-e)==1) cout << 1;
				else cout << 0;
			}
			if ((e=='D' || e=='F') && (f=='D' || f=='F')){
				flag=1;
				cout << 1;
				if (abs(f-e)==2) cout << 1;
				else cout << 0;
			}
			if (!flag) cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
