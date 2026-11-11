#include<iostream>
using namespace std;
string n,m,a,s; 
int main(){
	std::ios::sync_with_stdio(false);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m>>a>>s;
	if(n==a){
		cout<<1;
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(m[0]==s[0]&&m[1]==s[1]){
		cout<<1;
		
	}else{
		cout<<"000";
		return 0;
	}
	if(m[2]=='A'||m[2]=='B'||m[2]=='C'&&s[2]=='A'||s[2]=='B'||s[2]=='C'){
		cout<<1;
		
	}else if(m[2]=='D'||m[2]=='E'&&s[2]=='D'||s[2]=='E'){
		cout<<1;
		return 0;
	}
	else{
		cout<<"00";
		return 0;
	}
	if(m[2]-s[2]==1||m[2]-s[2]==-1){
		cout<<1;
		
	}else{
		cout<<0;
		return 0;
	}
	return 0;
}
