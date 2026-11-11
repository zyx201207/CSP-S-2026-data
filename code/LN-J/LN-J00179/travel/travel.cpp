//CSP-J2 2026 RP++!
#include<bits/stdc++.h>
#define int long long
using namespace std;
int c1,s1,c2,s2;char z1,z2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>z1>>c2>>s2>>z2;
	if(c1!=c2)
		return ((cout<<"0000\n"),0);
	else cout<<'1';
	if(s1!=s2)
		return ((cout<<"000\n"),0);
	else cout<<'1';
	if(z1<'D' and z2>'C' or z1>'C' and z2<'D')
		return ((cout<<"00\n"),0);
	else cout<<'1';
	if(z1>z2)swap(z1,z2);
	if(z1=='A' and z2=='B' or z1=='B' and z2=='C' or z1=='D' and z2=='F')
		cout<<'1';
	else cout<<'0';
	return 0;
}
