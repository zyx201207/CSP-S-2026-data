#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a,b,c,d;
ll s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else cout<<0;
	if(b[0]==d[0]&&b[1]==d[1]&&a==c)cout<<1;
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]){
		if(b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'||b[2]=='A'&&d[2]=='B'||b[2]=='A'&&d[2]=='C'||b[2]=='B'&&d[2]=='A'||b[2]=='B'&&d[2]=='C'||b[2]=='C'&&d[2]=='A'||b[2]=='C'&&d[2]=='B')cout<<1;
		else cout<<0;
	}else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&abs(int(b[2])-int(d[2]))==1){
		if(b[2]=='C'&&d[2]=='D')cout<<0;
		else cout<<1;
	}else cout<<0;
	return 0;
}
