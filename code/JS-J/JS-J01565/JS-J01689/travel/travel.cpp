#include<bits/stdc++.h>
using namespace std;
bool check3(char c1,char c2){
	if(c1=='A')return (c2=='B'||c2=='C'||c2=='A');
	if(c1=='B')return (c2=='A'||c2=='C'||c2=='B');
	if(c1=='C')return (c2=='A'||c2=='B'||c2=='A');
	if(c1=='D')return (c2=='F'||c2=='D');
	if(c1=='F')return (c2=='D'||c2=='F');
}
bool check4(char c1,char c2){
	if(c1=='A')return (c2=='B');
	if(c1=='B')return (c2=='A'||c2=='C');
	if(c1=='C')return (c2=='B');
	if(c1=='D')return (c2=='F');
	if(c1=='F')return (c2=='D');
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<"1";
		if((s2[0]-'0')*10+s2[1]-'0'==(s4[0]-'0')*10+s4[1]-'0'){
			cout<<"1";
			if(check3(s2[2],s4[2])){
				cout<<"1";
				if(check4(s2[2],s4[2]))cout<<"1";
				else cout<<"0";
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
	return 0;
}
