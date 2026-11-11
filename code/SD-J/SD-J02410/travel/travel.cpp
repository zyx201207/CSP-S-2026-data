#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,s1,c2,s2;
int a,b;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	s1=" "+s1;
	s2=" "+s2;
	cin>>a>>s1>>b>>s2;
	if(a==b){
		cout<<"1";
	}
	if(s1[1]==s2[1]&&s1[2]==s2[2]){
		cout<<"1";
	}
	if(s1[3]>='A'&&s1[3]<='C'&&s2[3]>='A'&&s2[3]<='C'){
			cout<<"1";
	}
	if(s1[3]<='A'||s1[3]>='C'&&s2[3]<='A'||s2[3]>='C'){
		cout<<"0";
	}
	if(s1[3]>='D'&&s1[3]<='F'&&s2[3]<='D'&&s2[3]>='F'){
	cout<<"11";
	}
	else cout<<"00";
	//else cout<<"0000";
	return 0;
}  
