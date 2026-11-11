#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(!isdigit(c)) {if(c=='-') f=-f;c=getchar();}
	while(isdigit(c)) {sum=((sum<<3)+(sum<<1))+c-48;c=getchar();}
	return sum*f;
}
int c1,c2;
string s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) {cout<<"0000"; return 0;}
	cout<<"1";
	if(s1[0]!=s2[0] || s1[1]!=s2[1]) {cout<<"000"; return 0;}
	cout<<"1";
	if((s1[2]<='C' && s2[2]>='D') || (s1[2]>='D' && s2[2]<='C')) {cout<<"00"; return 0;}
	cout<<"1";
	if(s1[2]<='C' && abs(s1[2]-s2[2])!=1) {cout<<"0"; return 0;}
	if(s1[2]>='D' && s1[2]==s2[2]) {cout<<"0"; return 0;}
	cout<<"1";
	return 0;
}