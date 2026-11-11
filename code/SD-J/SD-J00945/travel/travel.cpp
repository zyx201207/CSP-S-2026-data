#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
string x,y,s1,s2;
signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>s1>>y>>s2;
	if (x!=y) {
		cout<<"0000"<<endl;
		return 0;
	}
	cout<<1;
	if (s1[0]!=s2[0]||s1[1]!=s2[1]) {
		cout<<"000"<<endl;
		return 0;
	}
	cout<<1;
	if (s1[2]>s2[2]) {
		swap(s1,s2);
	}
	if (!((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F'))) {
		cout<<"00"<<endl;
		return 0;
	}
	cout<<1;
	if (!((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F'))) {
		cout<<"0"<<endl;
		return 0;
	}
	cout<<1<<endl;
	return 0;
}
