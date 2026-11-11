#include<bits/stdc++.h> 
using namespace std;
string s1,c1,s2,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if((s1[0]-'0')*10+s1[1]-'0'==(s2[0]-'0')*10+s2[1]-'0'){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if((s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]<='F'&&s2[2]>='D')){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	char a=s1[2],b=s2[2];
	if(a>b) swap(a,b);
	if((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F')){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
