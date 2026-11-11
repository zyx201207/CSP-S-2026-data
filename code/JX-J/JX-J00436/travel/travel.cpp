#include<bits/stdc++.h>
using namespace std;
string ax,bx,ay,by;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>ax>>bx>>ay>>by;
	if(ax==ay) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(bx[0]==by[0]&&bx[1]==by[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if(bx[2]=='A'){
		if(by[2]=='B'){
			cout<<"11";
			return 0;
		}
		else if(by[2]=='C'){
			cout<<"10";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(by[2]=='A'){
		if(bx[2]=='B'){
			cout<<"11";
			return 0;
		}
		else if(bx[2]=='C'){
			cout<<"10";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(bx[2]=='B'){
		if(by[2]=='A'||by[2]=='C'){
			cout<<"11";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(by[2]=='B'){
		if(bx[2]=='A'||bx[2]=='C'){
			cout<<"11";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(bx[2]=='C'){
		if(by[2]=='B'){
			cout<<"11";
			return 0;
		}
		else if(by[2]=='A'){
			cout<<"10";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(by[2]=='C'){
		if(bx[2]=='B'){
			cout<<"11";
			return 0;
		}
		else if(bx[2]=='A'){
			cout<<"10";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(bx[2]=='D'){
		if(by[2]=='F'){
			cout<<"11";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(by[2]=='D'){
		if(bx[2]=='F'){
			cout<<"11";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(bx[2]=='F') {
		if(by[2]=='D'){
			cout<<"11";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	if(by[2]=='F'){
		if(bx[2]=='D'){
			cout<<"11";
			return 0;
		}
		else{
			cout<<"00";
			return 0;
		}
	}
	return 0;
}
