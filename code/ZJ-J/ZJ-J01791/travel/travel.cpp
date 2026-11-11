#include<bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define il inline

int f=1;
string a,b,c,d;
string s,t;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else cout<<0,f=0;
	s=b[0]+b[1],t=d[0]+d[1];
	if(f&&s==t) cout<<1;
	else cout<<0,f=0;
	if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
		if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
			if(f) cout<<1;
			else cout<<0;
		}
		else cout<<0,f=0;
	}else{
		if(d[2]=='D'||d[2]=='F'){
			if(f) cout<<1;
			else cout<<0;
		}
		else cout<<0,f=0;
	}if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
		if(d[2]==b[2]+1||d[2]==b[2]-1){
			if(f) cout<<1;
			else cout<<0;
		}
		else cout<<0,f=0;
	}else if(b[2]=='D'){
		if(d[2]=='F'){
			if(f) cout<<1;
			else cout<<0;
		}
		else cout<<0,f=0;
	}else{
		if(d[2]=='D'){
			if(f) cout<<1;
			else cout<<0;
		}
		else cout<<0,f=0;
	}
	return 0;
}/*
Code by RhMoGe
Luogu uid = 1634173
Last Dance.
AFO soon.

also enough
*/

