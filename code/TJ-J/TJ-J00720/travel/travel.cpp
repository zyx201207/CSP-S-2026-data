#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define int long long 
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string x,y;
	string a,b;
	cin>>x>>a>>y>>b;
	string ans="0000";
	if(x==y)ans[0]='1';
	else {
		cout<<ans<<endl;
		return 0;
	}
	if(a[0]==b[0]&&a[1]==b[1])ans[1]='1';
	else{
		cout<<ans<<endl;
		return 0;
	}
	if((a[2]<'D'&&b[2]<'D')||(a[2]>'C'&&b[2]>'C'))ans[2]='1';
	else {
		cout<<ans<<endl;
		return 0;
	}
	if((a[2]=='D'&&b[2]=='F')||(a[2]=='F'&&b[2]=='D')||
	   (a[2]=='A'&&b[2]=='B')||(a[2]=='B'&&b[2]=='A')||
	   (a[2]=='C'&&b[2]=='B')||(a[2]=='B'&&b[2]=='C'))ans[3]='1';
	else {
		cout<<ans<<endl;
		return 0;
	}
	cout<<ans<<endl;
	return 0;
} 
