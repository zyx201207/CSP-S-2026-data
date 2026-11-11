#include <bits/stdc++.h>
using namespace std;
string c,cc,sx,sy;
int a=1,b=1,d=1,e=1,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>sx>>cc>>sy;
	x=sx[1]+sx[0];
	y=sy[1]+sy[0];
	if(sx[2]!=sy[2]+1||sx[2]!=sy[2]-1){
		e=0;
	}
	if((sx[2]=='C'&&sy[2]=='D')||(sx[2]=='D' && sy[2]=='C')){
		d=0;
		e=0;
	}
	if((x+1!=y&&x-1!=y)||(sx[0]==0&&sy[0]==1)||(sx[0]==1&&sy[0]==0)){
		e=0;
		b=0;
		d=0;
	}
	if(c!=cc){
		a=0;
		b=0;
		e=0;
		d=0;
	}
	cout<<a<<b<<d<<e;
	return 0;
}
