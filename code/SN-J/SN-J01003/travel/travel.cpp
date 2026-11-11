#include <bits/stdc++.h>
using namespace std;

string xi;
string xh;
string ri;
string rh;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool a=0;
	cin >>xi>>xh>>ri>>rh;
	if(xi==ri){
		cout<<1;
		a=1;
	} else {
		cout << 0;
		a=0;
	}
	if(xh[0]==rh[0]&&xh[1]==rh[1]){
		if(a){
			cout << 1;
			a=1;
		}
		if(('A'<=xh[2]&&xh[2]<='C'&&'A'<=rh[2]&&rh[2]<='C')||('D'<=xh[2]&&xh[2]<='F'&&'D'<=rh[2]&&rh[2]<='E')){
			a=1;
		} else {
			a=0;
		}
  if(a){
			cout<<a;
		} else {
			cout<<0;
		}
	}
	if(('A'<=xh[2]&&xh[2]<='C'&&'A'<=rh[2]&&rh[2]<='C')||('D'<=xh[2]&&xh[2]<='F'&&'D'<=rh[2]&&rh[2]<='E')){
		if(xh[0]==rh[0]&&xh[1]==rh[1]){
			if(xh[2]-rh[2]==-1||xh[2]-rh[2]==1){
				cout << 1;
			} else {
				cout << 0;
			}
		} else {
			cout << 0;
		}
	} else {
		cout << 0;
	}
	return 0;
	}
