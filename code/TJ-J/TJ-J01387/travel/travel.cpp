#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,cx,sx;
	int flag1=0,flag2=0,bsr=0,bsx=0,r,x;
	cin>>cr>>sr>>cx>>sx;
	if(sr[2]=='A'){
		r=1;
	}
	else if(sr[2]=='B'){
		r=2;
	}
	else{
		r=3;
	}
	if(sx[2]=='A'){
		x=1;
	}
	else if(sx[2]=='B'){
		x=2;
	}
	else{
		x=3;
	}
	if(sr[2]=='D'||sr[2]=='F'){
		bsr=1;
	}
	if(sx[2]=='D'||sx[2]=='F'){
		bsx=1;
	}
	if(cr==cx){
		cout<<"1";
		flag1=1;
	}
	else{
		cout<<"0";
	}
	if(flag1==1&&sr[0]==sx[0]&&sr[1]==sx[1]){
		cout<<"1";
		flag2=1;
	}
	else{
		cout<<"0";
	}
	if(flag1==1&&flag2==1&&bsr==bsx){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	if(flag1==1&&flag2==1){
		if(bsr==1&&bsx==1){
			cout<<"1";
		}
		else if(r+1==x||x+1==r){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else{
		cout<<"0";
	}
	return 0;
}
