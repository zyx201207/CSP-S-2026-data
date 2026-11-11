#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fst ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long

const int INF=0x3f3f3f3f3f3f3f3f;
const int N=1e6+10, M=2e6+10;

signed main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	fst
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	if(a!=c)
	{
		cout << "0000";
		return 0;
	}
	else
	{
		cout << 1;
	}
	if(b.substr(0, 2)!=d.substr(0, 2))
	{
		cout << "000";
		return 0; 
	}
	else 
	{
		cout << 1;
	}
	if((b[2]<='C' && d[2]<='C') || (b[2]>'C' && d[2]>'C'))
	{
		cout << 1;
	}
	else
	{
		cout << "00";
		return 0;
	}
	if((b[2]=='C' && d[2]=='A') || (b[2]=='A' && d[2]=='C'))
	{
		cout << "0";
	}
	else
	{
		cout << 1;
	}
	return 0;
}
