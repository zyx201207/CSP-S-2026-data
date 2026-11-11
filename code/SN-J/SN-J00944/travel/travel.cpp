#include<bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
	freopen("travel.in","r".in)
	freoprn("travel.out","r",out)
    int C1;
	int C2;
	string S1;
	string S2;
	cin>>C1>>C2;
	cin>>S1>>S2;
	if(C1=C2) {
		cout<<"1";
	} else {
		cout<<"0";
	}
	if(S1[0]=S2[0]&&S1[1]==S2[1]) {
		cout<<"1";
	}
else {
	cout<<"0";
}
if(S1[2]<='C'&&S2[2]<='C'||S1[2]>='C'&&S2[2]>='C') {
	cout<<"1";
} else {
	cout<<"0";
}
if(S1[2]+"1"=S2[2]) {
	cout<<"1";
} else {
	cout<<"0";
}
return 0;
}
