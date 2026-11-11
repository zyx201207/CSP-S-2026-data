#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	//
	int a1=(c1[0]-'0')*10+c1[1]-'0';
	int b1=(s1[0]-'0')*10+s1[1]-'0';
	int d1=s1[2]-'A'+1;
	int a2=(c2[0]-'0')*10+c2[1]-'0';
	int b2=(s2[0]-'0')*10+s2[1]-'0';
	int d2=s2[2]-'A'+1;
	//
	if(a1==a2) {
		cout<<1;
		if(b1==b2) {
			cout<<1;
			if((d1<=3&&d2<=3)||(d1>3&&d2>3)) {
				cout<<1;
				if((d1<=3&&d2<=3&&abs(d1-d2)==1)||(d1>3&&d2>3))cout<<1;
				else cout<<0;
			} else cout<<0<<0;
		} else cout<<0<<0<<0;
	} else cout<<0<<0<<0<<0;
	//
	return 0;
}