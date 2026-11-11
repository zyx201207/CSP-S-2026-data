#include <bits/stdc++.h>
using namespace std;
int rn,xn;
string rz,xz;
int rl,xl;
char rr,xr;
int main (){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	cin >> rn >> rz >> xn >> xz;
	rl=rz[0]*10+rz[1];
	xl=xz[0]*10+xz[1];
	rr=rz[2];
	xr=xz[2];
	bool a;

	if (rn==xn){
		a=1;
		cout << 1;
	}else{
		a=0;
		cout << 0;
	}
	bool c;
	if (a&&(rl==xl)){
		c=1;
		cout  << 1;
	}else {
		c=0;
		cout << 0;
	}
	bool b;
	if (((rr=='A'||rr=='B'||rr=='C')&&(xr=='D'||xr=='F'))||((xr=='A'||xr=='B'||xr=='C')&&(rr=='D'||rr=='F'))){
		b=0;
		cout << 0;
	}else if (c){
		b=1;
		cout << 1;
	}else {
		b=0;
		cout << 0;
	}
	if (b&&(rr-xr==1||xr-rr==1)){
		cout << 1;
	}else {
		cout << 0;
	}
	return 0;
}
