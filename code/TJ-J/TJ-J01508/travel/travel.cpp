#include<bits/stdc++.h>

using namespace std;

int aa,bb;
string as,bs;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>aa>>as>>bb>>bs;
	int ap=0,bp=0;
	ap=(ap+as[0])*10+as[1];
	bp=(bp+bs[0])*10+bs[1];
	char az=as[2],bz=bs[2];
	if(az>bz) swap(az,bz);
	if(aa==bb) cout<<1;
	else cout<<0;
	if(aa==bb && ap==bp) cout<<1;
	else cout<<0;
	if(aa==bb && ap==bp && ((az=='A'&&bz=='B')||(az=='B'&&bz=='C')||(az=='A'&&bz=='C')||(az=='D'&&bz=='F')) ) cout<<1;
	else cout<<0;
	if(aa==bb && ap==bp && ((az=='A'&&bz=='B')||(az=='B'&&bz=='C')||(az=='D'&&bz=='F')) ) cout<<1;
	else cout<<0;
	//100
	return 0;
}

