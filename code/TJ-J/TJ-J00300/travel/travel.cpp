#include <bits/stdc++.h>
using namespace std;
#define int long long
string a,b,x,y;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> a >> b >> x >> y;
	if(a == x) cout << "1";
	else {
		cout << "0000" << "\n";
		return 0;
	}
	int c = b.size();
	if(b[c - 2] != y[c - 2] or b[c - 3] != y[c - 3]){
		cout << "000";
		return 0;
	} 
	else cout << "1";
	if((b[c - 1] == 'A' and y[c - 1] == 'B') or (b[c - 1] == 'B' and y[c - 1] == 'A') or (b[c - 1] == 'A' and y[c - 1] == 'C') or (b[c - 1] == 'C' and y[c - 1] == 'A') or (b[c - 1] == 'C' and y[c - 1] == 'B') or (b[c - 1] == 'B' and y[c - 1] == 'C') or (b[c - 1] == 'D' and y[c - 1] == 'E') or (b[c - 1] == 'E' and y[c - 1] == 'D')) cout << "1";
	else cout << "0";
	if((abs(b[c - 1] - y[c - 1]) == 1) and (b[c - 1] != 'C' or y[c - 1] != 'D')) cout << "1";
	else cout << "0";
	return 0;
}
