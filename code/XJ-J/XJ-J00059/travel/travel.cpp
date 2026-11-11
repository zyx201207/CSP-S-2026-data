#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int tp1,tp2,si1,si2; 
int tp(string s){
	if(s[2]=='A')return 1;
	if(s[2]=='B')return 2;
	if(s[2]=='C')return 3;
	if(s[2]=='D')return 4;
	if(s[2]=='F')return 5;
}
int si(string s){
	if(s[2]=='A')return 1;
	if(s[2]=='B')return 1;
	if(s[2]=='C')return 1;
	if(s[2]=='D')return 2;
	if(s[2]=='F')return 2;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	tp1=tp(s1),tp2=tp(s2);
	si1=si(s1),si2=si(s2);
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(si1==si2){
				cout<<"1";
				if(si1==si2&&abs(tp1-tp2)==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else {
				cout<<"00";
			}
		}
		else {
			cout<<"000";
		}
	}
	else {
		cout<<"0000";
	}
	return 0;
} 
