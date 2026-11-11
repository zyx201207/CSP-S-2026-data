#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	bool b=0;
	if(c1!=c2){
		cout<<"0000";
		b=1;
	}
	if(!b)cout<<1;
	if(!b&&((s1[0]!=s2[0])||(s1[1]!=s2[1]))){
		cout<<"000";
		b=1;
	}
	if(!b)cout<<1;
	if(!b){
		bool s11,s22;
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			s11=1;
		}
		else{
			s11=0;
		}
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			s22=1;
		}
		else{
			s22=0;
		}
		if(s11!=s22){
			cout<<"00";
			b=1;
		}
		if(!b)cout<<1;
	}
	if(!b&&((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s2[2]=='A'&&s1[2]=='B')||(s2[2]=='B'&&s1[2]=='C')||(s2[2]=='D'&&s1[2]=='F'))){
		cout<<1;
		b=1;
	}
	if(!b)cout<<0;
	return 0;
} 
