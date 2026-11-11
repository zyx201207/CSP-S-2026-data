#include<bits/stdc++.h>
#define rd(x) cin>>x
#define pt(x) cout<<x
#define rep(i,x,y) for(ll (i)=(x);(i)<=(y);++i)
#define down(i,x,y) for(ll (i)=(x);(i)>=(y);--i)
#define rp(i,p) for(auto i:p)
#define mx(x,y) x=max(x,y)
#define mn(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
const int N=1e5+10;
const int mod=1e9+7;
const int inf=1e9;
const ll linf=1e18;
bool K1,K2;
string str1,str2,str3,str4;
bool check(char x,char y){
	bool flag=(x=='D'||x=='F');
	if(flag&&(y=='D'||y=='F')) return true;
	if(!flag&&y!='D'&&y!='F') return true;
	return false;
}
bool check1(char x,char y){
//	pt(x),pt(' '),pt(y),pt('\n');
//	pt(abs(x-y)),pt('\n');
	if(x=='D'||x=='F') return true;
	if(abs(x-y)==1) return true;
	return false;
}
void work(){
	rd(str1),rd(str2),rd(str3),rd(str4);
	if(str1!=str3) return pt("0000"),void();
	if(!((str2[0]==str4[0]&&str2[1]==str4[1]))) return pt("1000"),void();
	if(!check(str2[2],str4[2])) return pt("1100"),void();
	if(!check1(str2[2],str4[2])) return pt("1110"),void();
	return pt("1111"),void();
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T;
	T=1;
//	rd(T);
	while(T--) work();
	return 0;
}
/*
02 01A 02 01B
*/
/*

*/
/*

*/