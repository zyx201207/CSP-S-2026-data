#include <bits/stdc++.h>
using namespace std;
char c(char a){
	if(a=='A')return 'B';
	if(a=='B')return 'C';
	if(a=='C')return 'D';
	if(a=='D')return 'F';
	if(a=='F')return 'D';
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		if(s2[2]=='D'||s2[2]=='F'){
			cout<<"00";
			return 0;
		}else{
			cout<<"1";
		}
	}
	if(s1[2]=='D'||s1[2]=='F'){
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			cout<<"00";
			return 0;
		}else{
			cout<<"1";
		}
	}
	if(c(s1[2])==s2[2]||c(s2[2])==s1[2]){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
