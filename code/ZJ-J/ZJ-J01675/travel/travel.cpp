#include<bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>ca>>sa>>cb>>sb;
	
	
	
	if(ca==cb){
		cout<<'1';
	}
	else{
		cout<<"0000";
		return 0;
	}
	
	
	
	if(sa[0]==sb[0]&&sa[1]==sb[1]){
		cout<<'1';
	}
	else{
		cout<<"000";
		return 0;
	}
	
	

	if(sa[2]=='D'&&sb[2]=='E'){
		cout<<"11";
		return 0;
	}
	if(sb[2]=='D'&&sa[2]=='E'){
		cout<<"11";
		return 0;
	}	
	int bj=0;
	if(sa[2]=='A'||sa[2]=='B'||sa[2]=='C'){
		bj++;
	}
	if(sb[2]=='A'||sb[2]=='B'||sb[2]=='C'){
		bj++;
	}
	if(bj==2){
		cout<<'1';
	}
	else{
		cout<<"00";
		return 0;
	}
	if(sa[2]=='B'||sb[2]=='B'){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	return 0;
}