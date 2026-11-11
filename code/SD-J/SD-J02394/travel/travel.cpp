#include<bits/stdc++.h>
using namespace std;
bool type(char a,char b){
	if(a>='A'&&a<='C'){
		if(b>='A'&&b<='C'){
			return true;
		}else return false;
	}else{
		if(b=='D'||b=='F'){
			return true;	
		}else return false;
	}
}
bool connect(char a,char b){
	if(a=='A'){
		if(b=='B') return true;
		else return false; 
	}else if(a=='B'){
		if(b=='A'||b=='C') return true;
		else return false;
	}else if(a=='C'){
		if(b=='B') return true;
		else return false;
	}else if(a=='D'){
		if(b=='F') return true;
		else return false;
	}else{
		if(b=='D') return true;
		else return false;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else{
		cout<<"1";
		if(s1[0]+s1[1]!=s2[0]+s2[1]){
			cout<<"000";
		}else{
			cout<<"1";
			if(type(s1[2],s2[2])){
				cout<<"1";
				if(connect(s1[2],s2[2])){
					cout<<"1";
				}else cout<<"0";
			}else cout<<"00";
		}
	}
	return 0;
}
