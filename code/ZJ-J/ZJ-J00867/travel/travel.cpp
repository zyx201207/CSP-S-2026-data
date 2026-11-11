#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
char z1,z2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	z1=s1[2];
	z2=s2[2];
	s2[2]='0';
	s1[2]='0';
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1==c2&&s1==s2){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1==c2&&s1==s2&&'C'>=z1&&z1>='A'&&'C'>=z2&&z2>='A'||c1==c2&&s1==s2&&'F'>=z1&&z1>='E'&&'F'>=z2&&z2>='E'){
	    cout<<1;
	}
	else{
		cout<<0;
	}
	if(c1==c2&&s1==s2&&'C'>=z1&&z1>='A'&&'C'>=z2&&z2>='A'&&z1+1==z2||c1==c2&&s1==s2&&'F'>=z1&&z1>='E'&&'F'>=z2&&z2>='E'&&z2+1==z1){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
