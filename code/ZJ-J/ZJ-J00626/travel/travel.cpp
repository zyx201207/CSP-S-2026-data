#include<bits/stdc++.h>
#define ll long long
using namespace std;
string rc,rx,xc,xx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rx>>xc>>xx;
	bool fa=1,fb=1,fc=1;
	if(rc==xc){
		cout<<"1 ";
	}else{
		cout<<"0 ";
		fa=0;
	} 
	if(rx[0]==xx[0]&&rx[1]==xx[1]&&fa){
		cout<<"1 ";
	}else{
		cout<<"0 ";
		fb=0;
	} 
	int a=(rx[2]=='A')+(rx[2]=='B')+(rx[2]=='C');
	int b=(xx[2]=='A')+(xx[2]=='B')+(xx[2]=='C');
	int c=(rx[2]=='D')+(rx[2]=='F');
	int d=(xx[2]=='D')+(xx[2]=='F');
	if((a==b&&c==d)&&fb){
		cout<<"1 ";
	}else{
		cout<<"0 ";
		fc=0;
	}
	if(((rx[2]=='A'&&xx[2]=='B')||(rx[2]=='B'&&xx[2]=='C')||(rx[2]=='B'&&xx[2]=='A')||(rx[2]=='C'&&xx[2]=='B')||(rx[2]=='D'&&xx[2]=='F')||(rx[2]=='F'&&xx[2]=='D'))&&fc){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}