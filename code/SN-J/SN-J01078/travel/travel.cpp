#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string rc,rs,xc,xs;
	
	cin >> rc >> rs >> xc >> xs;
	if(rc==xc){
		cout<< 1;
		if(rs[0]==xs[0] && rs[1]==xs[1]) {
			cout << 1;
			if((rs[2]-'A'+xs[2]-'A'==7)||(abs(rs[2]-'A'+xs[2]-'A')<=2)||(rs[2]=='B'&&xs[2]=='B')){
				cout << 1;
				if(abs(rs[2]-xs[2])==1){
					cout << 1;
				}else cout << 0;
			}else cout << "00";
		}else cout << "000";
	}
	else cout << "0000";
	
	
	return 0;
}
