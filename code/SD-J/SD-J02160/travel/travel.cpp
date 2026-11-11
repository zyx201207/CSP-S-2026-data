#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
string c1,s1,c2,s2;
string ans;
signed main(){
	fast;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2) ans+='1';
	else ans+='0';
	string st1=s1.substr(0,2);
	string st2=s2.substr(0,2);
	if (st1==st2 && ans[0]=='1') ans+='1';
	else ans+='0';
	if (ans=="11"){
		bool bl=1;
		if ((s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')) bl=0;
		if ((s1[2]=='A' && s2[2]=='B') || (s1[2]=='B' && s2[2]=='A')) bl=0;
		if ((s1[2]=='A' && s2[2]=='C') || (s1[2]=='C' && s2[2]=='A')) bl=0;
		if ((s1[2]=='B' && s2[2]=='C') || (s1[2]=='C' && s2[2]=='B')) bl=0;
		if (bl==0) ans+='1';
		else ans+='0';
	}
	else ans+='0';
	if (ans=="111"){
		bool bl=0;
		if (s1[2]=='D'&&s2[2]=='F') bl=1;
		if (s1[2]=='F'&&s2[2]=='D') bl=1;
		if (s1[2]=='A'&&s2[2]=='B') bl=1;
		if (s1[2]=='B'&&s2[2]=='A') bl=1;
		if (s1[2]=='B'&&s2[2]=='C') bl=1;
		if (s1[2]=='C'&&s2[2]=='B') bl=1;
		if (bl==1) ans+='1';
		else ans+='0';
	}
	else ans+='0';
	cout<<ans;
	return 0;
} 
