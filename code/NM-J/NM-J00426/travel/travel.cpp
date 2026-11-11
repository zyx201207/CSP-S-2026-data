#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	map<char,string> m;
	m['A']="BC";
	m['B']="AC";
	m['C']="AB";
	m['D']="F";
	m['F']="D";
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	string a="";
	if(c1!=c2) {cout<<"0000";return 0;}
	else a+="1";
	if(s1[0]!=s2[0]||s1[1]!=s2[1]){cout<<"1000";return 0;}
	else a+="1";
	int d=(s1[2]-'A')/3,k=(s2[2]-'A')/3;
	if(d==k){
		a+="1";
	}
	else {cout<<"1100";return 0;}
	char s=s1[2],y=s2[2];
	if(y>s){
		if(y-s==1)a+="1";
		else a+="0";
	}
	else{
		if(s-y==1)a+="1";
		else a+="0";
	}
	cout<<a;
	return 0;
}
