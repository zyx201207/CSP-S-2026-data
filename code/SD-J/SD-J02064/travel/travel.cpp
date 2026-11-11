#include<bits/stdc++.h>
using namespace std;
string ax,ay,bx,by;
int f(char a,char b){
	if(a=='A'||a=='B'||a=='C'){
		if(b=='A'||b=='B'||b=='C'){
			return 1;
		}else{
			return 0;
		}
	}
	
	if(a=='D'||a=='F'){
		if(b=='D'||b=='F'){
			return 1;
		}else{
			return 0;
		}
	}
	return 0;
}
int z(char a,char b){
	if(a=='A'&&b=='B'){
		return 1;
	}else if(b=='A'&&a=='B'){
		return 1;
	}else if(b=='B'&&a=='C'){
		return 1;
	}else if(b=='C'&&a=='B'){
		return 1;
	}else if(b=='D'&&a=='F'){
		return 1;
	}else if(b=='F'&&a=='D'){
		return 1;
	}else return 0;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>ax>>ay>>bx>>by;
	int dx,dy,bcx,bcy;
	dx=ax[0]-'0';
	bcx=ax[1]-'0';
	dy=bx[0]-'0';
	bcy=bx[1]-'0';
	if(dx==dy&&bcx==bcy){
		cout<<1;
	}else{
		cout<<"0"<<"0"<<"0"<<"0";
		return 0;
	}
	int x,y,xx,yy;
	x=ay[0]-'0';
	y=by[0]-'0';
	xx=ay[1]-'0';
	yy=by[1]-'0';
	char fx,fy;
	fx=ay[2];
	fy=by[2];
	if(x==y&&xx==yy){
		cout<<1;
	}else{
		cout<<"0"<<"0"<<"0";
		return 0;
	}
	if(f(fx,fy)==1){
		cout<<1;
	}else{
		cout<<"0"<<"0";
		return 0;
	}
	if(z(fx,fy)==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}

