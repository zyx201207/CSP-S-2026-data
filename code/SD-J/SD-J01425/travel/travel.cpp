#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string q,w;
	char e,r;
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	q=b[0]+b[1];
	w=d[0]+d[1];
	e=b[2];
	r=d[2];
	if(a==c)
	cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(q==w)
	cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(((e=='A'||e=='B'||e=='C')&&(r=='A'||r=='B'||r=='C'))||((e=='D'||e=='F')&&(r=='D'||r=='F'))){
		cout<<1;
	}
	else{
		cout<<0<<0;
		return 0;
	}
	if((int)e==(int)r+1||(int)r==(int)e+1)
	cout<<1;
	else
	cout<<0;
	return 0;
}
