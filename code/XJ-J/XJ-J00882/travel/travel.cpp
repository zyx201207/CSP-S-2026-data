#include<bits/stdc++.h>
using namespace std;
string rc,xc;
string rz,xz;
int rzs,xzs;
int rzz,xzz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>rc>>rz>>xc>>xz;
	for(int i=0;i<rz.size();i++){
		if(rz[i]>='0'&&rz[i]<='9'){
			rzs+=rzs*10+(rz[i]-'0');
		}
		else{
			rzz=i;
		}
	}
	for(int i=0;i<xz.size();i++){
		if(xz[i]>='0'&&xz[i]<='9'){
			xzs+=xzs*10+(xz[i]-'0');
		}
		else{
			xzz=i;
		}
	}
	if(rc!=xc){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<1;
	}
	if(rzs==xzs){
		cout<<1;
	}
	else{
		cout<<"000";
		return 0;
	}
	if((rz[rzz]=='A'&&(xz[xzz]=='B'||xz[xzz]=='C'))||(rz[rzz]=='B'&&(xz[xzz]=='A'||xz[xzz]=='C'))||(rz[rzz]=='C'&&(xz[xzz]=='A'||xz[xzz]=='B'))||(rz[rzz]=='F'&&xz[xzz]=='D')||(rz[rzz]=='D'&&xz[xzz]=='F')){
		cout<<1;
	}
	else{
		cout<<"00";
		return 0;
	}
	
	if((rz[rzz]=='A'&&xz[xzz]=='B')||(rz[rzz]=='B'&&xz[xzz]=='C')||(rz[rzz]=='D'&&xz[xzz]=='F')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}