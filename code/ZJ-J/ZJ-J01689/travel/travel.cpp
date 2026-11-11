#include<bits/stdc++.h>
//#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	bool w=(c1==c2);
	cout<<w;
	w&=(s1[0]==s2[0]&&s1[1]==s2[1]);
	cout<<w;
	w&=((s1[2]=='D'&&s2[2]=='F')||
		(s1[2]=='F'&&s1[2]=='D')||
		(s1[2]=='A'&&s2[2]=='B')||
		(s1[2]=='A'&&s2[2]=='C')||
		(s1[2]=='B'&&s2[2]=='A')||
		(s1[2]=='B'&&s2[2]=='C')||
		(s1[2]=='C'&&s2[2]=='A')||
		(s1[2]=='C'&&s2[2]=='B'));
	cout<<w;
	w&=((s1[2]=='D'&&s2[2]=='F')||
		(s1[2]=='F'&&s1[2]=='D')||
		(s1[2]=='A'&&s2[2]=='B')||
		(s1[2]=='B'&&s2[2]=='A')||
		(s1[2]=='B'&&s2[2]=='C')||
		(s1[2]=='C'&&s2[2]=='B'));
	cout<<w<<endl;
	return 0;
}
/*
ez
score 100 pts
time 11 min
difficulty 1
*/