#include<bits/stdc++.h>
using namespace std;
int c[3],n[3];
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c[1]>>s1>>c[2]>>s2;
	if(c[1]!=c[2]){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	n[1]=(s1[0]-'0')*10+(s1[1]-'0');
	n[2]=(s2[0]-'0')*10+(s2[1]-'0');
	if(n[1]!=n[2]){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
		cout<<"11";
	}else if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')){
		cout<<"11";
	}else if((s1[2]=='C'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')){
		cout<<"11";
	}else if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
		cout<<"10";
	}else{
		cout<<"00";
	}
	return 0;
}
