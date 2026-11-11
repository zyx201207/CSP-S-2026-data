#include<bits/stdc++.h>
using namespace std;

char a,b,ad,bd;
int ax,bx,aw,bw,aa,bb,cc;
void sss(){
	aa=a-'0';
	bb=b-'0';
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b;
	sss();
	ax=10*a+b;
	cin>>a>>b>>ad;
	sss();
	aw=10*a+b;
	cin>>a>>b;
	sss();
	bx=10*a+b;
	cin>>a>>b>>bd;
	sss();
	bw=10*a+b;
	if(ax!=bx) cout<<"0000";
	else if(aw!=bw) cout<<"1000";
	else if((ad<'D' && bd>'C') || (ad>'C') && (bd<'D')) cout<<"1100";
	else if((ad=='A' && bd=='C') || (ad=='C' && bd=='A')) cout<<"1110";
	else cout<<"1111";
	return 0;
}

