#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int bx1,st1,bx2,st2;
char cst1,cst2;
bool ss1,ss2;
string c1,s1,c2,s2;
void solve(){
	bx1=(c1[0]-'0')*10+c1[1]-'0';
	bx2=(c2[0]-'0')*10+c2[1]-'0';
	st1=(s1[0]-'0')*10+s1[1]-'0';
	st2=(s2[0]-'0')*10+s2[1]-'0';
	cst1=s1[2],cst2=s2[2];
	if(cst1<='C') ss1=1;
	else ss1=0;
	if(cst2<='C') ss2=1;
	else ss2=0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	solve();
	if(bx1==bx2) cout<<'1';
	else cout<<'0';
	if(bx1==bx2&&st1==st2) cout<<'1';
	else cout<<'0';
	if(bx1==bx2&&st1==st2&&ss1==ss2) cout<<'1';
	else cout<<'0';
	if(bx1==bx2&&st1==st2&&ss1==ss2&&(cst1-cst2)<=1) cout<<'1';
	else cout<<'0';
	return 0;
}
/*
fc travel1.ans travel1.out /n
fc travel2.ans travel2.out /n
fc travel3.ans travel3.out /n
fc travel4.ans travel4.out /n
fc travel5.ans travel5.out /n
FC: Cannot find difference.
finished. 
*/
