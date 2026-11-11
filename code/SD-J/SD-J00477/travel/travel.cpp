#include<bits/stdc++.h>
using namespace std;
string ac,as,bc,bs;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> ac >> as >> bc >> bs;
	if(ac==bc){
		cout << "1";
	}
	else{
		cout << "0";
	}
	if(as[1]==bs[1]&&as[0]==bs[0]&&ac==bc){
		cout << "1";
	}
	else{
		cout << "0";
	}
	if(((as[2]=='A'||as[2]=='B'||as[2]=='C')&&(bs[2]=='A'||bs[2]=='B'||bs[2]=='C')||((as[2]=='D'&&bs[2]=='F')||(bs[2]=='D'&&as[2]=='F')))&&(as[1]==bs[1]&&as[0]==bs[0])&&ac==bc){
		cout << "1";
	}
	else{
		cout << "0";
	}
	if(((as[2]=='A'||as[2]=='B'||as[2]=='C')&&(bs[2]=='A'||bs[2]=='B'||bs[2]=='C')||((as[2]=='D'&&bs[2]=='F')||(bs[2]=='D'&&as[2]=='F')))&&(as[1]==bs[1]&&as[0]==bs[0])&&(abs(as[2]-bs[2])==1&&(as[2]&&bs[2]!='D'||as[2]&&bs[2]!='F'))&&ac==bc){
		cout << "1";
	}
	else{
		cout << "0";
	}
	return 0;
} 
