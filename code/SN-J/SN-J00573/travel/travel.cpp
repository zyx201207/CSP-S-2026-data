#include<bits/stdc++.h>
using namespace std;
string cr,cx,zr,zx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>zr>>cx>>zx;
	if(cr!=cx) cout<<"0000";
	else {
		cout<<"1";
		string xf=zr.substr(0,2),xt=zx.substr(0,2);
		if(xf!=xt) cout<<"000";
		else {
			cout<<"1";
			string xg=zr.substr(2,1),xh=zx.substr(2,1);
			if((xg<="C"&&xh<="C")||(xg>"C"&&xh>"C")) cout<<"1";
			else {
				cout<<"00";
				return 0;
			}
			if((xg=="D"&&xh=="F")||(xh=="D"&&xg=="F")) cout<<"1";
			else if((xg=="A"&&xh=="B")||(xh=="A"&&xg=="B")) cout<<"1";
			else if((xg=="C"&&xh=="B")||(xh=="C"&&xg=="B")) cout<<"1";
			else cout<<"0";
		}
	}
	return 0; 
}
