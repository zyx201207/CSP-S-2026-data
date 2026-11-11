#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c,s,c1,s1;
	cin>>c>>s>>c1>>s1;
	bool d;
	if(c[0]==c1[0]&&c[1]==c1[1]){
		cout<<"1";
		d=1;
	} else{
		cout<<"0";
		d=0;
	} 
	if(d==1&&s[0]==s1[0]&&s[1]==s1[1]){
		d=1;
		cout<<"1";
	} else{
		d=0;
		cout<<"0";
	} 
	if(d==1&&(s[2]=='A'||s[2]=='B'||s[2]=='C')&&(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')){
		d=1;
		cout<<"1";
	  } else if(d==1&&(s[2]=='D'||s[2]=='F')&&(s1[2]=='D'||s1[2]=='F')){
	  	d=1;
	  	cout<<"1";
	} else {
		cout<<"0";
		d=0;
	}
	if(d==1&&(s[2]-s1[2]==1||s1[2]-s[2]==1)) cout<<"1";
	else cout<<"0";
	return 0;
}
