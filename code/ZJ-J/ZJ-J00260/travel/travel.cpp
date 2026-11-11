#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(string x,string y){
	if(x[2]<='C'&&y[2]<='C') return 1;
	if(x[2]>='D'&&y[2]>='D') return 1;
	return 0;
}
bool f(string x,string y){
	if(x[2]=='A'&&y[2]=='B') return 1;
	if(x[2]=='B'&&y[2]=='A') return 1;
	if(x[2]=='B'&&y[2]=='C') return 1;
	if(x[2]=='C'&&y[2]=='B') return 1;
	if(x[2]=='D'&&y[2]=='F') return 1;
	if(x[2]=='F'&&y[2]=='D') return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) cout<<1;
	else cout<<0;
	if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1]) cout<<1;
	else cout<<0;
	if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1]&&check(s2,s4)) cout<<1;
	else cout<<0;
	if(s1==s3&&s2[0]==s4[0]&&s2[1]==s4[1]&&check(s2,s4)&&f(s2,s4)) cout<<1;
	else cout<<0;
	return 0;
}
