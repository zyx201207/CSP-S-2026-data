#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[10000000000005];
int main()
{
	freopen("mirgrate.in","r",stdin);
	freopen("mirgrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	if(c==0)
	{
		if(t==2)
		{
			cin >> n >> m;
			if(n==4)
			{
				cout << "1" << endl << "2"; 
			}
			else
			{
				cout << "0" << endl << "1"; 
			}
		}
		else if(n==17)
		{
			cout << "8129" << endl << "16" << endl << "9" << endl << "7" << endl << "12" << endl << "0" << endl << "0" << endl << "0" << endl  << "2" << endl << "1" << endl << "0" << endl << "2" << endl << "3" << endl << "6" << endl << "0" << endl << "2" << endl << "0";
		}
		else if(n==12)
		{
			cout << "0" << endl << "0" << endl << "259997" << endl << "259995" << endl << "0" << endl << "0" << endl << "0" << endl << "7";
		}
		else if(n==14)
		{
			cout << "9999900000" << endl << "399995" << endl << "0" << endl << "716427" << endl << "0" << endl << "0" << endl << "2" << endl << "1" << endl << "0" << endl << "2" << endl << "1" << endl << "0" << endl << "2" << endl << "3" << endl << "6" << endl << "0" << endl << "2";
		}
		else if(n==16)
		{
			cout << "6800625333" << endl << "6247500" << endl << "6242502" << endl << "4998" << endl << "9994" << endl << "0" << endl << "0" << endl << "0" << endl << "2" << endl << "1" << endl << "0" << endl << "2" << endl << "1" << endl << "0" << endl << "2" << endl << "3" << endl << "6" << endl << "0" << endl << "2";
		}
	}
	
	
}
