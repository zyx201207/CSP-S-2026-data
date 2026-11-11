#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c,cc,s,ss;
	cin>>c>>s>>cc>>ss;
	if(c==cc) {
		cout<<1;
		if(s.substr(0,2)==ss.substr(0,2)) {
			cout<<1;
			if((s[2]<'D')==(ss[2]<'D')) {
				cout<<1;
				if((abs(s[2]-ss[2])==1)&&(min(s[2],ss[2])!='C')) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
}
