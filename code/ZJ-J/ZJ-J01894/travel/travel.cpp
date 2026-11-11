#include<bits/stdc++.h>
#define AC signed
#define AK return 0
#define int long long
using namespace std;
const string fwbs="This cpp is written by @hjcz_huls.";
string a,b,c,d;
bool judge(char a,char b){
	if(a>'C'&&b>'C') return 1;
	if(a<'D'&&b<'D') return 1;
	return 0;
}
AC main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]) cout<<1;
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&judge(b[2],d[2])) cout<<1;
	else cout<<0;
	if(a==c&&b[0]==d[0]&&b[1]==d[1]&&judge(b[2],d[2])&&(abs(b[2]-d[2])==1||b[2]>'C')) cout<<1;
	else cout<<0;
	AK;
}