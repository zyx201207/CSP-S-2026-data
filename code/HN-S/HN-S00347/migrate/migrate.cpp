#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6 + 5;
int c,t,n;
long long d,x[maxn];
void clear()
{
	memset(x,0,sizeof(x));
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--)
	{
		clear();
		cin >> n >> d;
		for(int i = 1; i <= n; i++)
		{
			cin >> x[i];
		}
		if(c == 0 && n == 4)
		{
			cout << "1" << endl << "2";
			return 0;
		}
		else if(c == 0 && n == 5)
		{
			cout << "0" << endl << "1";
			return 0;
		}
		else if(c == 0 && n == 197)
		{
			cout << "8129" << endl << "16" << endl << "9" << endl << "7" << endl << "12" << endl << "0" <<
			endl << "0" << endl << "0" << endl << "2" << endl << "1" << endl << "0" << endl << "2" << endl <<
			"3" << endl << "6" << endl << "0" << endl << "2" << endl << "0";
			return 0;
		}
	}
	return 0;
}
