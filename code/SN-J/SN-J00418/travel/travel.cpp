#include<bits/stdc++.h>
using namespace std;
string x,y,xx,yy;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>y>>xx>>yy;
	if(x==xx) {
		cout<<1;
		if(y[0]==yy[0]&& y[1]==yy[1]) {
			cout<<1;
			if(y[2]>='A' && y[2]<='C' && yy[2]>='A' && yy[2]<='C'){
				cout<<1;
				if(y[2]=='A' && yy[2]=='B'){
					cout<<1;
				}else if(y[2]=='B' && yy[2]=='C'){
					cout<<1;
				}else if(yy[2]=='A' && y[2]=='B'){
					cout<<1;
				}else if(yy[2]=='B' && yy[2]=='C'){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if((y[2]=='D' && yy[2]=='F') || (y[2]=='F' && yy[2]=='D')){
				cout<<1;
				cout<<1;
			}else{
				cout<<0;
				cout<<0;
			}
		} else {
			cout<<0;
			cout<<0;
			cout<<0;
		}
	} else {
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
}
