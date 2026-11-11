#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + (ch - '0');
		ch = getchar();
	}
	return x * f;
}
int a, b;
string c1, c2, c3, c4;
signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> c1 >> c2 >> c3 >> c4;
	if(c1 == c3){
		cout << 1;
		if(c2[0] == c4[0] && c2[1] == c4[1]){
			cout << 1;
			if(c2[2] <= 'C' && c2[2] >= 'A') a = 1;
			if(c4[2] <= 'C' && c4[2] >= 'A') b = 1;
			if(a == b){
				cout << 1;
				if(c2[2] + 1 == c4[2] || c4[2] + 1 == c2[2])
					cout << 1;
				else cout << 0;
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
//退役快乐