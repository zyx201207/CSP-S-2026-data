#include<bits/stdc++.h>
using namespace std;
int a,b;
string aa,bb;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>aa>>b>>bb;
	if(a!=b) {
		cout<<"0000";
	}
	else if(aa[0]==bb[0] && aa[1]==bb[1]) {
		if((aa[2]<'D' && bb[2]<'D') || (aa[2]>'C' && bb[2]>'C')) {
			if(abs(aa[2]-bb[2])==1) cout<<"1111";
			else cout<<"1110";
		}
		else {
			cout<<"1100";
		}
	}
	else {
		cout<<"1000";
	}
	return 0;
} 
