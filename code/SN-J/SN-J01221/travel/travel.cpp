#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int xa=0,ya=0,za=0,oa=0;
bool x(string a,string b){
	if(a==b) return true;
	return false;
}
bool y(string a,string b){
	if(a[0]==b[0]&&a[1]==b[1]) return true;
	return false;
}
bool z(string a,string b){
	int ai=0,bi=0;
	if(a[2]=='A'||a[2]=='B'||a[2]=='C') ai=1;
	if(b[2]=='A'||b[2]=='B'||b[2]=='C') bi=1;
	if(a[1]==b[1]&&ai==bi) return true;
	return false;
}
bool O(string a,string b){
	int ai=0,bi=0;
	int p=fabs(a[2]-b[2]);
	if(a[2]=='A'||a[2]=='B'||a[2]=='C') ai=1;
	if(b[2]=='A'||b[2]=='B'||b[2]=='C') bi=1;
	if(ai==1&&bi==1&&p==1) return true;
	if(ai==0&&bi==0&&p==2) return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(x(c1,c2)) xa=1;
	if(x(c1,c2)&&y(s1,s2)) ya=1;
	if(x(c1,c2)&&y(s1,s2)&&z(s1,s2)) za=1;
	if(x(c1,c2)&&y(s1,s2)&&O(s1,s2)) oa=1;
	cout<<xa<<ya<<za<<oa;
	return 0;
}
