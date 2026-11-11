#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,rz,xc,xz;
	int a=1;
	cin>>rc>>rz>>xc>>xz;
	if(rc==xc) cout<<1;
	else cout<<0;
	if(rc==xc){
		if(rz[0]==xz[0]&&rz[1]==xz[1]) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	if(rc==xc){
		if(rz[0]==xz[0]&&rz[1]==xz[1]){
			if((rz[2]=='A'||rz[2]=='B'||rz[2]=='C')&&(xz[2]=='A'||xz[2]=='B'||xz[2]=='C')){
				a=1;
			}else a=0;
			if((rz[2]=='D'||rz[2]=='F')&&(xz[2]=='D'||xz[2]=='F')){
				a=1;
			}else if(a!=1){
				a=0;
			}
	}else a=0;
}else a=0;
cout<<a;
	int b=1;
	if(rc==xc){
		if(rz[0]==xz[0]&&rz[1]==xz[1]){
		if((rz[2]=='A'&&xz[2]=='B')||(rz[2]=='B'&&xz[2]=='A')||(rz[2]=='B'&&xz[2]=='C')||(rz[2]=='C'&&xz[2]=='B')){
			b=1;
		}else b=0;
		if((rz[2]=='D'&&xz[2]=='F')&&(xz[2]=='D'&&rz[2]=='F')){
			b=1;
		}else if(b!=1){
				b=0;
			}
	}else b=0;
}else b=0;
	cout<<b;
	return 0;
} 




























































