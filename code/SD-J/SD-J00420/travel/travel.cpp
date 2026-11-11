#include<bits/stdc++.h> 
using namespace std;
int c1,c2,zt=0;
char s1[5],s2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<0;
		zt=1;
	}
	if(zt==0&&s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
	else{
		cout<<0;
		zt=1;
	}
	if(zt==0&&s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='A'&&s2[2]=='B'||zt==0&&s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='B'&&s2[2]=='A'||zt==0&&s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='C'&&s2[2]=='B'||zt==0&&s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='B'&&s2[2]=='C'||zt==0&&s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='D'&&s2[2]=='F'||zt==0&&s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='F'&&s2[2]=='D'||zt==0&&s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='A'&&s2[2]=='C'||zt==0&&s1[0]==s2[0]&&s1[1]==s2[1]&&s1[2]=='C'&&s2[2]=='A') cout<<1;
	else{
		cout<<0;
		zt=1;
	}
	if(zt==0&&s1[2]=='A'&&s2[2]=='C'||zt==0&&s1[2]=='C'&&s2[2]=='A') cout<<0;
	else if(zt==1) cout<<0;
	else cout<<1;
	return 0;
}//sunset_god
