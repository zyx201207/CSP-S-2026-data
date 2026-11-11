#include<bits/stdc++.h>
using namespace std;
int ch(string a , string b)
{
	if(a[2]<='C' && b[2]<='C' && a[2]>='A' && b[2]>='A') return 1;
	if(a[2]<='F' && b[2]<='F' && a[2]>='D' && b[2]>='D') return 1;
	return 0;
}
int c(string a , string b)
{
	if(a[2]+1==b[2] || a[2]-1==b[2]) return 1;
	return 0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	int an,bn;
	cin>>an>>a>>bn>>b;
	if(an==bn) cout<<'1';
	else cout<<'0';
	if(an==bn && a[0]==b[0] && a[1]==b[1]) cout<<'1';
	else cout<<'0';
	if(an==bn && a[0]==b[0] && a[1]==b[1] && ch(a,b)) cout<<'1';
	else cout<<'0';
	if(an==bn && a[0]==b[0] && a[1]==b[1] && ch(a,b) && c(a,b)) cout<<'1';
	else cout<<'0';
	return 0;
}
