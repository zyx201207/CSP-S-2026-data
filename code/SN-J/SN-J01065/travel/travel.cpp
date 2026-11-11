#include<bits/stdc++.h>
using namespace std;
string co,ct,so,st;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>co>>so>>ct>>st;
	if(co!=ct){
		cout<<"0000\n";
		return 0;
	} 
	if(so[0]!=st[0]||so[1]!=st[1]){
		cout<<"1000\n";
		return 0;
	}
	if(((so[2]=='A'||so[2]=='B'||so[2]=='C')&&(st[2]=='D'||st[2]=='E'))||((st[2]=='A'||st[2]=='B'||st[2]=='C')&&(so[2]=='D'||so[2]=='E'))){
		cout<<"1100\n";
		return 0;
	}
	if(abs(so[2]-st[2])!=1){
		cout<<"1110\n";
		return 0;
	}
	cout<<"1111\n";
	return 0;
} 
