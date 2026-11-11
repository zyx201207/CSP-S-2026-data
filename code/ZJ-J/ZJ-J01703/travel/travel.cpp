#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans="";
bool check(char a,char b){
	if(a>='A'&&a<='C'&&b>='A'&&b<='C') return 1;
	if((a=='D'||a=='F')&&(b=='D'||b=='F')) return 1;
	return 0;
}
bool iok(char a,char b){
	if(a>b){char t=b,b=a,a=t;}
	if((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F'))
		return 1;
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(!(c1==c2)){cout<<"0000\n";return 0;}
	if(!(s1[0]==s2[0]&&s1[1]==s2[1])){cout<<"1000\n";return 0;}
	if(!check(s1[2],s2[2])){cout<<"1100\n";return 0;}
	if(!iok(s1[2],s2[2])){cout<<"1110\n";return 0;}
	cout<<"1111\n";
	return 0;
}