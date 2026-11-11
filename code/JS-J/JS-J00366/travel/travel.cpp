#include<bits/stdc++.h>
using namespace std;
int c1,s1;
string c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	int cs=c2[0]-'0',cg=c2[1]-'0';
	int ss=s2[0]-'0',sg=s2[1]-'0';
	int cn=cs*10+cg;
	int sn=ss*10+sg;
	if(cn==sn){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}char cw=c2[2];
	char sw=s2[2];
	if((cw=='C'||cw=='B'||cw=='A')&&(sw=='C'||sw=='B'||sw=='A')){
		cout<<1;
		if(cw=='B'||sw=='B'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if((cw=='D'||cw=='F')&&(sw=='D'||sw=='F')){
		cout<<"11";
	}else{
		cout<<"00";
	}return 0;
}
