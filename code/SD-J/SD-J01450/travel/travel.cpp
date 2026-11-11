#include<bits/stdc++.h>
using namespace std;
string rr,xx;
struct node{
	int cx,ph,zw;
}r,x;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r.cx>>rr>>x.cx>>xx;
	r.ph=(rr[0]-'0')*10+(rr[1]-'0');
	x.ph=(xx[0]-'0')*10+(xx[1]-'0');
	r.zw=(int)(rr[2]-'A'+1);
	x.zw=(int)(xx[2]-'A'+1);
	if(rr[2]=='F')	r.zw--;
	if(xx[2]=='F')	x.zw--;
	if(r.cx==x.cx)	cout<<1;
	else cout<<0;
	if(r.cx==x.cx&&r.ph==x.ph)	cout<<1;
	else cout<<0;
	if(r.cx==x.cx&&r.ph==x.ph&&r.zw<4&&x.zw<4||r.cx==x.cx&&r.ph==x.ph&&r.zw>3&&x.zw>3){
		cout<<1;
	}
	else	cout<<0;
	if(r.cx==x.cx&&r.ph==x.ph&&r.zw<4&&x.zw<4&&abs(r.zw-x.zw)==1||r.cx==x.cx&&r.ph==x.ph&&r.zw>3&&x.zw>3&&abs(r.zw-x.zw)==1){
		cout<<1;
	}
	else	cout<<0;
	return 0;
}
