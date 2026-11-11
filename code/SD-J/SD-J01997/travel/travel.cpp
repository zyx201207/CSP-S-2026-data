#include <bits/stdc++.h>
using namespace std;
#define int long long
bool check1(string s1,string s2){
	if(s1[1]==s2[1]&&s1[2]==s2[2])return true;
	return false;
}
bool check2(string s1,string s2){
	char c1=s1[3],c2=s2[3];
	if(((c1=='A'||c1=='B'||c1=='C')&&(c2=='A'||c2=='B'||c2=='C')||(c1=='D'||c1=='E')&&(c2=='D'||c2=='E'))&&check1(s1,s2))return true;
	return false;
}
bool check3(string s1,string s2){
	char c1=s1[3],c2=s2[3];
	int x=abs(c1-c2);
	if(x==1&&check2(s1,s2))return true;
	return false;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	s1=" "+s1,s2=" "+s2;
	if(c1!=c2)cout<<"0000";
	else cout<<'1'<<check1(s1,s2)<<check2(s1,s2)<<check3(s1,s2);
	return 0;
}
