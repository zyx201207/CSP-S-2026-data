#include <bits/stdc++.h>
using namespace std;
string a, b, c, d;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>a>>b>>c>>d;
	a = ' ' + a;
	b = ' ' + b;
	c = ' ' + c;
	d = ' ' + d;
	if(a==c){
		cout<<"1";
		if(b[1]==d[1]&&b[2]==d[2]){
			cout<<"1";
			if(b[3]<='C'&&d[3]<='C'||b[3]>='D'&&d[3]>='D'){
				cout<<"1";
				if(b[3]==d[3] + 1||d[3]==b[3] + 1||b[3]=='D'&&d[3]=='F'||b[3]=='F'&&d[3]=='D'){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
