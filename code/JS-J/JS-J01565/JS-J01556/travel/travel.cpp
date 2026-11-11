#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool check1(){
	if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')) return true;
	if((b[2]=='D'||b[2]=='E')&&(d[2]=='D'||d[2]=='E')) return true;
	return false;
	
}
bool check(){
	if(b[2]=='A'&&d[2]=='B') return true;
	if(b[2]=='B'&&d[2]=='A') return true;
	if(b[2]=='B'&&d[2]=='C') return true;
	if(b[2]=='C'&&d[2]=='B') return true;
	if(b[2]=='D'&&d[2]=='E') return true;
	if(b[2]=='E'&&d[2]=='D') return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
	}else if(b[0]!=d[0]||b[1]!=d[1]){
		cout<<"1000";
	}else if(!check1()){
		cout<<"1100";
	}else if(!check()){
		cout<<"1110";
	}else{
		cout<<"1111";
	}
	return 0;
}
