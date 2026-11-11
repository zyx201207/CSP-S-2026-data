#include<bits/stdc++.h>
using namespace std;
string c,s,C,S;
int a[114514];
int b[114514];
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>C>>S;
	if(c==C) {
		cout<<"1";
	} else {
		cout<<"0000";
		return 0;
	}
	for(int i=0; i<=2; i++) {
		a[i]=s[i];
	}
	for(int i=0; i<=3; i++) {
		b[i]=S[i];
	}
	for(int i=0; i<=1; i++) {
		if(a[i]!=b[i]) {
			cout<<"000";
			return 0;
	    }
	}
	cout<<"1";
	if((a[2]<=67&&b[2]<=67)||(a[2]>=68&&b[2]>=68)) {
		cout<<"1";
	} else {
		cout<<"00";
		return 0;
	}
	if((a[2]-1==b[2])||(a[2]+1==b[2])) {
		cout<<"1";
		return 0;
	} else {
		cout<<"0";
		return 0;
	}
	return 0;
}
