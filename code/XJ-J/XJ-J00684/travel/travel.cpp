#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2,q,w,e;
int main(){
	preopen("travel.in","r",stdin);
	preopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	//
	if(s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	//
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') q=1;
	else q=0;
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') w=1;
	else w=0;
	if(q==w) cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	if(q==0 && w==0){
		cout<<1;
	}else{
	if(s1[2]+1==s2[2]+0||s1[2]-1==s2[2]+0) cout<<1;
	else cout<<0;
	}	
	return 0;
}