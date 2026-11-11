#include <iostream>
#include <string>
using namespace std;
int abs(int n);
int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string ci, si, cj, sj;
	cin >> ci >> si >> cj >> sj;
	if(ci == cj and ci != "01" and ci != "16")
	{
		cout << '1';
		string linei;
		linei += si[0];
		linei += si[1];
		string linej;
		linej += sj[0];
		linej += sj[1];
		if(linei == linej)
		{
			cout << '1';
			if((si[2] - 'A' < 3 and sj[2] - 'A' < 3) or (si[2] - 'A' >= 3 and sj[2] - 'A' >= 3))
			{
				cout << '1';
				if(abs(si[2] - sj[2]) == 1)cout << '1';
				else if((si[2] == 'D' and sj[2] == 'F') or (si[2] == 'F' and sj[2] == 'D'))cout << '1';
				else cout << '0';
			}
			else cout << "00";
		}
		else cout << "000";
	}
	else cout << "0000";
	return 0;
}
int abs(int n)
{
	if(n >= 0)return n;
	else return -n;
}
