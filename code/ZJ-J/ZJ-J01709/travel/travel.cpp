#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) {
		cout<<"0000\n";
	}
	else if(s1[0]!=s2[0]||s1[1]!=s2[1]) {
		cout<<"1000\n";
	}
	else if((s1[2]<='C'&&s2[2]>'C')||(s1[2]>'C'&&s2[2]<='C')) {
		cout<<"1100\n";
	}
	else if((s1[2]<='C'&&abs(s1[2]-s2[2])==1)||s1[2]>'C') {
		cout<<"1111\n";
	}
	else {
		cout<<"1110\n";
	}
	return 0;
}