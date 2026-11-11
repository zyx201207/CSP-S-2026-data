#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string x1,x2,r1,r2;
	cin>>x1>>x2>>r1>>r2;
	if(x1==r1){
		cout<<1;
	}
	else cout<<0;
	if(x2[0]==r2[0]&&x2[1]==r2[1]&&x1==r1){
		cout<<1;
	}
	else cout<<0;
	if(x2[0]==r2[0]&&x2[1]==r2[1]){
		if((x2[2]=='A'&&r2[2]=='B')||(x2[2]=='A'&&r2[2]=='C')||(x2[2]=='B'&&r2[2]=='A')||(x2[2]=='B'&&r2[2]=='C')||(x2[2]=='C'&&r2[2]=='B')||(x2[2]=='C'&&r2[2]=='A')||(x2[2]=='E'&&r2[2]=='F')||(x2[2]=='F'&&r2[2]=='E')){
			cout<<1;
		}
		else cout<<0;
	}
	else cout<<0;
	if(x2[0]==r2[0]&&x2[1]==r2[1]){
		if((x2[2]=='A'&&r2[2]=='B')||(x2[2]=='B'&&r2[2]=='A')||(x2[2]=='B'&&r2[2]=='C')||(x2[2]=='C'&&r2[2]=='B')||(x2[2]=='E'&&r2[2]=='F')||(x2[2]=='F'&&r2[2]=='E')){
			cout<<1;
		}
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
