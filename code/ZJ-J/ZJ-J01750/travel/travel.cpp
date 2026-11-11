#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)cout<<1;
	else cout<<"0000",exit(0);
	string a="",b="";
	a+=s2[0],a+=s2[1];
	b+=s4[0],b+=s4[1];
	if(a==b)cout<<1;
	else cout<<"000",exit(0);
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		if(s4[2]=='D'||s4[2]=='F')cout<<"00",exit(0);
		else cout<<"1";
	}
	else if(s2[2]=='D'||s2[2]=='F'){
		if(s4[2]=='A'||s4[2]=='B'||s4[2]=='C')cout<<"00",exit(0);
		else cout<<"1";
	}
	if(s2[2]=='A'){
		if(s4[2]=='B')cout<<1;
		else cout<<0;
	}
	if(s2[2]=='B'){
		if(s4[2]=='C'||s4[2]=='A')cout<<1;
		else cout<<0;
	}
	if(s2[2]=='C'){
		if(s4[2]=='B')cout<<1;
		else cout<<0;
	}
	if(s2[2]=='D'){
		if(s4[2]=='F')cout<<1;
		else cout<<0;
	}
	if(s2[2]=='F'){
		if(s4[2]=='D')cout<<1;
		else cout<<0;
	}
	return  0;
}
/*
笑点解析:本题代码是4题当中最长的 
*/
