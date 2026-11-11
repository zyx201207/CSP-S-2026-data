#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
string a,b,c,d;
string ans="";
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>a>>b>>c>>d;
	if(a==c) ans+='1';
	else ans+='0';
	if(a==c&&b[0]==d[0]&&b[1]==d[1]) ans+='1';
	else ans+='0';
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&(b[2]<='C'&&d[2]<='C'||b[2]>'C'&&d[2]>'C')) ans+='1';
	else ans+='0';
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&(b[2]<='C'&&d[2]<='C'||b[2]>'C'&&d[2]>'C')){
		if(b>d) swap(b,d);
		if(b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='C'||b[2]=='D'&&d[2]=='F') ans+='1';
		else ans+='0';
	}
	else ans+='0';
	cout <<ans;
	return 0;
}
/*
Problem	Finish-time	Used-time	Used-time of reading problem	Used-time of debug	Expected-point	The solution		The level of difficulty
travel	8:42		12min		10min							0min				[0,100]			condition-struct	orange
string	8:50		8min		1min							0min				[0,100]			two-pointer			yellow
and		9:06		16min		1min							0min				[0,100]			always-select-best	yellow
card	9:59		53min		15min							10min				[0,100]			DP on DAG			green
Total 	9:59		1h29min		27min							10min				[0,400]								higher than CSP-J2025 and lower than CSP-J2024 

CSPS-2026 RP++
*/ 
