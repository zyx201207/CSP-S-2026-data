#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int Xn,Yn;
	string Xs,Ys;
	cin>>Xn>>Xs>>Yn>>Ys;
	bool a=0,b=0,c=0,d=0;
	if(Xn==Yn)a=1;
	int x=(Xs[0]-'0')*10+Xs[1];
	int y=(Ys[0]-'0')*10+Ys[1];
	if(x==y&&a)b=1;
	if(((Xs[2]<'D'&&Ys[2]<'D')||(Xs[2]>'C'&&Ys[2]>'C'))&&b)c=1;
	if(((abs(Xs[2]-Ys[2])==1)||(Xs[2]>'C'&&Ys[2]>'C'))&&c)d=1;
	cout<<a<<b<<c<<d;
	return 0;
}
