#include<bits/stdc++.h>
using namespace std;
string a,b,c,d; 
char zwa,zwb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	zwa=b[2];
	zwb=d[2];
	if(a==c){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0] and b[1]==d[1]){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	if((zwa<='C' and zwb<='C') or ((zwa=='D' or zwa=='F') and (zwb=='D' or zwb=='F'))){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if((zwa=='A' and zwb=='B') or (zwa=='B' and zwb=='A') or (zwa=='B' and zwb=='C') or (zwa=='C' and zwb=='B') or (zwa=='D' and zwb=='F') or (zwa=='F' and zwb=='D')){
		cout<<"1";
	}
	else{
		cout<<"0";
		return 0;
	}
	return 0;
}
