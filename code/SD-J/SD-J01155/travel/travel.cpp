#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[1]==c2[1]) cout<<"1";
	else {
		cout<<"0000";
		return 0;
	}
	if(s1[1]==s2[1]) cout<<"1";
	else {
		cout<<"000";
		return 0;
	} 
	if((s1[2]<='c'&&s2[2]<='c')||(s1[2]>'c'&&s2[2]>'c')) cout<<"1";
	else {
		cout<<"00";
		return 0;
	}
	int a=s1[2]-'0';
	int b=s2[2]-'0';
	if(a+1==b||a-1==b) cout<<"1";
	else cout<<"0";
	return 0;
} 
