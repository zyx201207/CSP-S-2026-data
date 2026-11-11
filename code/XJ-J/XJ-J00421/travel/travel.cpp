#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cr,cx,rp,xp;string sr,sx;
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(sr[0]==0){
		rp=sr[1]-'0';
	}
	else{
		rp=(sr[0]-'0')*10+sr[1]-'0';
	}
	if(sx[0]==0){
		xp=sx[1]-'0';
	}
	else{
		xp=(sx[0]-'0')*10+sx[1]-'0';
	}
	if(rp==xp){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(sr[2]=='A'&&sx[2]=='B'){
		cout<<1;
	}
	else if(sr[2]=='B'&&sx[2]=='C'){
		cout<<1;
	}
	else if(sr[2]=='A'&&sx[2]=='C'){
		cout<<1;
	}
	else if(sr[2]=='D'&&sx[2]=='F'){
		cout<<1;
	}
	else if(sr[2]=='C'&&sx[2]=='B'){
		cout<<1;
	}
	else if(sr[2]=='C'&&sx[2]=='A'){
		cout<<1;
	}
	else if(sr[2]=='F'&&sx[2]=='D'){
		cout<<1;
	}
	else if(sr[2]=='B'&&sx[2]=='A'){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if(sr[2]=='A'&&sx[2]=='B'){
		cout<<1;
	}
	else if(sr[2]=='B'&&sx[2]=='C'){
		cout<<1;
	}
	else if(sr[2]=='D'&&sx[2]=='F'){
		cout<<1;
	}
	else if(sr[2]=='F'&&sx[2]=='D'){
		cout<<1;
	}
	else if(sr[2]=='B'&&sx[2]=='A'){
		cout<<1;
	}
	else if(sr[2]=='C'&&sx[2]=='B'){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
