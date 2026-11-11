#include<bits/stdc++.h>
using namespace std;
string rh,rz,xh,xz;
int flag=0,i,p=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rh>>rz>>xh>>xz;
	for(i=0;i<2;i++){
		if(rh[i]==xh[i]){
			flag=1;
		}else{
			flag=0;
		}
		if(flag==0){
			break;
		}
	}
	if(flag==1){
		cout<<"1";
	}else{
		cout<<"0";
	}
	flag=0;
	for(i=0;i<2;i++){
		if(rz[i]==xz[i]){
			flag=1;
		}else{
			flag=0;
		}
		if(flag==0){
			break;
		}
	}
	if(flag==1){
		cout<<"1";
		p=1;
	}else{
		cout<<"0";
	}
	if(p==1&&rz[2]>='A'&&rz[2]<='C'&&xz[2]>='A'&&xz[2]<='C'){
		cout<<"1";
	}else if(p==1&&rz[2]>='D'&&rz[2]<='F'&&xz[2]>='D'&&xz[2]<='F'){
		cout<<"1";
	}else{
		cout<<"0";
	}
	if(rz[2]=='A'&&xz[2]=='B'||rz[2]=='B'&&xz[2]=='A'){
		cout<<"1";
	}else if(rz[2]=='B'&&xz[2]=='C'||rz[2]=='C'&&xz[2]=='B'){
		cout<<"1";
	}else if(rz[2]=='D'&&xz[2]=='F'||rz[2]=='F'&&xz[2]=='D'){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}