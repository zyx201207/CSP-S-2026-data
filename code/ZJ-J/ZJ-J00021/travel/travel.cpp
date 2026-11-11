#include<bits/stdc++.h>
using namespace std;
bool check1(char a,char b){
	if(a=='A'&&b=='B') return true;
	if(a=='A'&&b=='C') return true;
	if(a=='B'&&b=='C') return true;
	if(a=='D'&&b=='F') return true;
	if(a=='B'&&b=='A') return true;
	if(a=='C'&&b=='A') return true;
	if(a=='C'&&b=='B') return true;
	if(a=='F'&&b=='D') return true;
	return false;
}
bool check2(char a,char b){
	if(a=='A'&&b=='B') return true;
	if(a=='B'&&b=='C') return true;
	if(a=='D'&&b=='F') return true;
	if(a=='B'&&b=='A') return true;
	if(a=='C'&&b=='B') return true;
	if(a=='F'&&b=='D') return true;
	return false;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(check1(s1[2],s2[2])){
				cout<<"1";
				if(check2(s1[2],s2[2])){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
}
