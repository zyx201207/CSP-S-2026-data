#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}//
	int s1p=(s1[0]-'0')*10+(s1[1]-'0');
	int s2p=(s2[0]-'0')*10+(s2[1]-'0');
	int s1z=(s1[2]-'A');
	int s2z=(s2[2]-'A');
	if(s1p==s2p) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}//
	if((s1z>=3 && s2z<=2) || (s2z>=3 && s1z<=2)){
		cout<<"00";
		return 0;
	}else cout<<"1";
	//
	if(s1z>=3){
		cout<<"1";
		return 0;
	}
	else if(s1z-s2z==1 || s2z-s1z==1){
		cout<<"1";
		return 0;
	}cout<<"0";
	return 0;
}
