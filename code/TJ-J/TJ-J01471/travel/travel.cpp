#include<bits/stdc++.h>
using namespace std;
string ca,sa,cb,sb;
bool check(char a,char b){
	if(a=='A' || a=='B' || a=='C'){
		if(b=='A' || b=='B' || b=='C'){
			return true;
		}
	}
	if(a=='D' || a=='F'){
		if(b=='D' || b=='F'){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>ca>>sa>>cb>>sb;
	if(ca!=cb){
		cout<<'0';
	}
	else{
		cout<<'1';
	}
	if(ca==cb && sa[0]==sb[0] && sa[1]==sb[1]){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	if(ca==cb && sa[0]==sb[0] && sa[1]==sb[1] && check(sa[2],sb[2])){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	if(ca==cb && sa[0]==sb[0] && sa[1]==sb[1] && check(sa[2],sb[2]) && char(sa[2]==(sb[2]-1) || sb[2]==char(sa[2]-1) ) ){
		cout<<'1';
	}
	else{
		cout<<'0';
	}
	
	return 0;
}
