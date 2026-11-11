//SN-J00748  张哲瀚  西安市第八十九中学  
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,rp,xc,xp;
	cin>>rc>>rp>>xc>>xp;
	int a=0,b=0,c=0,d=0;
	if(rc==xc){
		a=1;
		if(rp[0]==xp[0]&&rp[1]==xp[1]){
			b=1;
			if(rp[2]>='D'&&xp[2]>='D'){
				c=1;
				d=1;
			}
			else if(rp[2]<='C'&&xp[2]<='C'){
				c=1;
				if(abs(rp[2]-xp[2])==1){
					d=1;
				}
			}
		}
	}
	cout<<a<<b<<c<<d;
	return 0;
}
