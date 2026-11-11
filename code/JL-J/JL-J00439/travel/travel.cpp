#include<bits/stdc++.h>
using namespace std;
#define int long long 
int x[6],y[6],p,q,m;
char a,b;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x[1]>>x[2]>>a>>y[1]>>y[2]>>b;
	if(x[1]==y[1]) cout<<'1';
	else {
		cout<<"0000";
		return 0;
	}
	if(x[2]==y[2]) cout<<'1';
	else{
		cout<<"000";
		return 0;
	}
	if(a=='D'||a=='F') p=1;
	else p=2;
	if(b=='D'||b=='F') q=1;
	else q=2;
	if(p==q) cout<<'1';
	else {
		cout<<"00";
		return 0;
	}
	if(a=='A') p=1;
	if(a=='B') p=2;
	if(a=='C') p=3;
	if(a=='D') p=4;
	if(a=='F') p=5;
	if(b=='A') q=1;
	if(b=='B') q=2;
	if(b=='C') q=3;
	if(b=='D') q=4;
	if(b=='F') q=5;
	m=max(p-q,q-p);
	if(m==1) cout<<'1';
	else cout<<'0';
	return 0;
}
