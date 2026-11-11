#include<bits/stdc++.h>
#define ll long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;
	if(c1==c2&&s1[1]==s2[1]) cout<<1;
	else cout<<0;
	if(c1==c2&&s1[1]==s2[1]&&('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C'||'D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F')) cout<<1;
	else cout<<0;
	if(c1==c2&&s1[1]==s2[1]&&abs(s1[2]-s2[2])==1&&(!(s1[2]=='C'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='C'))) cout<<1;
	else cout<<0;
	return 0;
} 
