#include<bits/stdc++.h>
using namespace std;
int a,b,aa,bb;
char ax,bx;
void x(int i,int j){
	if(i==j) cout<<"1";
	else cout<<"0";
}
void xx(int a,int b,int i,char ix,int j,char jx){
	if(a!=b){
		cout<<"000";
		return;
	}
	if(i==j){
		if((ix=='A'&&jx=='B')||(ix=='F'&&jx=='D')||(ix=='C'&&jx=='B')||(ix=='B'&&jx=='A')||(ix=='D'&&jx=='F')||(ix=='B'&&jx=='C')){
			cout<<"111";
			return;
		}
		else{
			if((ix=='A'&&jx=='C')||(ix=='C'&&jx=='A')){
				cout<<"110";
				return;	
			}
		}
		cout<<"100";
		return;
	}
	cout<<"000";
	return;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>ax>>b>>bb>>bx;
	x(a,b);
	xx(a,b,aa,ax,bb,bx);
	return 0;
}
