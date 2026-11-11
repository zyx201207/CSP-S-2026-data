#include <bits/stdc++.h>
using namespace std;
int a,b;
string c,d;
bool xl,yp,yc,ylc;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a==b){
		cout<<1;
		ylc=1;
	}else{
		cout<<0;
		ylc=0;
	}
	if(ylc==1 && c[0]==d[0] && c[1]==d[1]){
			cout<<1;
			yp=1;
		}else{
			cout<<0;
			yp=0;
		}
	if(c[2]<='C' && d[2]<='C' && yp==1 && c[2]!=d[2]){
		cout<<1;
		yc=1;
	}else if(c[2]=='D' && d[2]=='F' && yp==1){
		cout<<1;
		xl=1;
		yc=1;
	}else if(c[2]=='F' && d[2]=='D' && yp==1){
		cout<<1;
		xl=1;
		yc=1;
	}else{
		cout<<0;
		yc=0;
		xl=0;
	}
	
	if(xl==1){
		cout<<1;
	}else{
		if(yc==1 && c[2]-1==d[2]|| yc==1&&c[2]+1==d[2]){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}
