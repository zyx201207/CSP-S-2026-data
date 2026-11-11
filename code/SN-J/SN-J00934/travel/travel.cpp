#include <iostream>
#include <cstdio>
using namespace std;

string cr, sr, cx, sx;

bool pd(char l, char a, char r)
{
	if(l <= a && a <= r) return true;
	return false;
}

void solve()
{
	cin >> cr >> sr >> cx >> sx;
	if(cr != cx) cout << "0000";
	else
	{
		cout << 1;
		string pr = ""; pr += sr[0]; pr += sr[1];
		string px = ""; px += sx[0]; px += sx[1];
		if(pr != px) cout << "000";
		else
		{
			cout << 1;
			char lr = sr[2], lx = sx[2];
			if(!((pd('A', lr, 'C') && pd('A', lx, 'C')) 
			 || pd('E', lr, 'F') && pd('E', lx, 'F'))) cout << "00";
			else
			{
				cout << 1;
				int t = (int)(lr - lx);
				if(t == 1 || t == -1) cout << 1;
				else cout << 0;
			}
		}
	}
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	solve();
	return 0;
}

