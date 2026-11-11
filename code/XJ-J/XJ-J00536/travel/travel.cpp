#include <bits/stdc++.h>
using namespace std;
int a,c;
string b,d;

int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	
	if(a!=c) {
		cout<<"0000"<<endl;
		return 0;
	}
	cout<<"1";
	int sum1,sum2;
	sum1=(b[0]-'0')*10+(b[1]-'0');
	sum2=(d[0]-'0')*10+(d[1]-'0');
	if(sum1!=sum2) {
		cout<<"000";
		return 0;
	}
	cout<<"1";
	if((b[2]<='C'&&d[2]<='C') || (b[2]>='D'&&d[2]>='D')) {
		cout<<"1";
		if(char(b[2]+1)==d[2] || char(b[2]-1)==d[2]) cout<<"1";
		else cout<<"0";
	}
	else {
		cout<<"00";
		return 0;
	}
	return 0;
}
// 02 02B 02 01A