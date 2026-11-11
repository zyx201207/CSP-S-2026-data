#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s1.substr(0,2)==s2.substr(0,2))cout<<1;
	else {
		cout<<"000";
		return 0;
	}
	if((s1[2]<='C'&&s2[2]<='C')||('D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F'))cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(min(s1[2],s2[2])=='A'&&max(s1[2],s2[2])=='B'
	|| min(s1[2],s2[2])=='B'&&max(s1[2],s2[2])=='C'
	|| min(s1[2],s2[2])=='D'&&max(s1[2],s2[2])=='F')cout<<1;
	else{
		cout<<"0";
		return 0;
	}
	return 0;
}
/*
code by Ace
*/
