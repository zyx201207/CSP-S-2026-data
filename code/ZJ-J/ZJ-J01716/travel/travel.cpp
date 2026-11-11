#include<bits/stdc++.h>
using namespace std;
string xa,xb,ya,yb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>xa>>xb>>ya>>yb;
	if(xa==ya){
		cout<<1;
		if(xb[0]==yb[0]&&xb[1]==yb[1]){
			cout<<1;
			if(xb[2]<'D'&&yb[2]<'D'){
				cout<<1;
				if((xb[2]=='A'&&yb[2]=='B')||(xb[2]=='B'&&yb[2]=='C')){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if(xb[2]>='D'&&yb[2]>='D'){
				cout<<1<<1;
				return 0;
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}