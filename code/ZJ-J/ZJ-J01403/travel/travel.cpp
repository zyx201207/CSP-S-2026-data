#include<bits/stdc++.h>
#define int long long
#define I_want_to_AK_csp return
using namespace std;

string c1,s1,c2,s2;
bool flag;

signed main() {
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>c1>>s1>>c2>>s2;

	if(c1==c2) {
		cout<<1;
		flag=1;
	} else {
		cout<<0;
	}

	string h1,h2;
	for(int i=0; i<s1.size()-1; i++) {
		h1+=s1[i];
	}
	for(int i=0; i<s2.size()-1; i++) {
		h2+=s2[i];
	}
	if(h1==h2 && flag) {
		cout<<1;
	} else {
		cout<<0;
		flag=0;
	}

	char x,y;
	x=s1[2];
	y=s2[2];
	if(x>y) {
		swap(x,y);
	}
	if(flag && x=='A' && y=='B' || x=='A' && y=='C' || x=='B' && y=='C' || x=='D' && y=='E') {
		cout<<1;
	} else {
		cout<<0;
		flag=0;
	}

	if(y-x==1 && x!='C' && y!='D' && flag) {
		cout<<1;
	} else {
		cout<<0;
	}

	I_want_to_AK_csp 0;
}
/*
02 01A 02 01B

02 01C 02 01A

02 01C 02 01D

02 02B 02 01A

02 01A 03 01A
*/
