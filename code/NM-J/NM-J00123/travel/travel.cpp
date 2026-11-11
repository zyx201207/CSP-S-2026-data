#include<bits/stdc++.h>
using namespace std;
int a1,b1;
string a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;

	if(a1==b1) cout<<1;
	else {
		cout<<0<<0<<0<<0;
		return 0;
	}

	if(a2[1]==b2[1]&&a2[0]==b2[0]) cout<<1;
	else {
		cout<<0<<0<<0;
		return 0;
	}

	if((a2[2]<='C'&&b2[2]<='C')||(a2[2]>'C'&&b2[2]>'C'))
		cout<<1;
	else {
		cout<<0<<0;
		return 0;
	}

	int r=int(a2[2]),x=int(b2[2]);
	if(abs(r-x)==1) cout<<1;
	else cout<<0;

	return 0;
}
