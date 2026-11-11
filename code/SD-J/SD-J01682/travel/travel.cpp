#include <bits/stdc++.h>
using namespace std;
int rc,rp,rz,xc,xp,xz;
string r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool flaga = 1,flagb = 1; 
	cin>>rc>>r>>xc>>x;
	rp = (r[0] - 48) * 10 + r[1] - 48;
	xp = (x[0] - 48) * 10 + x[1] - 48;
	rz = r[2] - 64;
	xz = x[2] - 64;
	if(rc == xc){
		cout<<1;
	}else{
		flaga = 0;
		cout<<0;
	}if(xp == rp && flaga){
		cout<<1;
	}else{
		cout<<0;
		flagb = 0;
	}if((((rz == 1 || rz == 2 || rz == 3) && (xz == 1 || xz == 2 ||xz == 3)) || ((rz == 4 || rz == 6) && (xz == 4 || xz == 6))) && flaga && flagb){
		cout<<1;
	}else{
		cout<<0;
	}if(((rz == 1 && xz == 2) || (rz == 2 && xz == 1) || (rz == 2 && xz == 3) || (rz == 3 && xz == 2) || (rz == 4 && xz == 6) || (rz == 6 && xz == 4)) && flaga && flagb){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 
