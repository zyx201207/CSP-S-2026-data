#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
bool unsimilar(char a,char b){
	if(a>='A'&&a<='C'){
		if(b>='D'&&b<='F'){
			return true;
		}
			return false;
		
	}
	else if(a=='D'){
		if(b!='F')return true;
		else return false;
	}
	else {
		if(b!='D')return true;
		return false;
	}
	return true;
}
bool unn(char a,char b){
	if(a=='A'||a=='C'){
		if(b=='B')return false;
		return true;
	}
	else if(a=='B'){
		if(b=='A'||b=='C')return false;
		return true;
	}
	else if(a=='D'){
		if(b=='F')return false;
		return true;
	}
	else {
		if(b=='D')return false;
		return true;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]!=c2[0]||c1[1]!=c2[1]){
		cout<<"0 0 0 0";
		return 0;
	}
	cout<<"1 ";
	if(s1[1]!=s2[1]||s1[0]!=s2[0]){
		cout<<"0 0 0";
		return 0;
	}
	cout<<"1 ";
	if(unsimilar(s1[2],s2[2])){
		cout<<"0 0";
		return 0;
	}
	cout<<"1 ";
	if(unn(s1[2],s2[2])){
		cout<<"0";
		return 0;
	}
	cout<<"1";
	return 0;
}
