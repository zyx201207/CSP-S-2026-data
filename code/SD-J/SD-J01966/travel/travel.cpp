#include<bits/stdc++.h>
#define endl '/n'
using namespace std;
string c1,s1,c2,s2;

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if (c1==c2) cout<<1;
	else cout<<0000;
	if ((s1=="01A"&&s2=="01B")||(s1=="01B"&&s2=="01A")||(s1=="01B"&&s2=="01C")||(s1=="01C"&&s2=="01B")||(s1=="01E"&&s2=="01F")||(s1=="01F"&&s2=="01E")) cout<<111;
	if ((s1=="02A"&&s2=="02B")||(s1=="02B"&&s2=="02A")||(s1=="02B"&&s2=="02C")||(s1=="02C"&&s2=="02B")||(s1=="02E"&&s2=="02F")||(s1=="02F"&&s2=="02E")) cout<<111;
	else cout<<000;
	return 0;
}
/*
02 01A 02 01B

*/
