#include<bits/stdc++.h>
using namespace std;
int c1, c2;
char s1[3];
char s2[3];
int s(int sx,int sy){
	if(sx>'C'&&sy<='C'||sy>'C'&&sx<='C'){
		cout<<"00";
	}else if(sx<='C'&&sy<='C'){
		if(sx-sy==1&&sx-sy==-1){
			cout<<"11";
		}else{
			cout<<"10";
		}
	}else{
		cout<<"11";
	}	
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	for(int i=0;i<3;i++){
		cin>>s1[i];	
	}
	cin>>c2;
	for(int i=0;i<3;i++){
		cin>>s2[i];	
	}
	if(c1==1||c1==16||c2==1||c2==16){
		cout<<"0000";
		return 0;
	}
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
	} 
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"000";
		return 0;
	}else if(s1[0]==s2[0]||s1[1]==s2[2]){
		cout<<"1";
	}
	s(s1[2],s2[2]);
	return 0;
} 
