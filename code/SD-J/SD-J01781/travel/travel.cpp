#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool p(char i,char j){
	if(i=='C'&&j=='D'||i=='D'&&j=='C'){
		return 0;
	}
	return 1;
}
bool k(char i,char j){
	if(i=='A'&&j=='C'||i=='A'&&j=='B'||i=='B'&&j=='A'||i=='B'&&j=='C'||i=='C'&&j=='A'||i=='C'&&j=='B'||i=='E'&&j=='F'||i=='F'&&j=='E'){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(k(d[2],b[2])){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if((b[2]==d[2]+1||b[2]+1==d[2])&&p(b[2],d[3])==1){
		cout<<1;
	}else{
		cout<<"0";
	}
	return 0;
} 
