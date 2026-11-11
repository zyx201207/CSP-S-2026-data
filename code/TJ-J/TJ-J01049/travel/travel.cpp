#include<bits/stdc++.h>
using namespace std;
char lis_0[3]={'A','B','C'};
char lis_1[2]={'D','F'};
bool fun_1(char c_0,char c_1){
	bool flag=0,fg=0;
	for(char c:lis_0){
		if(c_0==c){
			flag=1;break;
		}
	}
	if(flag){
		for(char c:lis_0){
			if(c_1==c){fg=1;break;} 
		}
	}
	if(!flag){
		for(char c:lis_1){
			if(c_1==c){fg=1;break;} 
		}
	}
	return fg;
}
bool fun_2(char c_0,char c_1){
	bool fg=0;
	for(int i=1;i<=2;i++){
		if(c_0=='A'&&c_1=='B'){
			fg=1;
		}
		if(c_0=='B'&&c_1=='C'){
			fg=1;
		}
		if(c_0=='D'&&c_1=='F'){
			fg=1;
		}
		swap(c_0,c_1);
	}
	return fg;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{cout<<"0000";return 0;}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
	else{cout<<"000";return 0;}
	
	if(fun_1(s1[2],s2[2])) cout<<1;
	else{cout<<"00";return 0;}
	
	if(fun_2(s1[2],s2[2])) cout<<1;
	else cout<<0;
	return 0;
}
// Nah,i'd win! 
