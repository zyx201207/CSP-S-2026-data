#include<bits/stdc++.h>
using namespace std;

string c1,c2,c3,c4;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> c2 >> c3 >> c4;
	if(c1==c3){
		cout << "1";
		if(c2[0]==c4[0] && c2[1]==c4[1]){
			cout << "1";
			if(c2[2]<='C' && c4[2]<='C' || c2[2]>'C' && c4[2]>'C'){
				cout << "1";
				char x=c2[2],y=c4[2];
				if(x==char(y+1) || y==char(x+1)){
					cout << "1";
				}else{
					cout << "0";
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	return 0;
}
