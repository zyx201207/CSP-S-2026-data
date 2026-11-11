#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int rn,rs,xn,xs;
	char r,x;
	cin >> rn >> rs >> r >> xn >> xs >> x;
	if(rn==xn){
		cout << "1";
		if(rs==xs){
			cout << "1";
			if(r>='A'&&r<='c'&&x>='A'&&x<='C'){
				cout << "1";
				if(r-x==1||x-r==1){
					cout << "1";
				}else{
					cout << "0";
				}
			}else if(r>='D'&&r<='F'&&x>='D'&&x<='F'){
				cout << "1";
				if(r-x==2||x-r==2){
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