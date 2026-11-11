#include<bits/stdc++.h>
using namespace std;
string s,s1,ss,ss1;
int main(){
	freopen("travel","r",stdin);
	freopen("travel","w",stdout);
	cin>>s>>s1>>ss>>ss1;
	bool a=0,b=0,c=0;
	
	if(s==ss){
		a=1;
		cout<<1;
	} 
	else cout<<0;
	if(a){
		if(s1[0]==ss1[0] and s1[1]==ss1[1]){
			cout<<1;
			b=1;
		}
		else cout<<0;
	}
	else{
		cout<<"000";
		return 0;
	} 
	if(a and b){
		if(s1[2]=='A' or s1[2]=='B' or s1[2]=='C'){
		if(ss1[2]=='A' or ss1[2]=='B' or ss1[2]=='C'){
			cout<<1;
			c=1;
		}
		else cout<<0;
	}
	else if(s1[2]=='F' or s1[2]=='D'){
		if(ss1[2]=='F' or ss1[2]=='D'){
			cout<<1;
			c=1;
		}
		else cout<<0;
	}
	 
	}
	else {
		cout<<"00";
		return 0;
	}
	if(a and b and c){
		if(s1[2]-ss1[2]==1 or s1[2]-ss1[2]==-1) cout<<1;
		else if(s1[2]=='F' and ss1[2]=='D' ) cout<<1;
		else if(s1[2]=='D' and ss1[2]=='F') cout<<1;
		else cout<<0;
	}
	else{
		cout<<0;
	}
	return 0;
}
