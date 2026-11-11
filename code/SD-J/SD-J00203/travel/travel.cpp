#include<bits/stdc++.h>
using namespace std;

bool check(char a,char b){
	return ((a=='A'||a=='B'||a=='C')&&(b=='A'||b=='B'||b=='C'))	|| ((a=='D'||a=='F')&&(b=='D'||b=='F'));
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,c2,s1,s2,t1,t2;
	cin>>c1>>s1>>c2>>s2;
	bool b1,b2,b3,b4;
	b1=(c1==c2);
	b2=((b1)? s1.substr(0,2)==s2.substr(0,2):0);
	b3=((b2)? check(s1[2],s2[2]):0);
	b4=((b3)? abs(s1[2]-s2[2])==1:0);
	cout<<b1<<b2<<b3<<b4;
	return 0;
}
