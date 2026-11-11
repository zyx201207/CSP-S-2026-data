#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
string Rx,Rz,Xx,Xz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin>>Rx>>Rz>>Xx>>Xz;
	if(Rx==Xx){
		cout<<"1";
		if(Rz[0]==Xz[0]&&Rz[1]==Xz[1]){
			cout<<"1";
			if((Rz[2]>='A'&&Rz[2]<='C'&&Xz[2]>='A'&&Xz[2]<='C')||(Rz[2]>='D'&&Rz[2]<='F'&&Xz[2]>='D'&&Xz[2]<='F')){
				cout<<"1";
				if((Rz[2]=='A'&&Xz[2]=='B')||(Rz[2]=='B'&&Xz[2]=='A')||(Rz[2]=='B'&&Xz[2]=='C')||(Rz[2]=='C'&&Xz[2]=='B')||(Rz[2]=='D'&&Xz[2]=='F')||(Rz[2]=='F'&&Xz[2]=='D')){
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
	}else{
		cout<<"0000";
	}
	return 0;
} 
