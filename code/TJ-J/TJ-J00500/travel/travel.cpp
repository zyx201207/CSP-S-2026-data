#include<bits/stdc++.h>
using namespace std;
string a,b;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool c=0;
	if(c1==c2){
		cout<<"1";
		c=1;
	}
	else cout<<"0";
	a+=s1[0];
	a+=s1[1];
	b+=s2[0];
	b+=s2[1];
	bool pd=0;
	if(a==b&&c){
		cout<<"1";
		pd=1;
	}
	else cout<<"0";
	bool t=0;
	if(pd){
		if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')cout<<"1";
		else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
			cout<<"1";
			t=1;
		}
		else cout<<"0";
	}
	else cout<<"0";
	if(t)cout<<"1";
	else if(s1[2]=='A'&&s2[2]=='B'&&c&&pd)cout<<"1";
	else if(s1[2]=='B'&&s2[2]=='A'&&c&&pd)cout<<"1";
	else if(c1[2]=='B'&&c2[2]=='C'&&c&&pd)cout<<"1";
	else if(c1[2]=='C'&&c2[2]=='B'&&c&&pd)cout<<"1";
	else cout<<"0";
	return 0;
} 
