#include<bits/stdc++.h>
using namespace std;
string rc,xc,rw,xw;
unsigned long long tcx,tp,tptc,xl;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rc>>rw>>xc>>xw;
	if(rc==xc)tcx=1;
	if(!tcx){
		cout<<"0000"<<endl;
		return 0;
	}
	string rsc,xsc;
	char rp,xp;
	rsc=char(rw[0])+char(rw[1]);
	xsc=char(xw[0])+char(xw[1]);
	rp=rw[2];xp=xw[2];
	if(rsc==xsc)tp=1;
	if(((rp>='A'&&rp<='C'&&xp>='A'&&xp<='C')||(rp>='D'&&rp<='F'&&xp>='D'&&xp<='F'))&&tp){
		tptc=1;
		if(abs(rp-xp)==1&&tp==1)xl=1;
	}
	cout<<tcx<<tp<<tptc<<xl;
	return 0;
}
