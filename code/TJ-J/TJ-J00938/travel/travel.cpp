#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,a1;
	cin>>a>>a1;
	string b,b1;
	cin>>b>>b1;
	if(a[1]==b[1]&&a[0]==b[0]) {
		cout<<1;
	} else {
		cout<<0;
	}
	if(a[2]==b[2]&&b[3]==a[3]) {
		cout<<1;
	} else {
		cout<<0;
	}
	if(a1[0]==b1[0]&&b1[1]==a1[1]||a1[2]==b1[2]-1||a1[2]==b1[2]+1||a1[2]=='C'&&b1[2]!='D'||a1[2]=='D'&&b1[2]!='C') {
		cout<<1;
	} else {
		cout<<0;
	}
	if(a1[2]==b1[2]+1||a1[2]==b1[2]-1||a1[2]=='C'&&b1[2]!='D'||a1[2]=='D'&&b1[2]!='C') {
		cout<<1;
	} else {
		cout<<0;
	}
	return 0;
}
