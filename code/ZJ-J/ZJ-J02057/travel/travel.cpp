#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool g=false;
	if(c1==c2){
		cout<<1;
		g=true;
	}
	else cout<<0;
	bool f=false;
	if(g==true){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			f=true;	
		}
		else cout<<0;
	}
	else cout<<0;
	bool x=false;
	if(f==true&&g==true){
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'&&s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			cout<<1;
			x=true;
		}else if(s1[2]=='D'||s1[2]=='F'&&s2[2]=='D'||s2[2]=='F'){
			cout<<1;
			x=true;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(x==true&&g==true&&f==true){
		if(s1[2]=='D'||s2[2]=='D'||s1[2]=='F'||s2[2]=='F'){
			if(s1[2]=='D'&&s2[2]=='F')cout<<1;
			else if(s1[2]=='F'&&s2[2]=='D')cout<<1;
			else cout<<0;
		}else{
			if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}else{
		cout<<0;
	}
	return 0;
}
