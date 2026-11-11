#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(s2[0]==s4[0]&&s2[1]==s4[1]){
		cout<<1;
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	if(s2[2]=='A'&&(s4[2]=='B'||s4[2]=='C')){
		cout<<1;
	}
	else if(s2[2]=='B'&&(s4[2]=='A'||s4[2]=='C')){
		cout<<1;
	}
	else if(s2[2]=='C'&&(s4[2]=='A'||s4[2]=='B')){
		cout<<1;
	}
	else if(s2[2]=='D'&&s4[2]=='E'){
		cout<<1;
	}
	else if(s2[2]=='E'&&s4[2]=='D'){
		cout<<1;
	}
	else{
		cout<<0;
		cout<<0;
		return 0;
	}
	if(s2[2]=='A'&&s4[2]=='B'){
		cout<<1;
	}
	else if(s2[2]=='B'&&(s4[2]=='A'||s4[2]=='C')){
		cout<<1;
	}
	else if(s2[2]=='C'&&s4[2]=='B'){
		cout<<1;
	}
	else if(s2[2]=='D'&&s4[2]=='E'){
		cout<<1;
	}
	else if(s2[2]=='E'&&s4[2]=='D'){
		cout<<1;
	}
	else{
		cout<<0;
		return 0;
	}
	return 0;
}