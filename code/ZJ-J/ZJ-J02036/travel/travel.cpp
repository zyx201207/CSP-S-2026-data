#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int x,xx,y,yy,p,q;
bool f=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	x=(a[0]-'0')*10+(a[1]-'0');
	xx=(b[0]-'0')*10+(b[1]-'0');
	y=(c[0]-'0')*10+(c[1]-'0');
	yy=(d[0]-'0')*10+(d[1]-'0');
	p=(b[2]-'A')+1;
	q=(d[2]-'A')+1;
	if(x==y) cout<<1;
	else{
		cout<<0;
		f=1;
	}
	if(f||xx!=yy){
		cout<<0;
		f=1;
	}
	else cout<<1;
	if(f) cout<<0;
	else if((p>=4&&q>=4)||(p<=3&&q<=3)) cout<<1;
	else{
		cout<<0;
		f=1;
	}
	if(f) cout<<0;
	else if(abs(p-q)==1) cout<<1;
	else cout<<0;
	return 0;
}
