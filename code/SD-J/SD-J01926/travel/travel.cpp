#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("travel.in" , "r" , stdin);
	freopen("travel.out" , "w" , stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	string a , b , c , d;
	cin >> a >> b >> c >> d;
	if(a != c){
		cout << "0000";
		return 0;
	}
	else
		cout << 1;
	cout << (b[0] == d[0] && b[1] == d[1]);
	int aa = (b[0] == d[0] && b[1] == d[1]);
	int bb = (b[2] >= 'A' && b[2] <= 'C' && d[2] >= 'A' && d[2] <= 'C') || (b[2] >= 'D' && b[2] <= 'F' && d[2] >= 'D' && d[2] <= 'F');
	cout << (aa && bb);
	int x = (b[2] >= 'A' && b[2] <= 'C' && d[2] >= 'A' && d[2] <= 'C') || (b[2] >= 'D' && b[2] <= 'F' && d[2] >= 'D' && d[2] <= 'F');
	int y = (b[0] == d[0] && b[1] == d[1]);
	if(b[2] =='A' && d[2] == 'B')
		cout << (x && y);
	else if(b[2] == 'B'  && d[2] == 'A')
		cout << (x && y);
	else if(b[2] == 'B' && d[2] == 'C')
		cout << (x && y);
	else if(b[2] == 'C' && d[2] == 'B')
		cout << (x && y);
	else if(b[2] == 'D' && d[2] == 'F')
		cout << (x && y);
	else if(b[2] == 'F' && d[2] == 'D')
		cout << (x && y);
	else 
		cout << 0;
	
	return 0;
}
