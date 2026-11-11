#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rc,rz,xc,xz;
	cin>>rc>>rz>>xc>>xz;
	string rp,xp;
	rp+=rz[0];
	rp+=rz[1];
	xp+=xz[0];
	xp+=xz[1];
	bool c=false,tt=0;
	if(rc!=xc){
		cout<<"0000";
		return 0;}
	cout<<1;
	if(rp!=xp){
		cout<<"000";
		return 0;}
	cout<<1;
	if(rz[2]=='A'&&xz[2]=='B') c=1;
	if(rz[2]=='A'&&xz[2]=='C') c=1;
	if(rz[2]=='B'&&xz[2]=='A') c=1;
	if(rz[2]=='B'&&xz[2]=='C') c=1;
	if(rz[2]=='C'&&xz[2]=='A') c=1;
	if(rz[2]=='C'&&xz[2]=='B') c=1;
	if(rz[2]=='D'&&xz[2]=='F') c=1;
	if(rz[2]=='F'&&xz[2]=='D') c=1;
	if(rz[2]=='A'||rz[2]=='B'||rz[2]=='C') tt=1;
	if(!c){
		cout<<"00";
		return 0;}
	cout<<1;
	if(!tt||rz[2]=='B'||xz[2]=='B'){
		cout<<1;
		return 0;}
	cout<<0;
	return 0;}
