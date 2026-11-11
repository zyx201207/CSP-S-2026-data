#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
bool f=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<0;
		f=0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&f) cout<<1;
	else{
		cout<<0;
		f=0;
	}
	if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&f) cout<<1;
	else if((s1[2]=='D'||s1[2]=='F')&&(s1[2]=='D'||s1[2]=='F')&&f) cout<<1;
	else{
		cout<<0;
		f=0;
	}
	if(abs(int(s1[2]-s2[2]))==1&&f){
		if((s1[2]=='D'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='D')) cout<<0;
		else cout<<1;
	}else cout<<0;
	return 0;
}
