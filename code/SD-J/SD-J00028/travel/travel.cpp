#include <bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
void solve(){
	cin >> a >> b >> c >> d;
	if (a!=c) cout << "0000\n";
	else if (b.substr(0,2)!=d.substr(0,2)) cout << "1000\n";
	else if ((b[2]<='C'&&d[2]>='D')||(b[2]>='D'&&d[2]<='C')) cout << "1100\n";
	else if ((b[2]=='A'&&d[i]!='B')||(b[2]=='B'&&d[2]!='A'&&d[2]!='C')||(b[2]=='C'&&d[2]!='B')||(b[2]=='D'&&d[2]!='F')||(b[2]=='F'&&d[2]!='D')) cout << "1110\n";
	else cout << "1111\n";
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T=1;
//	cin >> T;
	while (T--){
		solve();
	}
	return 0;
}

