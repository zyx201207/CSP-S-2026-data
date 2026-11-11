#include<bits/stdc++.h>
using namespace std;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int a[105];
	for(int i=0; i<105; i++) {
		cin>>c1[i]>>s1[i]>>c2[i]>>s2[i];
	}
	if(c1==c2) {
		cout<<1;
	} else {
		cout<<0;
	}
	if(c1==c2&&s1[1]==s2[1]) {
		cout<<1;
	} else {
		cout<<0;
	}
	if(c1==c2&&s1[1]==s2[1]) {
		cout<<1;
	} else {
		cout<<0;
	}
	if(s1[2]+1==s2[2]) {
		cout<<0;
	} else {
		cout<<1;
	}
	return 0;
}
