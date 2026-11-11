#include<bits/stdc++.h>
using namespace std;
string cr,sr,cx,sx;
bool ba=0,bb=0,bc=0,bd=0;
bool s(char x){
	if('A'<=x&&x<='C')
	return 0;
	return 1;
}
bool sbs(char r,char x){
	if(r=='A') return x=='B';
	if(r=='B') return (x=='A'||x=='C');
	if(r=='C') return x=='B';
	if(r=='D') return x=='F';
	if(r=='F') return x=='D';
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>cr>>sr>>cx>>sx;
	if(cr==cx){
		ba=1;
		if(sr[0]==sx[0]&&sr[1]==sx[1]){
			bb=1;
			if(s(sr[2])==s(sx[2])){
				bc=1;
				bd=sbs(sr[2],sx[2]);
			}
		}
	}
	cout<<ba<<bb<<bc<<bd;
	return 0;
}
