#include <bits/stdc++.h>
#define int long long
#define S "travel"
#define FI freopen(S".in","r",stdin);
#define FO freopen(S".out","w",stdout);
using namespace std;

const int N = 2e5+10;
string a,b,c,d;
signed main()
{
	FI;FO;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> c >> d;
	if (a == c)
	{
		cout << 1;
//		string s11 = b[0]+b[1];
//		string s22 = d[0]+d[1];
		if (b[0] == d[0] && b[1] == d[1])
		{
			cout << 1;
			char X = b[2];
			char Y = d[2];
			bool pdx=0,pdy=0;
			if (X == 'D' || X == 'E')  pdx=1;
			if (Y == 'D' || Y == 'E')  pdy=1;
			if (pdx==pdy)
			{
				cout << 1;
				if (abs(X-Y)==1) cout << 1;
				else cout << 0;
			}
			else
			{
				cout << "00";
			}
		}
		else cout << "000";
	}
	else cout << "0000";
	
	
	
	
	return 0;
}
