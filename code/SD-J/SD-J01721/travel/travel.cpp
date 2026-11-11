#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,c,d;
char e,f;
bool check(){
	if(e=='C'&&f=='D')return 0;
	if(e=='D'&&f=='C')return 0;
	if(abs(e-f)==1)return 1;
	return 0;
}signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>a>>b>>e>>c>>d>>f;
	cout<<(a==c)<<(a==c&&b==d);
	cout<<(a==c&&b==d&&(e<'D'&&f<'D'||e>'C'&&f>'C'));
	cout<<(a==c&&b==d&&check());
}

