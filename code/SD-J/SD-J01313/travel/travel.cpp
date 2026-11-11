#include<bits/stdc++.h>
const int N=2e5+10,inf=0x3f3f3f3f;
typedef long long ll;

using namespace std;
void solve() {
	int x;
	string a;
	int y;
	string b;
	cin>>x>>a>>y>>b;
	if(x==y) {
		cout<<1;
		if(a[0]==b[0] && a[1]==b[1]) {
			cout<<1;
			if((a[2]>='D' && b[2]>='D') || (a[2]<='C' && b[2]<='C')){
				cout<<1;
				if(int(a[2])==int(b[2])+1||int(a[2])==int(b[2])-1) cout<<1;
				else cout<<"0";
			}else cout<<"00";
		}		
		else cout<<"000";
	} else cout<<"0000";
	return ;
}
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int _=1;
//	cin>>_;
	while(_--) solve();
	return 0;
}
