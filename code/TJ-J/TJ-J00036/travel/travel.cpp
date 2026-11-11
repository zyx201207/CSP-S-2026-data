#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	string rc,rw,xc,xw,rp,xp;
	char r,x;
	cin>>rc>>rw>>xc>>xw;
	rp=rw[1];
	xp=xw[1];
	r=rw[2];
	x=xw[2];
	if(rc==xc){
		cout<<1;
		if(rp==xp){
			cout<<1;
			if(r=='A'||r=='B'||r=='C'){
				if(x=='A'||x=='B'||x=='C'){
					cout<<1;
					if(r!='B'&&x!='B')	cout<<"0";
					else	cout<<1;
				}if(x>='D'&&x<='E')	cout<<"00";
			}if(r=='D'||r=='E'){
				if(x=='D'||x=='E'){
					cout<<11;
				}else	cout<<"00";
			}
		}if(rp!=xp)	cout<<"000";
	}else	cout<<"0000";
	return 0;}
