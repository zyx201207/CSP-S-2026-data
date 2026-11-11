#include<bits/stdc++.h>
using namespace std;
string rc,rz,xc,xz;
int a1,a2,a3,a4,z1,z2,b1,b2,b3,b4,zz1,zz2;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>rc>>rz>>xc>>xz;
	a1=rc[0]-48;
	a2=rc[1]-48;
	a3=xc[0]-48;
	a4=xc[1]-48;
	if(a1!=0){
		z1=a1*10+a2;
	}else{
		z1=a2;
	}
	if(a3!=0){
		z2=a3*10+a4;
	}else{
		z2=a4;
	}
	if(z1!=z2){
		cout<<"0000";
		return 0;
	}
	b1=rz[0]-48;
	b2=rz[1]-48;
	b3=xz[0]-48;
	b4=xz[1]-48;
	if(b1!=0){
		zz1=b1*10+b2;
	}else{
		zz1=b2;
	}
	if(b3!=0){
		zz2=b3*10+b4;
	}else{
		zz2=b4;
	}
	if(zz1!=zz2){
		cout<<"1000";
		return 0;
	}
	a=rz[2];
	b=xz[2];
	if(a=='F'&&b=='C'||a=='F'&&b=='B'||a=='F'&&b=='A'||a=='D'&&b=='C'||a=='D'&&b=='B'||a=='D'&&b=='A'||a=='C'&&b=='F'||a=='C'&&b=='D'||a=='B'&&b=='D'||a=='B'&&b=='F'||a=='A'&&b=='D'||a=='A'&&b=='F'){
		cout<<"1100";
		return 0;
	}
	if(a=='F'&&b=='D'||a=='D'&&b=='F'||a=='A'&&b=='B'||a=='B'&&b=='A'||a=='C'&&b=='B'||a=='B'&&b=='C'){
		cout<<"1111";
		return 0;
	}else{
		cout<<"1110";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
