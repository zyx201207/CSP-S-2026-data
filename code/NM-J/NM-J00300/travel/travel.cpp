#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	char n=s1[0];
	char b=s2[0];
	char a=s1[1];
	char c=s2[1];
	char d=s1[2];
	char e=s2[2];
	if(c1!=c2){
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}

	if(c1==c2){
		cout<<1;
	}
	if(n==b&&a==c&&c1==c2) cout<<1;
	if(n!=b||a!=c){
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}

	if(d<='C'&&e<='C'||d>='D'&&e>='D') cout<<1;
	if(d>'C'&&e<='C'||d<'D'&&e>='D'||d>'C'&&e<'C'||d<'D'&&e>'D'){
		cout<<0;
		cout<<0;
		return 0;
	}
	if(d-e<=1&&d-e>0||e-d<=1&&e-d>0) cout<<1;
	if(d-e>1) cout<<0;
	return 0;
}
