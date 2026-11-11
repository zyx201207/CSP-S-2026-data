#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define inf 0x3f3f3f3f
#define llinf 0x3f3f3f3f3f3f3f3f
#define to0(x) memset(x,0,sizeof x)
#define to_1(x) memset(x,-1,sizeof x)
#define toinf(x) memset(x,0x3f,sizeof x)
#define Debug cout<<"DEBUG\n";
#define Deon(x) cout<<"DEBUG:"<<x<<'\n';
#define pb(x) push_back(x)
#define CLOSE ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

string c1,c2,s1,s2;

int main() {
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);

	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) {cout<<"0000";return 0;}
	cout<<1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]) {
		cout<<1;
		if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C') {
			cout<<1;
			if(abs(s1[2]-s2[2])==1) {cout<<1;return 0;}
			else {cout<<0;return 0;}
		} else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F') {cout<<"11";return 0;}
		else {cout<<"00";return 0;}
	} else {cout<<"000";return 0;}

	return 0;
}
/*
02 01A 02 01B
*/
