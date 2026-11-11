#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a1,b2,a,b;
	cin >> a >> a1 >> b >> b2;
	if(a==b){
		cout << 1;
		if(a1.substr(0,2)==b2.substr(0,2)){
			cout << 1;
			if(a1[2]<='C'&&b2[2]<='C'||a1[2]>'C'&&b2[2]>='C'){
				cout << '1';
				if(abs(a1[2]-b2[2])==1 || (a1[2]!='F' && b2[2]!='D') && (a1[2]!='D' && b2[2]!='F')){
					cout << '1';
				}
				else{
					cout << '0';
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
