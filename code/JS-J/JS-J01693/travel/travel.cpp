#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) {cout<<"0000";return 0;}
	int a=(s1[0]-'0')*10+(s1[1]-'0');
	int b=(s2[0]-'0')*10+(s2[1]-'0');
	char a1=s1[2],b1=s2[2];
	if(a!=b) {cout<<"1000";return 0;}
	if(((a1=='A'||a1=='B'||a1=='C')&&(b1=='D'||b1=='F'))
		||((b1=='A'||b1=='B'||b1=='C')&&(a1=='D'||a1=='F'))){
		cout<<"1100";return 0;
	}
	if((a1=='D'&&b1=='F')||(a1=='F'&&b1=='D')){cout<<"1111";return 0;}
	if((a1=='A'&&b1=='B')||(b1=='A'&&a1=='B')
	||(a1=='B'&&b1=='C')||(a1=='C'&&b1=='B')){cout<<"1111";return 0;}
	cout<<"1110";return 0;
}
