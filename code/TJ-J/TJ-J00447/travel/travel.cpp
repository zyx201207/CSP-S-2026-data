#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string> 
using namespace std; 
string rc,rz,xc,xz;
string grz,gxz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rz>>xc>>xz;
	if(rc!=xc){
		cout<<"0000\n";
	}else{
		cout<<"1";
		grz+=rz[0],grz+=rz[1];
		gxz+=xz[0],gxz+=xz[1];
		if(grz==gxz){
			cout<<"1";
			if((rz[2]>='A'&&rz[2]<='C'&&xz[2]>='A'&&xz[2]<='C')||(rz[2]>='D'&&rz[2]<='F'&&xz[2]>='D'&&xz[2]<='F')){
				cout<<"1"; 
				if(abs((rz[2]-'A')-(xz[2]-'A'))==1||(rz[2]=='F'&&xz[2]=='D')||(rz[2]=='D'&&rz[2]=='F')){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}
	return 0;
}
