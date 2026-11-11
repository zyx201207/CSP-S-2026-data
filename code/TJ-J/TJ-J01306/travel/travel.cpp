#include <bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000";
	else{
		if(s1[2]>s2[2])swap(s1[2],s2[2]);
		bool b=(s1[0]==s2[0]&&s1[1]==s2[1]);
		bool b1=(s1[2]=='A'&&s2[2]=='B'),b2=(s1[2]=='B'&&s2[2]=='C'),b3=(s1[2]=='A'&&s2[2]=='C');
		bool b5=(s1[2]=='D'&&s2[2]=='E');
		cout<<1;
		cout<<b;
		cout<<((b1||b2||b3||b5)&&b);
		cout<<((b1||b2||b5)&&b);
	}
return 0;
}

