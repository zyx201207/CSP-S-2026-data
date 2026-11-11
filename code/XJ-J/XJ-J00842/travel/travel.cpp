#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,rz,xc,xz,r=0,x=0;
	cin >> rc >> rz >> xc >> xz;
	if(rc==xc){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if(rz[2]==xz[2]){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if(rz[2]==xz[2]){
		cout << 1;
	}
	else{
		cout << 0;
	}
	r+=(rz[0]-'0')*10+(rz[1]-'0')*10;
	x+=(rz[0]-'0')*10+(rz[1]-'0')*10;
	if(r==x){
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}