#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	a=s1[0]-'0';
	a=a*10+s1[1]-'0';
	b=s2[0]-'0';
	b=b*10+s2[1]-'0';
	if(a!=b){
		cout<<"1000";
		return 0;
	}
	if(s1[2]>='A' && s1[2]<='C' && s2[2]>='D'){
		cout<<"1100";
		return 0;
	}
	if(s2[2]>='A' && s2[2]<='C' && s1[2]>='D'){
		cout<<"1100";
		return 0;
	}
	if(s1[2]>='E') cout<<"1111";
	else if(s1[2]=='B' || s2[2]=='B') cout<<"1111";
	else cout<<"1110";
	return 0;
}
