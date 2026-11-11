//SN-J00791 余思弦 西安工业大学附属中学 
#include<bits/stdc++.h>
using namespace std;
int a1,a2,b1,b2;
char c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>s1>>a2>>s2;
	b1=int(s1[0])*10+int(s1[1]);
	b2=int(s2[0])*10+int(s2[1]);
	c1=s1[2];
	c2=s2[2];
	if(a1==a2) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	if(b1==b2) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if((c1=='A'||c1=='B'||c1=='C')&&(c2=='A'||c2=='B'||c2=='C')) cout<<"1";
	else if((c1=='D'||c1=='F')&&(c2=='D'||c2=='F')){
		cout<<"11";
		return 0;
	}
	else{
		cout<<"00";
		return 0;
	}
	if((c1=='A'&&c2=='B') || (c1=='B'&&c2=='C')) cout<<"1";
	else cout<<"0";
	return 0;
}
