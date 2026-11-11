#include <bits/stdc++.h>
#define int long long
using namespace std;
string s,s1,c,c1;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s1>>c>>c1;
	if(s!=c)cout<<"0000";
	else {
		cout<<1;
		if(s1[0]==c1[0]&&s1[1]==c1[1]){
			cout<<1;
			if(s1[2]=='C'&&c1[2]=='D'||s1[2]=='D'&&c1[2]=='C')cout<<"00";
			else {
				cout<<1;
				if(c1[2]-s1[2]==1||s1[2]-c1[2]==1)cout<<1;
				else cout<<0;
			}
		}
		else cout<<"000";
	}
	return 0;
}