#include<bits/stdc++.h>
using namespace std;
int n,m;
string s,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>s>>m>>d;
	if(n==m)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s[0]==d[0]&&s[1]==d[1])cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((s[2]=='D'&&d[2]=='F')||(s[2]=='F'&&d[2]=='D')||(s[2]!='F'&&s[2]!='D'&&d[2]!='F'&&d[2]!='D'))cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if((s[2]=='D'&&d[2]=='F')||(s[2]=='F'&&d[2]=='D')||s[2]=='B'||d[2]=='B')cout<<1;
	else cout<<0;
}
