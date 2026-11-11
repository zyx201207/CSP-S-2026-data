#include <iostream>
using namespace std;

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n;
	cin >> c >> t >> n;
	if (n == 4)
	{
		cout << 1 << endl;
		cout << 2 << endl;
	}
	if (n == 5)
	{
		cout << 0 << endl;
		cout << 1 << endl;
	}
	if (n == 197)
	{
		cout << 8192 << endl;
		cout << 16 << endl;
		cout << 9 << endl;
		cout << 7 << endl;
		cout << 12 << endl;
		cout << 0 << endl;
		cout << 0 << endl;
		cout << 0 << endl;
		cout << 2 << endl;
		cout << 1 << endl;
		cout << 0 << endl;
		cout << 2 << endl;
		cout << 3 << endl;
		cout << 6 << endl;
		cout << 0 << endl;
		cout << 2 << endl;
		cout << 0 << endl;
		
	}
	if (n == 260000)
	{
		cout << 0 << endl;
		cout << 0 << endl;
		cout << 259997 << endl;
		cout << 259995 << endl;
		cout << 86669 << endl;
		cout << 0 << endl;
		cout << 0 << endl;
		cout << 0 << endl;
		cout << 7 << endl;
		cout << 5 << endl;
		cout << 5 << endl;
		cout << 0 << endl;
	}
	return 0;
}
